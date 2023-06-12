// program demonstrates how to use C++'s regex library to process complicated
// patterns typical of what one would find in a table
//
// program also uses the function template from_string<>() that converts a
// string into an object of a user specified type
//
// template<typename T>
// T from_string(string s)

#include <iostream> // for cerr, cout
#include <fstream> // for ifstream
#include <regex> // for regex, smatch, regex_search
#include <exception> // for exception
#include <string> // for string, getline()
#include <io_utils/io_utils.hpp> // for from_string<>()
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::ifstream;
        using std::regex;
        using std::smatch;
        using std::cout;
        using std::regex_search;
        using std::string;

        ifstream ifs {"table.txt"};
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
            cout << "boys: " << boys << "\tgirls: " << girls << '\n';
        }

        if (2 * curr_boy != boys)
            error("boys don't add up");
        if (2 * curr_girl != girls)
            error("girls don't add up");
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exeption\n";
        return 2;
    }

    return 0;
}
