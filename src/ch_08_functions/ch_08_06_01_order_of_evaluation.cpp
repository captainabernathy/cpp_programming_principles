// program implements a function that strips non-alpha-numeric characters from
// text entered by the user

#include <iostream> // I/O library header
#include <string> // string library header
#include <vector> // vector library header
using namespace std;  // add names from std namespace to global namespace

vector<string> v; // global vector of strings
void f(); // function declaration


int main()
{
    // f accumulates strings in v
    f();

    // write elements of v to stdout
    for (auto it : v)
        cout << it << endl;

    return 0;
}

// function prompts user to enter text, removes any non-alpha-numeric characers
// from it, and accumulates the results in the global vector v
void f()
{
    string s; // holds input
    cout << "Enter text or type \"quit\" to exit: ";

    // read from stdin into s
    while (cin >> s && s != "quit")
    {
        // intermediate varaibles used for processing contents of s...
        // recreated each pass through the loop
        string stripped;
        string not_letters;

        // loop over each character in s
        for (size_t i = 0; i < s.size(); i++)
            if (isalpha(s[i]))
                stripped += s[i]; // accumulate alphabetic characters in striped
            else
                // accumulate non-alphabetic characters in not_letters
                not_letters += s[i];

        // add word containing only alphabetic characters into global vector v
        v.push_back(stripped);
        cout << "Enter text or type \"quit\" to exit: ";
    }
}

