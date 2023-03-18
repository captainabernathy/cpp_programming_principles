#include <iostream> // I/O library header
#include <vector> // vector library header
using namespace std;  // add names from std namespace to global namespace

// simple test class
struct X {
    int val;

    // function prints the address of this object along with the name of the
    // function that calls it, which it receives as the string s
    void out(const string& s)
    {
        cerr << this << "->" << s << ": " << val << endl;
    }

    // defalut constructor
    X()
    {
        out("default constructor X()");
        val = 0;
    }

    // explicit, one-argument constructor
    explicit X(int v)
    {
        out("explict constructor X(int)");
        val = v;
    }

    // copy constructor
    X(const X& x)
    {
        out("copy constructor X(X&) ");
        val = x.val;
    }

    // copy assignment
    X& operator=(const X& x)
    {
        out("copy assignment X::operator=()");
        val = x.val;
        return *this;
    }

    // destructor
    ~X() { out("destructor ~X()"); }
};

X glob(2); // global

inline X copy(X x) { return x; }

inline X copy2(X x)
{
    X xx = x;
    return xx;
}

inline X& ref_to(X& x) { return x; }

inline X* make(int i)
{
    X x(i);
    return new X(x);
}

struct XX {
    X a;
    X b;
};

int main()
{
    // create some objects... follow the various constructor, assignemt, and
    // destructor calls
    X loc(4);
    X loc2 = loc;
    loc = X(5);
    loc2 = copy(loc);
    loc2 = copy2(loc);
    X loc3(6);
    X& r = ref_to(loc3);
    delete make(7);
    delete make(8);

    vector<X> v(4);
    XX loc4;
    X* p = new X(9); // an X on the free store
    delete p; // release dynamically allocated resources

    X* pp = new X[5]; // an array of Xs on the free store
    delete[] pp; // release dynamically allocated resources
    return 0;
}
