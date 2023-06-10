#ifndef LINK_HPP
#define LINK_HPP

// not defined when link<> needed
#ifdef LINK_STR
#include <string> // for string
#endif

// not defined when link<> needed
#ifndef LINK_STR
// template for a link in a doubly linked list of type T
template<typename T>
#endif
struct link {
// not defined when link<> needed
#ifndef LINK_STR
    T value;
#else
    std::string value;
#endif
    link *prev; // pointer to the link before this link
    link *next; // pointer to the link after this link
    
// not defined when link<> needed
#ifndef LINK_STR
    // constructor... initializes value to t, prev to p, and next to n when
    // provided... otherwise initializes them to default values
    link(T const& t = T(), link *p = nullptr, link *n = nullptr)
#else
    link(std::string const& s, link *p = nullptr, link *n = nullptr)
#endif
        :
// not defined when link<> needed
#ifndef LINK_STR
          value {t},
#else
          value {s},
#endif
          prev {p},
          next {n} {  }
};

#endif
