#ifndef LIST_CLASS_HPP
#define LIST_CLASS_HPP

#include <list_utils/link_class.hpp> // for link<>

// template for a doubly linked list of type T
template<typename T>
class list {
    link<T> *first; // pointer to the first link in this list
    link<T> *last; // pointer to the last link in this list
public:
    class iterator; // nested class

    // default constructor... allocates a pointer to a new link for first, and
    // initializes the pointer to the last link to the first one
    list()
        : first {new link<T>()}, last {first} { }

    // returns an iterator to the first element
    iterator begin();

    // returns an iterator to one beyond last element
    iterator end();

    // inserts v into this list after p
    iterator insert(iterator p, T const& v); // NOT IMPLEMENTED
    
    // removes p from this list
    iterator erase(iterator p); // NOT IMPLEMENTED

    // inserts v at the end of this list
    void push_back(T const& t); // NOT IMPLEMENTED

    // inserts v at the front of this list
    void push_front(T const& t);

    // removes the first element in this list
    void pop_front(); // NOT IMPLEMENTED
    
    // removes the last element in this list
    void pop_back(); // NOT IMPLEMENTED

    // returns a reference to the first element in this list
    T& front(); // NOT IMPLEMENTED

    // returns a reference to the last element in this list
    T& back(); // NOT IMPLEMENTED
};

#endif
