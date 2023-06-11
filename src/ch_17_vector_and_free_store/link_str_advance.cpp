#include "link_str.hpp"

// moves link p, n positions in list... +n moves forward, -n moves backwards...
// and returns a pointer to link p
link* advance(link *p, int n)
{
    if (p == nullptr)
        return nullptr;

    // moving p forward
    if (0 < n)
    {
        while (n != 0)
        {
            if (p->next == nullptr)
                return nullptr;
            p = p->next; // move p forward and
            n--; // decrement n
        }
    }

    // moving p backwards
    if (n < 0)
    {
        while (n != 0)
        {
            if (p->prev == nullptr)
                return nullptr;
            p = p->prev; // move p backwards and
            n++; // increment n
        }
    }

    return p;
}
