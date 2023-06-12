// program tests the implementation of a vector class that stores elements of
// type double, which now supports a copy constructor, move constructor,
// copy assignment operator, and move assignment operator
//
// vector (class)
//      vector()
//      vector(initializer_list<double> lst)
//      vector(vector const& v)
//      vector(vector&& v)
//      ~vector()
//      vector& operator=(vector const& rhs)
//      vector& operator=(vector&& rhs)
//      double& operator[](size_t i)
//      double operator[](size_t i) const
//      size_t size() const
//      size_t capacity() const
//      void push_back(double d)
//
// void print_vec(vector const& v, string const& s)

#include <iostream> // for cout
#include <utility> // for move()
#include "vector_dbl_utils.hpp" // for vector, print_vec()

int main()
{
    using std::cout;

    vector v1 {1.1, 2.2, 3.3, 4.4}; // initializer list

    cout << "v1.size(): " << v1.size() << '\n'; // 4
    cout << "v1.capacity(): " << v1.capacity() << '\n'; // 4
    print_vec(v1, "v1"); // output v1
    cout << '\n';

    vector v2(v1); // copy constructor

    cout << "v2.size(): " << v2.size() << '\n'; // 4
    cout << "v2.capacity(): " << v2.capacity() << '\n'; // 4
    print_vec(v2, "v2"); // output v2
    cout << '\n';

    vector v3; // default constructor
    v3 = v2; // copy assignment

    cout << "v3.size(): " << v3.size() << '\n'; // 4
    cout << "v3.capacity(): " << v3.capacity() << '\n'; // 4
    print_vec(v3, "v3"); // output v3
    cout << '\n';

    vector vm1(v3); // copy constructor

    // NOTE: vm1 is 'emptied' by the move operation
    vector v4(std::move(vm1)); // move constructor

    cout << "v4.size(): " << v4.size() << '\n'; // 4
    cout << "v4.capacity(): " << v4.capacity() << '\n'; // 4
    print_vec(v4, "v4"); // output v4
    cout << '\n';

    vector v5; // default constructor
    vm1 = v3; // copy assignment

    // NOTE: vm1 is 'emptied' by the move operation
    v5 = std::move(vm1); // move assignment

    cout << "v5.size(): " << v5.size() << '\n'; // 4
    cout << "v5.capacity(): " << v5.capacity() << '\n'; // 4
    print_vec(v5, "v5"); // output v5
    cout << '\n';

    vector v6; // default constructor

    // fill v6 using push_back()
    for (size_t i = 0; i < 4; i++)
    {
        v6.push_back(v1[i]);
        v6.push_back(v2[i] * (i + 1.0));
        v6.push_back(v3[i] * (i + 2.0));
        v6.push_back(v4[i] * (i + 3.0));
        v6.push_back(v5[i] * (i + 5.0));
    }
    cout << "v6.size(): " << v6.size() << '\n'; // 20
    cout << "v6.capacity(): " << v6.capacity() << '\n'; // 32
    print_vec(v6, "v6"); // output v6

    return 0;
}
