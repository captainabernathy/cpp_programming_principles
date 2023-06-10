#include <text_utils/text_utils.hpp>
#include <text_utils/text_iterator.hpp> // for Text_iterator
#include <string> // for string
#include <algorithm> // for find()

// determines if the text between first and last match the string s
bool match(Text_iterator first, Text_iterator last, std::string const& s)
{
    std::string::const_iterator pos;

    for (pos = s.begin();
         pos != s.end() && first != last && *pos == *first;
         ++pos, ++first) {  }

    return pos == s.end(); // if we reached the end, we matched the string
}

// returns a Text_iterator to the first character if string s exists between
// first and last... or an iterator to the end of the sequence when it does
// not
Text_iterator find_text(Text_iterator first, Text_iterator last,
    std::string const& s)
{
    if (s.size() == 0) // string is empty
        return last;

    char first_char = s[0];
    while (true)
    {
        // look for an occurrence of first_char between first and last
        Text_iterator pos = std::find(first, last, first_char);

        // return an iterator to first character of s when found or an iterator
        // to the end of the sequence otherwise
        if (pos == last || match(pos, last, s))
            return pos;

        first = ++pos; // loot at next character in pos
    }
}
