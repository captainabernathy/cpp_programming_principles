// program tests the implementation of a class template for a vector that can
// store elements of any type
//
// template<typename T>
// vector (template class)
//      vector(initializer_list<T> lst)
//      vector(vector const& v)
//      vector(vector&& v)
//      ~vector()
//      vector& operator=(vector&& rhs)
//      vector& operator=(vector const& rhs)
//      T& operator[](size_t idx)
//      T const& operator[](size_t idx) const
//      size_t size() const
//      size_t capacity() const
//      void push_back(T const& t)
//
// template<typename T>
// void print(T const& t, string const& s)

#include <iostream> // for cout
#include <utility> // for move()

// to force the use of vector<T> since vector<T,A> also matches
#ifndef VECTOR_T
#define VECTOR_T
#endif

#include <vector_utils/vector_utils.hpp> // for vector
#include "collection_utils.hpp" //for print<>()

int main()
{
    using std::cout;

    vector<int> v1 {1, 2, 3, 4}; // initializer list

    cout << "v1.size(): " << v1.size() << '\n'; // 4
    cout << "v1.capacity(): " << v1.capacity() << '\n'; // 4
    print(v1, "v1"); // output v1
    cout << '\n';

    vector<int> v2(v1); // copy constructor

    cout << "v2.size(): " << v2.size() << '\n'; // 4
    cout << "v2.capacity(): " << v2.capacity() << '\n'; // 4
    print(v2, "v2"); // output v2
    cout << '\n';

    vector<int> v3;
    v3 = v2; // copy assignment

    cout << "v3.size(): " << v3.size() << '\n'; // 4
    cout << "v3.capacity(): " << v3.capacity() << '\n'; // 4
    print(v3, "v3"); // output v3
    cout << '\n';

    vector<int> vm1(v3); // copy constructor

    // NOTE: vm1 is 'emptied' by the move operation
    vector<int> v4(std::move(vm1)); // move constructor

    cout << "v4.size(): " << v4.size() << '\n'; // 4
    cout << "v4.capacity(): " << v4.capacity() << '\n'; // 4
    print(v4, "v4"); // output v4
    cout << '\n';

    vector<int> v5; // default constructor
    vm1 = v4; // copy assignment
    v5 = std::move(vm1); // move assignment

    cout << "v5.size(): " << v5.size() << '\n'; // 4
    cout << "v5.capacity(): " << v5.capacity() << '\n'; // 4
    print(v5, "v5"); // output v5
    cout << '\n';

    vector<int> v6; // default constructor

    // fill v6 using push_back()
    for (size_t i = 0; i < 4; i++)
    {
        v6.push_back(v1[i]);
        v6.push_back(v2[i] * (i + 1));
        v6.push_back(v3[i] * (i + 2));
        v6.push_back(v4[i] * (i + 3));
        v6.push_back(v5[i] * (i + 4));
    }

    cout << "v6.size(): " << v6.size() << '\n'; // 20
    cout << "v6.capacity(): " << v6.capacity() << '\n'; // 32
    print(v6, "v6"); // output v6
    cout << '\n';

    const vector<int> v7(v5); // copy constructor

    cout << "v7.size(): " << v7.size() << '\n'; // 4
    cout << "v7.capacity(): " << v7.capacity() << '\n'; // 4
    print(v7, "v7"); // output v7
    cout << '\n';
    
    int i = v7[3];
    const int j = v7[3];

    cout << "i: " << i << '\n';
    cout << "j: " << j << '\n';

    return 0;
}
