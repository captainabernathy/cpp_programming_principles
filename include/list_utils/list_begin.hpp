#ifndef LIST_BEGIN_HPP
#define LIST_BEGIN_HPP

#include <list_utils/list_class.hpp> // for list<>
#include <list_utils/list_iterator.hpp> // for list<>::iterator

// returns an iterator to the first element in this list of type T
template<typename T>
typename list<T>::iterator list<T>::begin()
{
    return iterator {first};
}

#endif
