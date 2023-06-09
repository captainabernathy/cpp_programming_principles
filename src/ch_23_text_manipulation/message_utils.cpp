#include "message_utils.hpp"
#include "message.hpp" // for Message, Line_iter
#include <string> // for string
#include <string_utils/string_utils.hpp> // for is_prefix()

// returns true and sets the string passed to s the rest of the characters in
// a line of the message passed to msg if the line begins with "From: "...
// returns false otherwise
bool find_from_addr(const Message *msg, std::string& s)
{
    // loop over lines
    for (Line_iter li = msg->begin(); li != msg->end(); ++li)
        // test if "From: " is a prefix of the current line
        if (size_t sz = is_prefix(*li, "From: "))
        {
            // NOTE: s = string(str,pos) returns the rest of the sting in str
            // begnning at the character pos...
            // so, s = string(*li, sz) is the same as string(*li, sz, -1)
            // s = string(*li, sz, -1); // write the "From: " string to s if so
            s = std::string(*li, sz); // write the "From: " string to s if so
            return true;
        }
    
    return false;
}

// returns a string that contains the rest of the characters in a line of the
// message passed to msg if the line begins with "Subject: "...
// otherwise, returns an empty string
std::string find_subject(Message const& msg)
{
    // loop over lines
    for (Line_iter li = msg.begin(); li != msg.end(); li++)
        // test if "Subject: " is the prefix of the current line
        if (size_t sz = is_prefix(*li, "Subject: "))
            // NOTE: string(str,pos) returns the rest of the string in str
            // beginning at the character pos
            return std::string(*li, sz); // if so return the rest of it
    return ""; // otherwise return an empty string
}
