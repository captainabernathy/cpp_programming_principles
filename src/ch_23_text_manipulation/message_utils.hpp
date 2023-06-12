#ifndef MESSAGE_UTILS_HPP
#define MESSAGE_UTILS_HPP

// provides:
// Line_iter (alias for vector<string>::const_iterator)
//
// Message (class)
//      Message(Line_iter first_line, Line_iter last_line)
//      Line_iter begin() const
//      Line_iter end() const
#include "message.hpp" // for Message
#include <string> // for string

// returns true and sets the string passed to s the rest of the characters in
// a line of the message passed to msg if the line begins with "From: "...
// returns false otherwise
bool find_from_addr(const Message *m, std::string& s);

// returns a string that contains the rest of the characters in a line of the
// message passed to msg if the line begins with "Subject: "...
// otherwise, returns an empty string
std::string find_subject(Message const& m);

#endif
