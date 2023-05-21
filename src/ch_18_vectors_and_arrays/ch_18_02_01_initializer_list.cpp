// program implements an ad-hoc class for a vector of doubles and demonstrates
// how to implement a constructor that takes an initializer list

#include <iostream> // for cout
#include <algorithm> // for copy()
#include <initializer_list> // for initializer_list<>
#include <string> // for string

// ad-hoc class for a vector of doubles
class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elem; // pointer to elements in a vector

public:
    // public member functions
    // explicit, one-argument constructor
    // allocates memory for a vector of s doubles and sets each element in s to
    // 0.0
    // NOTE: explicit constructors define a conversion from its argument type to
    // its class
    explicit vector(size_t s)
        : sz {s}, elem {new double[sz]}
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

    // destructor deallocates dynamically allocated memory
    ~vector() { delete[] elem; }

    // returns the size of this vector
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
void print_vector(vector const&, std::string const&);

int main()
{
    using std::cout;

    // build a vector using an initializer list
    vector v1 {1, 2, 3};

    // build a vector using the explict constructor
    vector v2(3); // three elements initialized to 0.0

    //NOTE: the '=' before initializer list is optional
    vector v3 = {3, 4, 5};

    // output contents of each vector
    print_vector(v1, "v1");
    cout << '\n';

    print_vector(v2, "v2");
    cout << '\n';

    print_vector(v3, "v3");

    return 0;
}

void print_vector(vector const& v, std::string const& s)
{
    // loop over each vector and output each element prepended by s
    for (size_t i = 0; i < v.size(); i++)
        std::cout << s << ": " << v.get(i) << '\n';
}
