// program prompts the user to fill a vector of strings, then it writes the
// number of words it contains to stdout, sorts it, and writes any repeated
// words to stdout
//
// program demonstrates various common vector operations as well as the usage of
// c++'s standard sorting algorithm

#include <iostream> // I/O library header
#include <string> // string library header
#include <vector> // vector library header
#include <algorithm> // algorithm library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    vector<string> words; // empty vector of strings
    string temp; // placeholder variable to fill vector

    cout << "Enter strings values (or CTRL-D when done): "; // prompt user
    while (cin >> temp) // read string into temp
    {
        words.push_back(temp); // write temp to vector
        cout << "Enter strings values (or CTRL-D when done): "; // prompt user
    }
   
    // NOTE: the size() method returns the number of elements in a container
    cout << "Number of words: " << words.size() << endl;

    // default sort... provied by algorithm library
    // requires iterator to first and last elements in the range of the
    // container to be sorted
    sort(words.begin(), words.end()); // sort from beginning to end

    for (unsigned int i = 0; i < words.size(); i++)
        if (i == 0 || words[i - 1] != words[i]) // is this a new word?
            cout << words[i] << endl;

    return 0;
}
