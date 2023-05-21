// program implements a function that strips non-alpha-numeric characters from
// text entered by the user

#include <iostream> // for cin, cout
#include <cctype> // for isalpha()
#include <string> // for string
#include <vector> // for vector

std::vector<std::string> v; // global vector of strings
void f(); // function declaration


int main()
{
    // f accumulates strings in v
    f();

    // write elements of v to stdout
    for (auto it : v)
        std::cout << it << '\n';

    return 0;
}

// function prompts user to enter text, removes any non-alpha-numeric characers
// from it, and accumulates the results in the global vector v
void f()
{
    std::string s; // holds input
    std::cout << "Enter text or type \"quit\" to exit: ";

    // read from stdin into s
    while (std::cin >> s && s != "quit")
    {
        // intermediate varaibles used for processing contents of s...
        // recreated each pass through the loop
        std::string stripped;
        std::string not_letters;

        // loop over each character in s
        for (size_t i = 0; i < s.size(); i++)
            if (isalpha(s[i]))
                stripped += s[i]; // accumulate alphabetic characters in striped
            else
                // accumulate non-alphabetic characters in not_letters
                not_letters += s[i];

        // add word containing only alphabetic characters into global vector v
        v.push_back(stripped);
        std::cout << "Enter text or type \"quit\" to exit: ";
    }
}

