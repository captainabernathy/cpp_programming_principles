#include <string_utils/string_utils.hpp>

#include <string> // for string

// given a string, function returns whether or not it is a palindrome
bool is_palindrome(std::string const& s)
{
    size_t first = 0;
    size_t last = s.length() - 1;

    // cout up from first and down from last...
    // string must be a mirror image of itself to be a palindrome
    while (first < last)
    {
        if (s[first] != s[last])
            return false;
        first++;
        last--;
    }

    return true;
}

// given a c-string and its length, function returns whether or not it is a
// palindrome
bool is_palindrome(const char s[], int n)
{
    int first = 0;
    int last = n - 1;

    // cout up from first and down from last...
    // string must be a mirror image of itself to be a palindrome
    while (first < last)
    {
        if (s[first] != s[last])
            return false;
        first++;
        last--;
    }

    return true;
}

// given a pointer to the first and last characters in a string, function
// returns whether or not the string is a palindrome
bool is_palindrome(const char *first, const char *last)
{
// only defined by programs that use the iterative version of the algorithm
#ifndef NO_RECURSION
    // recursively increment pointer address from first and decrement it from
    // last... string must be a mirror image of itself to be a palindrome
    return (first < last) ?
            (*first != *last) ? false : is_palindrome(++first, --last) : true;
#else
    // iteratively increment pointer address from first and decrement it from
    // last... string must be a mirror image of itself to be a palindrome
    while (first < last)
    {
        if (*first != *last)
            return false;
        first++;
        last--;
    }
    return true;
#endif
}
