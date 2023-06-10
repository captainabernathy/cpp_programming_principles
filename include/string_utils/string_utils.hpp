#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <string>

// is *li the first part of s?
// returns the size of the string passed to li if the beginning of the string
// passed to s is equal to li
size_t is_prefix(std::string const& s, std::string const& li);

// class for a function object that performs a case-insensitive
// comparison between two strings
struct No_case {
    // returns true when x comes before y, false otherwise
    bool operator()(std::string const& x, std::string const& y) const;
};

// given a string, function returns whether or not it is a palindrome
bool is_palindrome(std::string const&);

// given a c-string and its length, function returns whether or not it is a
// palindrome
bool is_palindrome(const char s[], int n);

// given a pointer to the first and last characters in a string, function
// returns whether or not the string is a palindrome
bool is_palindrome(const char *first, const char *last);

#endif
