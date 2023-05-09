// program demonstrates how to use the getline() function to read a line of
// text from a stream into a string varaible, as well as how to use a
// stringstream object to extract to the words contained in that variable into
// a vector of strings

#include <iostream> // I/O library header
#include <string> // string library header
#include <sstream> // provides stream classes for operating on strings
#include <vector> // vector library header

int main()
{
    using std::cout;
    using std::string;
    using std::cin;
    using std::stringstream;
    using std::vector;
    
    cout << "Enter your first and last name: ";
    string name;
    cin >> name; // will read to first whitespace/terminating character
    cout << name << '\n';

    string tmp;
    // read whatever's left in the input stream up to newline into tmp
    getline(cin, tmp);
    cout << tmp << '\n';
    name += tmp; // re-form the entire line
    cout << name << "\n\n";

    string first;
    string second;
    stringstream ss {name}; // initialize a stringstream to name

    ss >> first; // read first word of ss into first string
    ss >> second; // read second word of ss into second string

    cout << first << " " << second << "\n\n";

    {
        cout << "Enter a line of text: ";
       
        string command;
        getline(cin, command); // read a line into command

        stringstream ss(command); // initialize stringstream to command
        
        vector<string> words; // to store the strings in command
        string s; // for reading from ss
        
        // read the strings contained in ss into s and write them to vector
        // words
        while (ss >> s)
            words.push_back(s);

        cout << '\n';
        // write each word in words separted by a space to stdout
        for (auto word : words)
            cout << word << " ";

        cout << '\n';
    }

    return 0;
}
