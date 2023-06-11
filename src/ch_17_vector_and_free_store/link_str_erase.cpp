#include "link_str.hpp"

#ifndef LINK_STR_CLASS
// removes link p from a list and returns a pointer to the link that follows it
link *erase(link *p)
{
    if (p == nullptr)
        return nullptr;

    if (p->next != nullptr) // there's a link after link p
        // set the prev pointer of link p's next pointer to link p's
        // prev pointer
        p->next->prev = p->prev;

    if (p->prev != nullptr) // there's a link before link p
        // set the next pointer of link p's prev pointer to link p's
        // prev pointer
        p->prev->next = p->next;

    return p->next;
}
#else
// removes this link from a list and returns the link that follows it
link *link::erase()
{
    if (this == nullptr)
        return nullptr;

    if (next != nullptr) // this link has link after it
        // set the prev pointer of this link's next pointer to this link's
        // prev pointer
        next->prev = prev;

    if (prev != nullptr) // this link has a link before it
        // set the next pointer of this link's prev pointer to this link's
        // next pointer
        prev->next = next;

    return next;
}
#endif
