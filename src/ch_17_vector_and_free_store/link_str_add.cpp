#include "link_str.hpp"

// inserts link n after link p and returns a pointer to link n
link *add(link *p, link *n)
{
    if (n == nullptr)
        return p;
    if (p == nullptr)
        return n;
   
    n->prev = p; // set link n's prev pointer to link p
    if (p->next != nullptr)
        // set the prev pointer of link p's next pointer to link n
        p->next->prev = n;

    // set link n's next pointer to link p's next pointer
    n->next = p->next;
    
    // set link p's next pointer to link n
    p->next = n;
    return n;
}
