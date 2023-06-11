#include "punct_stream.hpp"

#include <string> // for string, getline()
#include <cctype> // for tolower()

// returns true if the character it receives is part of a Punct_stream's
// whitespace characters
bool Punct_stream::is_whitespace(char ch) const
{
    // read a Punct_stream's whitespace characters and test if any of them
    // match ch
    for (size_t i = 0; i < whitespace.size(); i++)
        if (ch == whitespace[i])
            return true;

    return false;
}

// overloaded input operator
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

// returns true if an operation on a Punct_stream succeeded
Punct_stream::operator bool() const
{
    // true if...
    // neither the fail bit nor bad bit of a Punct_stream's input source stream
    // is set and the Punct_stream's good bit is set
    return !(source.fail() || source.bad()) && source.good();
}
