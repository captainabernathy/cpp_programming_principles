#ifndef MAIL_FILE_HPP
#define MAIL_FILE_HPP

#include "message.hpp" // for Message
#include <vector> // for vector
#include <string> // for string

// typedef std::vector<Message>::const_iterator Msg_iter;
using Msg_iter = std::vector<Message>::const_iterator;

// Mail_file is a class that holds lines of text and messages, specifically...
// it holds all the lines of a file, and simplifies access to messages
struct Mail_file {

    std::string name; // file name
    std::vector<std::string> lines; // lines in order
    std::vector<Message> messages; // messages in order

    // explicit constructor... builds a mail file from a file
    explicit Mail_file(std::string const& file); // read file into lines

    // returns an iterator to the first message in this Mail_file
    Msg_iter begin() const
    {
        return messages.begin();
    }

    // returns an iterator to the last message in this Mail_file
    Msg_iter end() const
    {
        return messages.end();
    }
};

#endif
