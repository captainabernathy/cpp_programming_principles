#ifndef PUNCT_STREAM_HPP
#define PUNCT_STREAM_HPP

#include <istream> // for istream
#include <string> // for string
#include <sstream> // for istringstream

// Punct_stream is a user-defined type that is similar to istream but allows
// the user to define what characters should be considered whitespace
class Punct_stream {
public:
    // constructor sets character source and case-sensitivity
    Punct_stream(std::istream& src)
        : source {src},
          sensitive {true} {  }

    // function sets a Punct_stream's whitespace characters to the string
    // received as input
    void set_whitespace(std::string const& s)
    {
        whitespace = s;
    }

    // function adds the character it receives to a Punct_strem's set of
    // whitespace characters
    void add_whitespace(char ch)
    {
        whitespace += ch;
    }

    // function returns whether or not the character it receives is part of a
    // Punct_stream's whitespace characters
    bool is_whitespace(char ch) const;

    // function returns whether or not a Punct_stream is case-sensitive
    void case_sensitive(bool b)
    {
        sensitive = b;
    }

    // function returns the value of a Punct_stream's sensitive member
    bool is_case_sensitive() const
    {
        return sensitive;
    }

    // overloaded input operator
    Punct_stream& operator>>(std::string& s);
    
    // overloaded boolean operator
    operator bool() const;

private:
    std::istream& source;       // character source
    std::istringstream buffer;  // buffer does our formatting
    std::string whitespace;     // whitespace characters
    bool sensitive;             // is stream case sensitive?
};

#endif
