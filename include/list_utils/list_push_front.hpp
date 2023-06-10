#ifndef LIST_PUSH_FRONT_HPP
#define LIST_PUSH_FRONT_HPP

#include <list_utils/list_class.hpp> // for list<>
#include <list_utils/link_class.hpp> // for link<>

// inserts t at the front of this list of type T
template<typename T>
void list<T>::push_front(T const& t)
{
    // update pointer to first link in this list...
    // set its value to t, its prev pointer to nullptr, and its next pointer to
    // the link currently first
    first = new link<T> {t, nullptr, first};
}

#endif
