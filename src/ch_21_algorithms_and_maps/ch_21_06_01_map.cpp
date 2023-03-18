#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> words;  // keep (word, frequency) pairs

    string s;
    while (cin >> s)
        ++words[s];

    for (map<string, int>::const_iterator i = words.begin(); i != words.end();
            ++i)
        cout << i->first << ": " << i->second << endl;

    return 0;
}
