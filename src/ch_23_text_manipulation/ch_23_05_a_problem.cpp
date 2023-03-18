#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream ifs("chapter.23.5.in");
    if (!ifs)
    {
        cerr << "failed to open chapter.23.5.in" << endl;
        exit(EXIT_FAILURE);
    }

    string s;
    while (getline(ifs, s))
    {
        if (s.size() == 7
            && isalpha(s[0]) && isalpha(s[1])
            && isdigit(s[2]) && isdigit(s[3]) && isdigit(s[4])
            && isdigit(s[5]) && isdigit(s[6]))
            cout << "found " << s << endl;
    }

    return 0;
}
