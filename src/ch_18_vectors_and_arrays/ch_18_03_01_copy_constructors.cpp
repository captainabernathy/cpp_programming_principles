// program implements an ad-hoc class for a vector of doubles and demonstrates
// how to implement a copy constructor

#include <iostream> // for cout
#include <algorithm> // for copy()
#include <initializer_list> // for initializer_list<>
#include <string> // for string

// ad-hoc class for a vector of doubles
class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elem; // pointer to elements in a vector

    // copy elements from v into *elem
    // void copy(vector const& v)
    // {
    //     // for (size_t i = 0; i < v.sz; i++)
    //     //     elem[i] = v.elem[i];
    //     std::copy(v.elem, v.elem + sz, elem);
    // }

public:
    // public member functions
    // explicit constructor
    // allocates memory for a vector of s doubles and sets each element in s to
    // 0.0
    explicit vector(size_t s)
        : sz {s}, elem {new double[s]}
    {
        for (size_t i = 0; i < sz; i++)
            elem[i] = 0.0;
    }

    // constructor that takes an initializer list
    // it creates a vector with a size equal to the number of elements in the
    // initializer list and copies the values of the elements in the
    // initializer list to its elements
    vector(std::initializer_list<double> lst)
        : sz {lst.size()}, elem {new double[sz]}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    // copy constructor
    // gets called when a vector is initialized from another vector
    // it sets this vector's size to the input vector's size and copies the
    // the values of the input vector's elements to this vector's elements
    vector(vector const& v)
        : sz {v.sz}, elem {new double[v.sz]}
    {
        std::copy(v.elem, v.elem + sz, elem);
    }

    // destructor deallocates dynamically allocated memory
    ~vector() { delete[] elem; }

    // returns the size this vector
    size_t size() const { return sz; }

    // provides read access to this vector by returning the value
    // of the element at index n
    // NOTE: function does not provide any range checking
    double get(size_t n) const { return elem[n]; }

    // provides write access to this vector by assigning double v to the
    // element at index n
    // NOTE: function does not provide any range checking
    void set(size_t n, double v) { elem[n] = v; }
};

// outputs the contents of the vector it receives and prepends each
// with the string it receives
void print_vector(vector const& v, std::string const& s);

int main()
{
    using std::cout;

    // build a vector from an initializer list
    vector v1 {1.1, 2.2, 3.3};

    // build a vector via copy construction
    vector v2(v1);

    // output contents of each vector
    print_vector(v1, "v1");
    cout << '\n';

    print_vector(v2, "v2");

    return 0;
}

void print_vector(vector const& v, std::string const& s)
{
    // loop over each vector and output each element prepended by s
    for (size_t i = 0; i < v.size(); i++)
        std::cout << s << ": " << v.get(i) << '\n';
}
