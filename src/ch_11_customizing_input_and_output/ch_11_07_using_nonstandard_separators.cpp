// program tests the Punct_stream class, which can be used to create objects
// that provide an input stream operator that allows users to specify what
// characters should be considered whitespace
//
// Punct_stream (class)
//      Punct_stream(istream& str)
//      void set_whitespace(string const& s)
//      void add_whitespace(char ch)
//      void case_sensitive(bool b)

#include <iostream> // for cout, cin
#include <vector> // for vector
#include <string> // for string, getline()
#include <algorithm> // for sort()
#include "punct_stream.hpp" // for Punct_stream

// given text input, produce a sorted list of all words in that text ignoring
// punctuation and case differences... and eliminate duplicates from output
int main()
{
    using std::cin;
    using std::vector;
    using std::string;
    using std::cout;
    using std::sort;

    // initialize a Punct_stream object with cn
    Punct_stream ps {cin};
    
    // set Punct_stream's whitespace characters
    ps.set_whitespace(";:,.?!()\"{}<>/&$@#%^*|");
    ps.add_whitespace('~');
    
    // turn off case sensitivity
    ps.case_sensitive(false);

    vector<string> vs;
    string word;

    // read words from ps into word and save result in vs
    cout << "enter some words (or CTRL-D to quit):\n";
    while (ps >> word)
        vs.push_back(word);

    sort(vs.begin(), vs.end()); // sort words in vs in lexicographical order

    // write sorted list of unique words in vs to stdout
    for (size_t i = 0; i < vs.size(); i++)
        if (i == 0 || vs[i] != vs[i - 1])
            cout << vs[i] << '\n';

    return 0;
}
