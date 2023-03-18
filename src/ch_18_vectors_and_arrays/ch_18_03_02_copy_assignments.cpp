#include <iostream> // I/O library header
#include <algorithm> // algorithm library header
#include <initializer_list> // provides initializer_list class template
#include <string> // string library header

using std::string;
using std::cout;
using std::endl;

class vector {
    // private attributes
    size_t sz; // number of elements in a vector
    double *elem; // pointer to elements in a vector

    // void copy(const vector& v)
    // {
    //     // for (size_t i = 0; i < v.sz; i++)
    //     //     elem[i] = v.elem[i];
    //     std::copy(v.elem, v.elem + sz, elem);
    // }

public:
    // public member functions
    // explicit, one-argument constructor
    // allocates memory for a vector of s doubles
    // NOTE: explicit constructors define a conversion from its argument type to
    // its class
    explicit vector(size_t s)
        : sz{s}, elem{new double[sz]}
    {
        for (size_t i = 0; i < sz; i++)
            elem[i] = 0.;
    }

    // constructor that takes an initializer list
    // it creates a vector with a size equal to the number of elements in the
    // initializer list and copies the values of the elements in the
    // initializer list to its elements
    vector(std::initializer_list<double> lst)
        : sz{lst.size()}, elem{new double[sz]}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    // copy constructor
    // gets called when a vector is initialized from another vector
    // it sets this vector's size to the input vector's size and copies the
    // the values of the input vector's elements to this vector's elements
    vector(const vector& v)
        : sz{v.sz}, elem{new double[sz]}
    {
        std::copy(v.elem, v.elem + sz, elem);
    }

    // copy assignment operator
    // gets called when a vector is assigned to from another vector
    // it creates a new vector whose size is equal to rhs, copies the values
    // of the elements in rhs to the new vector's elements, and returns a
    // reference to the new vector
    vector& operator=(const vector& rhs);

    // destructor deallocates dynamically allocated memory
    ~vector() { delete[] elem; }

    // returns the size of a vector
    size_t size() const { return sz; }

    // provides read access to a vector by returning the value
    // of the element at index n
    // NOTE: function does not provide any range checking
    double get(int n) const { return elem[n]; }

    // provides write access to a vector by assign double v to
    // index n
    // NOTE: function does not provide any range checking
    void set(int n, double v) { elem[n] = v; }
};

// copy assignment
vector& vector::operator=(const vector& rhs)
{
    double *p = new double[rhs.sz]; // allocate new space
    
    // copy elements from rhs into p
    std::copy(rhs.elem, rhs.elem + rhs.sz, p);
    delete[] elem; // deallocate space allocated for this vector's elements
    
    elem = p; // set this vector's element pointer to p
    sz = rhs.sz; // update this vector's size
    
    return *this; // return self-reference
}

// outputs the contents of the vector it receives and prepends each
// with the string it receives
void print_vector(vector& v, const string& s);

int main()
{
    // build a vector from an initializer list
    vector v1 {1.1, 2.2, 3.3};
    // build a vector via copy construction
    vector v2(v1);
    // build a vector via copy assignment
    vector v3 = v2;

    // output contents of each vector
    print_vector(v1, "v1");
    cout << endl;
    print_vector(v2, "v2");
    cout << endl;
    print_vector(v3, "v3");

    return 0;
}

void print_vector(vector& v, const string& s)
{
    // loop over each vector and output each element prepended by s
    for (size_t i = 0; i < v.size(); i++)
        cout << s << ": " << v.get(i) << endl;
}
