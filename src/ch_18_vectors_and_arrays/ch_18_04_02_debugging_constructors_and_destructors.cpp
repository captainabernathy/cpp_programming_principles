// program implements a class that provides a default/no-argument constructor,
// a single argument constructor, a copy assignment operator, and a
// destructor.
//
// whenever any of these methods is called within the program, an output
// message associated with each is printed to the screen

#include <string> // for string
#include <iostream> // for cout
#include <vector> // for vector

// simple test class
struct X {
    int val;

    // function prints the address of this object along with the name of the
    // function that calls it, which it receives as the string s
    void out(std::string const& s)
    {
        std::cout << this << "->" << s << ": " << val << '\n';
    }

    // defalut/no-argument constructor
    X()
    {
        val = 0;
        out("default constructor X()");
    }

    // single argument constructor
    explicit X(int v)
    {
        val = v;
        out("explicit constructor X(int)");
    }

    // copy constructor
    X(X const& x)
    {
        val = x.val;
        out("copy constructor X(X&) ");
    }

    // copy assignment
    X& operator=(X const& x)
    {
        val = x.val;
        out("copy assignment X::operator=()");
        return *this;
    }

    // destructor
    ~X() { out("destructor ~X()"); }
};

X glob(2); // global instance of an X... X(int) constructor

inline X copy(X x) { return x; }

inline X copy2(X x)
{
    X xx = x;
    return xx;
}

// returns a reference to the reference it receives... for initializing a
// reference to an X from an X
inline X& ref_to(X& x) { return x; }

// returns a new X constructed from i
inline X* make(int i)
{
    X x(i);
    return new X(x);
}

// class that contains two Xs
struct XX {
    X a;
    X b;
};

int main()
{
    using std::vector;
    using std::cout;

    cout << '\n';

    // create some objects... follow the various constructor, assignemt, and
    // destructor calls
    X loc(4); // X(int) constructor
    cout << '\n';

    X loc2 = loc; // copy constructor
    cout << '\n';

    loc = X(5); // X(int) constructor, copy assignment, destructor
    cout << '\n';

    // copy constructor, copy constructor, copy assignment, destructor,
    // destructor
    loc2 = copy(loc);
    cout << '\n';

    // copy constructor, copy constructor, copy assignment, destructor,
    // destructor
    loc2 = copy2(loc);
    cout << '\n';

    X loc3(6); // X(int) constructor
    cout << '\n';

    X& r = ref_to(loc3);

    // X(int) constructor, copy constructor, destructor, destructor
    delete make(7);
    cout << '\n';

    // X(int) constructor, copy constructor, destructor, destructor
    delete make(8);
    cout << '\n';

    // default constructor, default constructor, default constructor,
    // default constructor
    vector<X> v(4);
    cout << '\n';

    // default constructor, default constructor
    XX loc4;
    cout << '\n';

    // X(int) constructor
    X* p = new X(9); // an X on the free store
    cout << '\n';

    // destructor
    delete p; // release dynamically allocated resources
    cout << '\n';


    // default constructor, default constructor, default constructor,
    // default constructor, default constructor
    X* pp = new X[5]; // an array of Xs on the free store
    cout << '\n';

    // destructor, destructor, destructor, destructor, destructor
    delete[] pp; // release dynamically allocated resources
    cout << '\n';

    // the rest of the destructors run

    return 0;
}
