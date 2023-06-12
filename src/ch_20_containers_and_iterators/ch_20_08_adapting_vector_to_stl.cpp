// program  tests the implementation of a class template for a vector that
// can store elements of any type, which now includes the methods begin(),
// end(), insert(), and erase()
//
// template<typename T, typename A = std::allocator<T>>
// vector (template class)
//      vector()
//      vector(initializer_list<T> lst)
//      vector(vector const& v)
//      vector(vector&& v)
//      ~vector()
//      vector& operator=(vector const& rhs)
//      vector& operator=(vector&& rhs)
//      T& operator[](size_t idx)
//      T const& operator[](size_t idx) const
//      size_t size() const
//      size_t capacity() const
//      iterator begin()
//      const_iterator begin() const
//      iterator end()
//      const_iterator const* end() const
//      iterator insert(T* p, T const& val)
//      iterator erase(T* p)
//      void push_back(T const& t)

#include <iostream> // for cout
#include <vector_utils/vector_utils.hpp> // for vector

int main()
{
    using std::cout;

    vector<int> v1 {1, 2, 3, 4}; // initializer list
    v1.insert(v1.end(), 99); // insert 99 at the the end of v1
    v1.erase(v1.end() - 2); // remove the second to last element of v1
    for (auto v : v1)
        cout << v << ' '; // 1 2 3 99
    cout << '\n';
    cout << v1.size() << " " << v1.capacity() << "\n\n"; // 4 8

    vector<int> v2(v1); // copy constructor
    for (auto v : v2)
        cout << v << ' '; // 1 2 3 99
    cout << '\n';
    cout << v2.size() << " " << v2.capacity() << "\n\n"; // 4 4

    vector<int> v3 = v2; // copy constructor
    for (auto v : v3)
        cout << v << ' '; // 1 2 3 99
    cout << '\n';
    cout << v3.size() << " " << v3.capacity() << "\n\n"; // 4 4

    vector<int> v4; // default constructor
    v4 = v3; // copy assignment
    for (auto v : v4)
        cout << v << ' '; // 1 2 3 99
    cout << '\n';
    cout << v4.size() << " " << v4.capacity() << "\n\n"; // 4 4

    vector<int> v5(std::move(v1)); // move constructor
    for (auto v : v5)
        cout << v << ' '; // 1 2 3 99
    cout << '\n';
    cout << v5.size() << " " << v5.capacity() << "\n\n"; // 4 8

    v5.push_back(18); // insert 18 at the end of v5
    for (auto v : v5)
        cout << v << ' '; // 1 2 3 99 18
    cout << '\n';
    cout << v5.size() << " " << v5.capacity() << "\n\n"; //5 8
    
    vector<int> v6 = std::move(v5); // move constructor
    for (auto v : v6)
        cout << v << ' '; // 1 2 3 99 18
    cout << '\n';
    cout << v6.size() << " " << v6.capacity() << "\n\n"; // 5 8

    vector<int> v7; // default constructor
    v7 = std::move(v6); // move assignment
    for (auto v : v7)
        cout << v << ' '; // 1 2 3 99 18
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << "\n\n"; // 5 8

    v7 = v4; // copy assignment
    for (auto v : v7)
        cout << v << ' '; // 1 2 3 99
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << "\n\n"; // 4 8

    // get iterator to the first element of v7
    vector<int>::iterator i = v7.begin();
    ++i; // advances i to second position of v7
    ++i; // advances i to thrid position of v7

    vector<int>::iterator j = i; // initialize j to i (second position of v7)
    ++j; // advance j to fourth position of v7

    cout << *i << " " << v7[2] << " " << *j << "\n\n"; // 3 3 99

    i = v7.erase(i); // remove element at thrid position of v7
    for (auto v : v7)
        cout << v << ' '; // 1 2 99
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << '\n'; // 3 8
    cout << *i << "\n\n"; // 99... vaule of element at thrid position in v7

    // get iterator to the first element of v7
    vector<int>::iterator k = v7.begin();
    ++k; // advance k to secnod position of v7

    k = v7.insert(k, 13); // insert 13 at the second position of v7
    for (auto v : v7)
        cout << v << ' '; // 1 13 2 99
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << '\n'; // 4 8
    cout << *k << "\n\n"; // 13... value of element at second position in v7

    // assign value of fourth element in v2 to thrid element of v7
    v7[2] = v2[3];
    for (auto v : v7)
        cout << v << ' '; // 1 13 99 99
    cout << '\n';
    cout << v7.size() << " " << v7.capacity() << "\n\n"; // 4 8

    const vector<int> v8(v7); // copy constructor

    for (size_t i = 0; i < v8.size(); i++)
        cout << v8[i] << ' '; // 1 13 99 99
    cout << '\n';
    cout << v8.size() << " " << v8.capacity() << "\n\n"; // 4 4

    const int ci = v8[2];
    int const& cr = v8[3];
    int const *p = &v8[0];
    cout << ci << " " << cr << " " << *p << '\n'; // 99 99 1

    return 0;
}
