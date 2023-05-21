// program demonstates the limitations of using the string class to process
// more complicated operations on strings (such as searching)

#include <iostream> // for cout, cerr
#include <fstream> // for ifstream
#include <string> // for string , getline()
#include <cstdlib> // for exit(), EXIT_FAILURE

int main()
{
    using std::ifstream;
    using std::cerr;
    using std::string;
    using std::cout;

    ifstream ifs {"chapter.23.5.in"}; // initialize ifs to file
    if (!ifs)
    {
        cerr << "failed to open chapter.23.5.in" << '\n';
        exit(EXIT_FAILURE);
    }

    string s;
    while (getline(ifs, s))
    {
        // NOTE: misses every postal code not separated from its context by
        // whitespace
        // misses every postal code with a space betwen the letters and the
        // digits
        // accepts every postal colde that begins with lower case letters
        // isn't flexible enough to look for postal codes in another format
        if (s.size() == 7
            && isalpha(s[0]) && isalpha(s[1])
            && isdigit(s[2]) && isdigit(s[3]) && isdigit(s[4])
            && isdigit(s[5]) && isdigit(s[6]))
            cout << "found " << s << '\n';
    }

    return 0;
}
