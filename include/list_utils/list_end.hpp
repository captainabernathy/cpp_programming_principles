#ifndef LIST_END_HPP
#define LIST_END_HPP

#include <list_utils/list_class.hpp> // for list<>
#include <list_utils/list_iterator.hpp> // for list<>::iterator

// returns an iterator to one beyond the last element in this list of type T
template<typename T>
typename list<T>::iterator list<T>::end()
{
    return iterator {last};
}

#endif
