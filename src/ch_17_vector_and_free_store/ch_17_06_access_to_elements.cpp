// program implements an ad-hoc vector class that can be used to create
// a vector of doubles and demonstrates its usage

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

// simple class to represent vector of doubles
// provides a constructor, destructor, get(), set(), and size() methods
class vector {
    // private members
    int sz; // size
    double *elem; // pointer to the elements

    public:
        // constructor
        // create a new vector of s elements
        vector(int s)
            : sz(s), elem(new double[s]) {  }

        // destructor
        ~vector()
        {
            delete[] elem; // release dynamically allocated resources
        }

        // return the number elements in this vector
        int size() const
        {
            return sz; // current size
        }

        // access: read
        // return the nth element in this vector
        double get(int n) const
        {
            return elem[n];
        }

        // access: write
        // set the nth element in this vector to v
        void set(int n, double v)
        {
            elem[n] = v;
        }
};

int main()
{
    vector v(5); // build a vector

    for (int i = 0; i < v.size(); i++)
    {
        v.set(i, 1.1 + i); // populate elements of v
        // write value of each element in v to stdout
        cout << "v[" << i << "]: " << v.get(i) << endl;
    }

    return 0;
}
