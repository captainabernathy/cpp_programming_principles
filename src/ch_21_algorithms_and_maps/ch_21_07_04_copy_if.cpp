// program tests the implementation of the copy_if<>() function template to
// copy elements from one collection to another collection based on the
// results of a predicate function
//
// program also tests the implementation the class template Larger_than<>,
// which provides a function object that can be used as a predicate function
//
// template<typename In, typename Out, typename Pred>
// Out copy_if(In first, In last, Out res, Pred p)
//
// template<typename T>
// Larger_than (template class)
//      Larger_than(T val)
//      bool operator()(T x)

#include <vector> // for vector
#include <iostream> // for cout
#include <algorithm_utils/copy_if.hpp> // for copy_if<>()
#include "larger_than.hpp" // for Larger_than<>

int main()
{
    using std::vector;
    using std::cout;

    vector<int> v1 {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v2(v1.size());
    auto it = copy_if(v1.begin(), v1.end(), v2.begin(), Larger_than<int> {6});

    for (auto i = v2.begin(); i != it; i++)
        cout << *i << '\n';

    return 0;
}
