#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include <list_utils/list_class.hpp> // for list<>
#include <list_utils/link_class.hpp> // for link<>

template<typename T>
class list<T>::iterator {
    link<T> *curr; // pointer to the current link
public:
    // constructor initializes the pointer to the current link to p
    iterator(link<T> *p)
        : curr {p} {  }

    // forward/incrementation... advances the pointer to the current link
    // to the next link and returns a reference to this iterator
    iterator& operator++()
    {
        curr = curr->next;
        return *this;
    }

    // backwards/decrementation... sets the pointer to the current link to
    // the previous link and returns a reference to this iterator
    iterator& operator--()
    {
        curr = curr->prev;
        return *this;
    }

    // dereference operator... returns the value of the element at the
    // current link
    T& operator*()
    {
        return curr->value;
    }

    // equality operator... two iterators are equal if the pointers to
    // their current link are the same
    friend bool operator==(iterator const& lhs, iterator const& rhs)
    {
        return lhs.curr == rhs.curr;
    }

    // inequality operator... two iterators are not equal if the pointers
    // to their current link are not the same
    friend bool operator!=(iterator const& lhs, iterator const& rhs)
    {
        return lhs.curr != rhs.curr;
    }
};

#endif
