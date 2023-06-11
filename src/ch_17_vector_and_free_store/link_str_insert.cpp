#include "link_str.hpp"

#ifndef LINK_STR_CLASS
// inserts link n before link p and returns a pointer to link n
link *insert(link *p, link *n)
{
    if (n == nullptr)
        return p;
    if (p == nullptr)
        return n;

    n->next = p; // set link n's next pointer to link p

    if (p->prev != nullptr)
        // set the next pointer of link p's prev pointer to link n
        p->prev->next = n;

    // set link n's prev pointer to link p's prev pointer
    n->prev = p->prev;
    
    // set link p's prev pointer to link n
    p->prev = n;
    return n;
}
#else
// inserts link n before this link and returns a pointer to it
link *link::insert(link *n)
{
    if (n == nullptr) // return this pointer if n is NULL
        return this;

    if (this == nullptr) // return n if this pointer is NULL
        return n;

    n->next = this; // set link n's next pointer to this link

    if (prev != nullptr)
        // set the next pointer of this link's prev pointer to link n
        prev->next = n;

    // set link n's prev pointer to this link's prev pointer
    n->prev = prev;
    
    // set this link's prev pointer to link n
    prev = n;

    return n;
}
#endif
