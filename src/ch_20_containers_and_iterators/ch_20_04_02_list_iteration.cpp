// program implements a template for a link/node structure in a doubly linked
// list and a template class for a doubly linked list that contains a nested
// iterator class, which it subsequently provides a template class for.
//
// NOTE: program does NOT provide a full list or template implementation nor
// does it account for dynamically allocated memory

#include <iostream> // for cout

// template for a Link in a doubly linked list of type T
template<typename T>
struct Link {
    T val;
    Link *prev; // pointer to the Link before this Link
    Link *next; // pointer to the Link after this Link
    
    // constructor... initializes val to t, prev to p, and next to n when
    // provided... otherwise initializes them to default values
    Link(T const& t = T(), Link *p = nullptr, Link *n = nullptr)
        : val {t}, prev {p}, next {n} {  }
};

// template for a doubly linked list of type T
template<typename T>
class list {
    Link<T> *first; // pointer to the first Link in this list
    Link<T> *last; // pointer to the last Link in this list
public:
    class iterator; // nested class

    // default constructor... allocates a pointer to a new Link for first, and
    // initializes the pointer to the last Link to the first one
    list()
        : first {new Link<T>()}, last {first} { }

    // returns an iterator to the first element
    iterator begin();

    // returns an iterator to one beyond last element
    iterator end();

    // inserts v into this list after p
    iterator insert(iterator p, T const& v); // NOT IMPLEMENTED
    
    // removes p from this list
    iterator erase(iterator p); // NOT IMPLEMENTED

    // inserts v at the end of this list
    void push_back(T const& v); // NOT IMPLEMENTED

    // inserts v at the front of this list
    void push_front(T const& v);

    // removes the first element in this list
    void pop_front(); // NOT IMPLEMENTED
    
    // removes the last element in this list
    void pop_back(); // NOT IMPLEMENTED

    // returns a reference to the first element in this list
    T& front(); // NOT IMPLEMENTED

    // returns a reference to the last element in this list
    T& back(); // NOT IMPLEMENTED

};

template<typename T>
class list<T>::iterator {
Link<T> *curr; // pointer to the current node

public:
    // constructor initializes the pointer to the current node to p
    iterator(Link<T> *p)
        : curr {p} {  }

    // forward/incrementation... advances the pointer to the current node
    // to the next node and returns a reference to this iterator
    iterator& operator++()
    {
        curr = curr->next;
        return *this;
    }

    // backwards/decrementation... sets the pointer to the current node to
    // the previous node and returns a reference to this iterator
    iterator& operator--()
    {
        curr = curr->prev;
        return *this;
    }

    // dereference operator... returns the value of the element at the
    // current node
    T& operator*()
    {
        return curr->val;
    }

    // equality operator... two iterators are equal if the pointers to
    // their current nodes are the same
    friend bool operator==(iterator const& lhs, iterator const& rhs)
    {
        return lhs.curr == rhs.curr;
    }

    // inequality operator... two iterators are not equal if the pointers
    // to their current nodes are not the same
    friend bool operator!=(iterator const& lhs, iterator const& rhs)
    {
        return lhs.curr != rhs.curr;
    }
};

// returns an iterator to the first element in this list of type T
template<typename T>
typename list<T>::iterator list<T>::begin()
{
    return iterator {first};
}

// returns an iterator to one beyond the last element in this list of type T
template<typename T>
typename list<T>::iterator list<T>::end()
{
    return iterator {last};
}

// inserts t at the front of this list of type T
template<typename T>
void list<T>::push_front(T const& t)
{
    // update pointer to first Link in this list...
    // set its value to t, its prev pointer to nullptr, and its next pointer to
    // the Link currently first
    first = new Link<T> {t, nullptr, first};
}

// function template that returns an iterator to the element in a collection
// between first and last... [first, last)... that has the highest value
template<typename T>
T high(T first, T last)
{
    // assume value at the first iterator is the highest in the range
    T high = first;
    for (T t = first; t != last; ++t) // iterate over range
        if (*high < *t) // update high if value at curent high is lest than
            high = t;   // value at current iterator
    return high; // return iterator to highest element in range
}

// test function
void f();

int main()
{
    f();

    return 0;
}

void f()
{
    list<int> lst; // empty list of ints
    for (int i = 0; i < 10; i++) // add elements to list
        lst.push_front(10 - i);

    list<int>::iterator q = high(lst.begin(), lst.end());
    std::cout << "highest value: " << *q << "\n\n";

    list<int>::iterator p = high(lst.begin(), lst.end());

    if (p == lst.end()) // only true when list is empty
        std::cout << "list is empty";
    else
        std::cout << "highest value: " << *p << '\n';
}
