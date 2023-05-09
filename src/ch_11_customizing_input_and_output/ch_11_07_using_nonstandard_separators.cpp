// program implements a class that can be used to create objects that provide
// an input stream that allows users to specify what characters should be
// considered whitespace

#include <iostream> // I/O library header
#include <string> // string library header
#include <sstream> // provides stream classes for operating on strings
#include <vector> // vector library header
#include <algorithm> // algorithm library header

// Punct_stream is a user-defined type that is similar to istream but allows
// the user to define what characters should be considered whitespace
class Punct_stream {
public:
    // constructor sets character source and case-sensitivity
    Punct_stream(std::istream& src)
        : source {src}, sensitive {true} {  }

    // function sets a Punct_stream's whitespace characters to the string
    // received as input
    void set_whitespace(std::string const& s) { whitespace = s; }

    // function adds the character it receives to a Punct_strem's set of
    // whitespace characters
    void add_white(char ch) { whitespace += ch; }

    // function returns whether or not the character it receives is part of a
    // Punct_stream's whitespace characters
    bool is_whitespace(char ch);

    // function returns whether or not a Punct_stream is case-sensitive
    void case_sensitive(bool b) { sensitive = b; }

    // function returns the value of a Punct_stream's sensitive member
    bool is_case_sensitive() { return sensitive; }

    // overloaded input operator
    Punct_stream& operator>>(std::string& s);
    
    // overloaded boolean operator
    operator bool();

private:
    std::istream& source;        // character source
    std::istringstream buffer;   // buffer does our formatting
    std::string whitespace;      // whitespace characters
    bool sensitive;         // is stream case sensitive?
};

Punct_stream& Punct_stream::operator>>(std::string& s)
{
    // try to read from a Punct_stream's buffer into s
    // NOTE: when a Punct_stream's buffer fails, we must replenish the buffer
    // from the Punct_stream's source
    while (!(buffer >> s))
    {
        if (buffer.bad() || !source.good())
            return *this;

        buffer.clear(); // clear Punct_stream's buffer's error flags

        // replenish buffer
        std::string line;
        
        // read line from Punct_stream's source string into the string line
        getline(source, line);

        // do character replacement as needed:
        for (size_t i = 0; i < line.size(); i++)
            if (is_whitespace(line[i])) // replace all whitespace characters
                line[i] = ' ';  // in line with a space
            else if (!sensitive) // convert character to lower case if
                line[i] = tolower(line[i]); // Punct_stream is case-sensitive

        // set Punct_stream's istringstream buffer's string to line
        // set the contents of the Punct_stream's buffer to line
        buffer.str(line); // put line into Punct_stream's buffer
    }

    return *this;
}

// returns true if the character it receives is part of a Punct_stream's
// whitespace characters
bool Punct_stream::is_whitespace(char ch)
{
    // read a Punct_stream's whitespace characters and test if any of them
    // match ch
    for (size_t i = 0; i < whitespace.size(); i++)
        if (ch == whitespace[i])
            return true;

    return false;
}

// returns true if an operation on a Punct_stream succeeded
Punct_stream::operator bool()
{
    // true if...
    // neither the fail bit nor bad bit of a Punct_stream's input source stream
    // is set and the Punct_stream's good bit is set
    return !(source.fail() || source.bad()) && source.good();
}


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
    Punct_stream ps(cin);
    
    // set Punct_stream's whitespace characters
    ps.set_whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
    
    // turn off case sensitivity
    ps.case_sensitive(false);

    vector<string> vs;
    string word;

    // read words from ps into word and save result in vs
    cout << "enter some words (or CTRL-D to quit): " << '\n';
    while (ps >> word)
        vs.push_back(word);

    sort(vs.begin(), vs.end()); // sort words in vs in lexicographical order

    // write sorted list of unique words in vs to stdout
    for (size_t i = 0; i < vs.size(); i++)
        if (i == 0 || vs[i] != vs[i - 1])
            cout << vs[i] << '\n';

    return 0;
}
