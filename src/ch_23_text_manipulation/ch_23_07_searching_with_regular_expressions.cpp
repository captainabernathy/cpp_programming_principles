// program demonstrates how to use C++'s regex library to search for patterns
// within strings

#include <regex> // regular expression library header
#include <iostream> // I/O library header
#include <stdexcept> // exception library header
#include <string> // string library header
#include <fstream> // file stream library header

using std::ifstream;
using std::regex;
using std::string;
using std::smatch;
using std::regex_search;
using std::exception;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    try
    {
        ifstream ifs("file.txt"); // initialize ifs to file
        if (!ifs)
        {
            cerr << "could not open file.txt" << endl;
            exit(EXIT_FAILURE);
        }

        // 2 letters followed by 0 or more spaces follwed by 5 digits optionally
        // followed by a dash and 4 digits
        // NOTE: (expr)? means optionally, so (-\\d{4})? means optionally
        // accept 4 digits preceded by a dash
        regex pat{"\\w{2}\\s*\\d{5}(-\\d{4})?"};

        int lineno = 0;
        string line;
        // read from file
        while (getline(ifs, line))
        {
            ++lineno;
            smatch matches; // matched strings go here
            if (regex_search(line, matches, pat))
            {
                cout << lineno << ": " << matches[0] << endl;
                if (1 < matches.size() && matches[1].matched)
                    cout << "\t: " << matches[1] << endl; // sub-match
            }
        }
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }

    return 0;
}