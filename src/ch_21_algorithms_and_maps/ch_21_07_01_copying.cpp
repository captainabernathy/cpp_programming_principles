// program creates a namespace and implements a function to copy the elements
// from one collection to another in it as well as a function to print the
// elements in a collection

#include <iostream> // I/O library header
#include <list> // list library header
#include <string> // string library header
#include <stdexcept> // exception library header
#include <vector> // vector library header

using std::list;
using std::vector;
using std::string;
using std::exception;
using std::runtime_error;
using std::cout;
using std::cerr;
using std::endl;

namespace our {
    // template function that copies the elements between the iterators first
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

    // template function that prints the elements in a collection between the
    // iterators start and stop (range [start,stop))
    template<typename Iter>
    void print(Iter start, Iter stop)
    {
        while (start != stop)
        {
            cout << *start << endl;
            start++; // advance to next position in collection
        }
    }
}

// error function that throws a runtime_error() with the message specified by
// msg
inline void error(string const& msg)
{
    throw runtime_error(msg);
}

// function that tests the template function our::copy() by copying the
// elements contained in src to the list specified by dest
// NOTE: if the list dest does not have enough room to contain the elements
// in dest, function throws a runtime_error()
inline void f(list<int>& dest, vector<int>& src)
{
    if (dest.size() < src.size())
        error("target container too small");
    our::copy(src.begin(), src.end(), dest.begin());
}

int main()
{
    try
    {
        vector<int> v{1, 2, 3, 4};
        list<int> l(4);
        f(l, v);
        our::print(v.begin(), v.end());
        cout << endl;
        our::print(l.begin(), l.end());
    }
    catch(exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }

    return 0;
}
