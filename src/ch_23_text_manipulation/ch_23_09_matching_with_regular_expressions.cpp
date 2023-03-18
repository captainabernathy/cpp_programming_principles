#include <iostream>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

inline void error(const string& msg)
{
    cerr << msg << endl;
    throw runtime_error(msg);
}

inline void error(string s1, string s2)
{
    error(s1 + s2);
}

inline void error(string s1, int n)
{
    ostringstream oss;
    oss << n;
    error(s1, oss.str());
}

// class for reporting string cast errors
struct bad_from_string : std::bad_cast {

    const char *what() const throw() {
        return "bad cast from string";
    }
};

template<typename T>
T from_string(const string& s)
{
    istringstream iss(s);
    T t;
    if (!(iss >> t))
        throw bad_from_string();
    return t;
}

int main()
{
    try
    {
        ifstream ifs("table.txt");
        if (!ifs)
            error("could not open table.txt");

        regex header {"^[\\w ]+(\\s.*[\\w\\s]+)*$"};

        string line;
        if (getline(ifs, line)) // check header
        {
            smatch matches;
            if (!regex_search(line, matches, header))
                error("no header");
        }

        regex row {"^[\\w ]+(\t\\d+)(\t\\d+)(\t\\d+)$"};
        int lineno = 0;
        int boys = 0;
        int girls = 0;
        int curr_boy = 0;
        int curr_girl = 0;

        while (getline(ifs, line))
        {
            lineno++;
            smatch matches;
            if (!regex_search(line, matches, row))
                error("bad line", lineno);

            curr_boy = from_string<int>(matches[1]);
            cout << "curr_boy: " << curr_boy << "\t";
            curr_girl = from_string<int>(matches[2]);
            cout << "curr_girl: " << curr_girl << "\t";
            int curr_total = from_string<int>(matches[3]);
            if (curr_boy + curr_girl != curr_total)
                error("bad row sum");

            boys += curr_boy;
            girls += curr_girl;
            cout << "boys: " << boys << "\tgirls: " << girls << endl;
        }

        if (2 * curr_boy != boys)
            error("boys don't add up");
        if (2 * curr_girl != girls)
            error("girls don't add up");
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exeption" << endl;
        return 2;
    }

    return 0;
}
