// program tests the implementation of a template class for a (doubly linked)
// list that stores elements of any type
//
// program also uses the list template to test the function template high<>()
//
// NOTE: list template does not account for dynamically allocated memory
//
// template<typename T>
// list (template class)
//      iterator (class)
//      list()
//      iterator begin()
//      iterator end()
//      void push_front(T const& t)
//
// template<typename T>
// T high(T first, T last)

#include <iostream> // for cout
#include <list_utils/list_utils.hpp> // for list
#include "high.hpp" // for high<>()

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
