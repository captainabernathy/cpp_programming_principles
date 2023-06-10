#include <string>

// returns the size of the string passed to li if the beginning of the string
// passed to s is equal to li
size_t is_prefix(std::string const& s, std::string const& li)
{
    size_t sz = li.size();
    // string(str,pos,len)... initializes a string of length len starting at
    // position pos of str
    return (std::string(s, 0, sz) == li) ? sz : 0;
}
