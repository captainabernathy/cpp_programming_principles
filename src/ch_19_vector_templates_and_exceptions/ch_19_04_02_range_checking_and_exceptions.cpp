// program extends the standard library template for a vector of any type to
// include range checking

#include <iostream> // I/O library header
#include <string> // string library header
#include <stdexcept> // convenience classes for logic and runtime errors
#include <vector> // vector library header
#include <sstream> // provides stream classes for operating on strings

// template for a function that converts an object of type T to a string and
// returns it
template<class T>
std::string to_string(T const& t)
{
    std::ostringstream os;
    os << t;
    return os.str();
}

// not necessary
// class used to report range access errors
// struct out_of_range {
//     out_of_range(const std::string& err_msg) {  }
// };


// not necessary
// enhanced vector range error reporting
// struct Range_error : std::out_of_range {
//     ssize_t index;
//     Range_error(ssize_t i)
//         : out_of_range{"Range error at index " + to_string(i)}, index{i}
//     {  }
// };

// template that extends the standard library template for a vector of
// type T to include range checking
template<typename T>
struct Vector : std::vector<T> {
    using size_type = typename std::vector<T>::size_type;
    using std::vector<T>::vector;

    // member access operator
    // provides read and write access to a vector by returning a reference to
    // the element at index n
    // throws an out_of_range() exception if n is an invalid index
    T& operator[](size_type i)
    {
        if (i < 0 || this->size() <= i)
            // throw Range_error{(ssize_t)i};
            throw std::out_of_range("Range error at index " + to_string(i));
        return std::vector<T>::operator[](i);
    }

    T const& operator[](size_type i) const
    {
        if (i < 0 || this->size() <= i)
            // throw Range_error{(ssize_t)i};
            throw std::out_of_range("Range error at index " + to_string(i));
        return std::vector<T>::operator[](i);
    }
};

// template for a function that prints an index-able collection of type T
// prepended by string s... works for any index-able collection that has a size
// function
template<typename T>
void print(T const& t, std::string const& s)
{
    for (size_t i = 0; i < t.size(); i++)
        std::cout << s << "[" << i << "]: " << t[i] << '\n';
}

// hack to get range-checked vector
#define vector Vector

int main()
{
    using std::cout;
    using std::cerr;
    using std::exception;

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

    vector<int> v3; // default constructor
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

    const vector<int> v7(v5); // copy constructor

    cout << "v7.size(): " << v7.size() << '\n'; // 4
    cout << "v7.capacity(): " << v7.capacity() << '\n'; // 4
    print(v7, "v7"); // output v7
    cout << '\n';
    
    int i = v7[3];
    const int j = v7[3];

    cout << "i: " << i << '\n';
    cout << "j: " << j << '\n';

    try
    {
        v1[99] = 9; // bad access
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << '\n';
        return 2;
    }

    return 0;
}
