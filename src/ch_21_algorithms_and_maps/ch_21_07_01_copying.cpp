// program creates a namespace and implements a function template to copy the
// elements from one collection to another in it, as well as a function
// template to print the elements in a collection

#include <iostream> // for cout, cerr
#include <list> // for list
#include <vector> // for vector
#include <exception> // for exception
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

namespace our {
// function template that copies the elements between the iterators first
// and last in one collection (range [first,last)) to another collection
// starting from the position of the iterator res and returns an iterator
// to the last element copied into the second collection
template<typename In, typename Out>
Out copy(In first, In last, Out res)
{
    while (first != last)
    {
        *res = *first; // copy element
        ++res; // advance to next position in output collection
        ++first; // advance to next position in input collection
    }

    return res;
}

// function template that prints the elements in a collection between the
// iterators start and stop (range [start,stop))
template<typename Iter>
void print(Iter start, Iter stop)
{
    while (start != stop)
    {
        std::cout << *start << '\n';
        start++; // advance to next position in collection
    }
}
}

// function that tests the function template our::copy() by copying the
// elements contained in src to the list specified by dest
// NOTE: if the list dest does not have enough room to contain the elements
// in dest, function throws a runtime_error()
inline void f(std::list<int>& dest, std::vector<int>& src)
{
    if (dest.size() < src.size())
        error("target container too small");
    our::copy(src.begin(), src.end(), dest.begin());
}

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::vector;
        using std::list;
        using std::cout;

        vector<int> v {1, 2, 3, 4};
        list<int> l(4);

        f(l, v);

        our::print(v.begin(), v.end());

        cout << '\n';

        our::print(l.begin(), l.end());
    }
    catch(exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}
