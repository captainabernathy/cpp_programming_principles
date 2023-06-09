#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <vector> // for vector
#include <string> // for string

// typedef std::vector<std::string>::const_iterator Line_iter;
using Line_iter = std::vector<std::string>::const_iterator;

// define a Message as a pair of iterators into a vector<string> (line)
// A Message object points to the first and last line of a message
class Message {
    // private members
    Line_iter first;
    Line_iter last;

public:
    // constructor initializes first to first_line and last to last_line
    Message(Line_iter first_line, Line_iter last_line)
        : first {first_line}, last{last_line}
    {  }

    // returns an iterator to the first line in this Message
    Line_iter begin() const
    {
        return first;
    }

    // returns an iterator to the last line in this Message
    Line_iter end() const
    {
        return last;
    }
};

#endif
