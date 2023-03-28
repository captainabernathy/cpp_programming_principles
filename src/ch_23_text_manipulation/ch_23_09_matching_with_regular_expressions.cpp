// program demonstrates how to use C++'s regex library to process complicated
// patterns typical of what one would find in a table

#include <iostream> // I/O library header
#include <fstream> // file stream library header
#include <regex> // regex library header
#include <stdexcept> // exception library header
#include <sstream> // string stream library header
#include <string> // string library header

using namespace std;

// outputs the string passed to msg to stderr and throws a runtime_error()
// with msg as its argument
inline void error(string const& msg)
{
    cerr << msg << endl;
    throw runtime_error(msg);
}

// concatenates both of the strings into a an error message that forms the
// message of a runtime_error()
inline void error(string s1, string s2)
{
    error(s1 + s2);
}

// function that reads integer passed to n into a string and forms an error
// message that concatenates the string passed to s1 with n, which subsequently
// forms the message of a runtime_error()
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

// template function that attempts to read an object of the type specified from
// the string passed to s.
// NOTE: if s cannot be read as a type T, then the function throws a
// bad_from_string() exception
template<typename T>
T from_string(string const& s)
{
    istringstream is(s); // initialize input string stream with s
    T t; // target type
    if (!(is >> t)) // read t from stream
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

        // match
        // the beginning of the line
        // followed by one or more of either a word character or a space
        // followed by zero or more of...
        //      a space followed by zero or more characters
        //      followed by one or more of either a word character or a space
        // followed by the end of the line
        regex header {"^[\\w ]+(\\s.*[\\w\\s]+)*$"};

        string line;
        if (getline(ifs, line)) // check header
        {
            smatch matches;
            if (!regex_search(line, matches, header))
                error("no header");
        }

        // match
        // the beginning of the line
        // followed by one or more of either a word character or a space
        // followed by a tab and one or more numbers
        // followed by a tab and one or more numbers
        // followed by a tab and one or more numbers
        // followed by the end of the line
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

            curr_boy = from_string<int>(matches[1]); // first capture
            cout << "curr_boy: " << curr_boy << "\t";

            curr_girl = from_string<int>(matches[2]); // second capture
            cout << "curr_girl: " << curr_girl << "\t";

            int curr_total = from_string<int>(matches[3]); // third capture
            if (curr_boy + curr_girl != curr_total)
                error("bad row sum");

            // update totals
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
