#ifndef MESSAGE_UTILS_HPP
#define MESSAGE_UTILS_HPP

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
