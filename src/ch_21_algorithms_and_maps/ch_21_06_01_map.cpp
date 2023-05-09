// program demonstrates how to use the standard library's map collection to
// to work with an object that contains an ordered sequence of key-value pairs
// such that each key in a map object provides access to a corresponding value

#include <iostream> // I/O library header
#include <map>  // map library header
#include <string> // string library header

int main()
{
    using std::map;
    using std::string;
    using std::cout;
    using std::cin;

    // NOTE: a map is an ordered sequence of key-value pairs in which you can
    // look up a value based on a key
    map<string, int> words;  // keep (word, frequency) pairs

    string s;
    cout << "Enter lines of text or press CTRL-D to exit." << '\n';
    while (cin >> s)
        ++words[s];

    // NOTE: map iterators provide access to a map's key value-pairs
    // the key of a particular element in a map can be accessed via the
    // iterator's first member, and the value at that key can be accessed by
    // the iterator's second member
    for (map<string, int>::const_iterator i = words.begin(); i != words.end();
            ++i)
        cout << i->first << ": " << i->second << '\n';
    cout << '\n';
    
    // NOTE: since a map is an ordered collection, it provides direct access
    // via the [] operator such that providing a key to [] returns a value
    for (map<string, int>::const_iterator i = words.begin(); i != words.end();
            i++)
        cout << i->first << ": " << words[i->first] << '\n';

    return 0;
}
