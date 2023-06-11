#include "link_str.hpp"

#include <string> // for string

#ifndef LINK_STR_CLASS
// finds string s in link(-ed list) p... and returns a pointer to it if found,
// or nullptr if not
link *find(link *p, std::string const& s)
{
    while (p != nullptr)
    {
        if (p->value == s) // found value
            return p;
        p = p->next; // advance pointer to next link
    }

    return nullptr;
}
#else
// finds the string s in a list starting from this link and returns a
// pointer to the link if found... or nullptr if not
link *link::find(std::string const& s)
{
    link *p = this; // start from this link

    while (p != nullptr)
    {
        if (p->value == s) // found value
            return p;
        p = p->next; // advance pointer to next link
    }

    return nullptr;
}
#endif
