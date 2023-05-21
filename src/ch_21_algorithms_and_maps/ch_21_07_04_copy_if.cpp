// program implements a function template that copies elements from one
// collection to another collection based on the results of a predicate
//
// program also implements a class template for a function object that can be
// used as predicate with the function template 

#include <vector> // for vector 
#include <iostream> // for cout

// function template that copies the elements between the iterators first
// and last in one collection (range [first,last)) to another collection
// based on the predicated pred and starting from the position of the iterator
// res
// function returns an iterator to the last element copied into the second
// collection
template<typename In, typename Out, typename Pred>
Out copy_if(In first, In last, Out res, Pred p)
{
    while (first != last)
    {
        if (p(*first)) // test predicate
        {
            *res = *first; // copy result
            ++res; // advance to next position in output collection
        }
        ++first; // advance to next position in input collection
    }

    return res;
}

// class template for a function object that returns true when the object
// passed to it is larger than the object used to instantiate it
template<typename T>
class Larger_than {
    T v; // private data member

public:
    // constructor initializes val
    Larger_than(T val)
        : v {val}
    {  }
    
    // overloaded function call operator intercepts calls to this object
    // returns true if x is greater than this object's v
    bool operator()(T x)
    {
        return x > v;
    }
};

int main()
{
    using std::vector;
    using std::cout;

    vector<int> v1 {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v2(v1.size());
    auto it = copy_if(v1.begin(), v1.end(), v2.begin(), Larger_than<int> {6});

    for (auto i = v2.begin(); i != it; i++)
        cout << *i << '\n';
}
