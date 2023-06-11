#ifndef LINK_STR_HPP
#define LINK_STR_HPP

// disable link template
#ifndef LINK_STR
#define LINK_STR
#endif

#include <string> // for string

#ifndef LINK_STR_CLASS
#include <list_utils/link_class.hpp> // for link
// inserts link n before link p and returns a pointer to link n
link *insert(link *p, link *n);

// inserts link n after link p and returns a pointer to link n
link *add(link *p, link *n);

// removes link p from a list and returns a pointer to the link that follows it
link *erase(link *p);

// finds string s in link(-ed list) p... and returns a pointer to it if found,
// or nullptr if not
link *find(link *p, std::string const& s);

// moves link p, n positions in list... +n moves forward, -n moves backwards...
// and returns a pointer to link p
link *advance(link *p, int n);
#else
// class used to build an ad-hoc doubly linked list of strings
class link {
public:
    std::string value;

    // constructor
    link(std::string const& v, link *p = nullptr, link *n = nullptr)
        : value {v}, prev {p}, next {n} {  }

    // inserts link n before this link and returns a pointer to it
    link *insert(link *n);
    
    // removes this link from a list and returns the link that follows it
    link *erase();
    
    // finds the string s in a list starting from this link and returns a
    // pointer to it if found... or nullptr if not
    link *find(std::string const& s);
   
    // NOT IMPLEMENTED:
    // finds the string s in a list starting from this link and returns a
    // pointer to it if found... or nullptr if not
    // const link *find(std::string const& s) const;
   
    // NOT IMPLEMENTED:
    // moves this link n positions in list... +n moves, -n moves backwards
    // link *advance(int n) const;

    // returns a pointer to the link after this link
    link *get_next() const
    {
        return next;
    }

    // returns a pointer to link before this link
    link *get_prev() const
    {
        return prev;
    }

private:
    link *prev; // pointer to link before this link
    link *next; // pointer to link after this link
};
#endif

#endif
