#include <iostream> // I/O library header
#include <iterator> // iterator library header
using namespace std;

// template for a link in a doubly linked list of type T
template<typename T>
struct Link {
    T val;
    Link *prev; // pointer to previous link
    Link *next; // pointer to next link
    
    // constructor... initializes val to t, prev to p, and next to n when
    // provided... otherwise initializes them to default values
    Link(const T& t = T(), Link *p = nullptr, Link *n = nullptr)
        : val(t), prev(p), next(n) {  }
};

// template for a doubly linked list of type T
template<typename T>
class list {
public:
    class iterator;

    // default constructor... allocates pointer to a new link for first, and
    // initializes the pointer to the last link to the first one
    list()
        : first(new Link<T>()), last(first) { }

    // iterator to first element
    iterator begin();

    // iterator to one beyond last element
    iterator end();

    // insert v into list after p
    iterator insert(iterator p, const T& v); // NOT IMPLEMENTED
    
    // remove p from list
    iterator erase(iterator p); // NOT IMPLEMENTED

    // insert v at the end of this list
    void push_back(const T& v); // NOT IMPLEMENTED

    // insert v at the front of this list
    void push_front(const T& v);

    // remove the first element in this list
    void pop_front(); // NOT IMPLEMENTED
    
    // remove the last element in this list
    void pop_back(); // NOT IMPLEMENTED

    // return the first element
    T& front(); // NOT IMPLEMENTED

    // return the last element
    T& back(); // NOT IMPLEMENTED

    Link<T> *first; // pointer to the first link in this list
    Link<T> *last; // pointer to the last link in this list
};

template<typename T>
class list<T>::iterator {
    Link<T> *curr; // pointer to the current node

    public:
        // constructor initializes pointer to current node to p
        iterator(Link<T> *p)
            : curr(p) {  }

        // forward incrementation... advances the pointer to the current node to
        // the next node and returns a reference to this iterator
        iterator& operator++()
        {
            curr = curr->next;
            return *this;
        }

        // backwards decrementation... sets the pointer to the current node to
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
        friend bool operator==(const iterator& lhs, const iterator& rhs)
        {
            return lhs.curr == rhs.curr;
        }
 
        // inequality operator... two iterators are not equal if the pointers to
        // their current nodes are not the same
        friend bool operator!=(const iterator& lhs, const iterator& rhs)
        {
            return lhs.curr != rhs.curr;
        }
};

// returns an iterator to the first element in a list of type T
template<typename T>
typename list<T>::iterator list<T>::begin()
{
    return iterator(first);
}

// returns an iterator to one beyond the last element in a list of type T
template<typename T>
typename list<T>::iterator list<T>::end()
{
    return iterator(last);
}

// inserts t at the front of a list of type T
template<typename T>
void list<T>::push_front(const T& t)
{
    // update pointer to first link in this list...
    // set its value to t, its prev pointer to nullptr, and its next pointer to
    // the link currently first
    first = new Link<T>(t, nullptr, first);
}

// template function that returns an iterator to the element in a collection
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
    cout << "highest value: " << *q << endl << endl;

    list<int>::iterator p = high(lst.begin(), lst.end());

    if (p == lst.end()) // only true when list is empty
        cout << "list is empty";
    else
        cout << "highest value: " << *p << endl;
}
