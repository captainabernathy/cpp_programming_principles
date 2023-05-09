// program demonstrates how to dynamically initialize pointers to objects
// and arrays of objects using defalt/no-argument constructors and initializer
// lists
#include <iostream> // I/O library header

// simple class that provides a default/no argument-constructor
class X {
    public:
        X() {  } // default constructor
};

// simple class that provides a constructor that takes a single element...
// it does not provide a default/no-argument constructor
class Y {
    public:
        Y(int) {  } // no default constructor
};

int main()
{
    using std::cout;

    double *p1 = new double; // dynamically allocate a double

    // dynamically allocate and initialize a double
    double *p2 = new double(5.5);
    
    double *p3 = new double[5]; // dynamically allocate an array of 5 doubles

    *p1 = 3.3;  // assign value to dynamically allocated double
    for (int i = 0; i < 5; i++) // assign values to dynamically allocated array
        p3[i] = 1.1 + i;        // of doubles

    cout << "*p1: " << *p1 << '\n'; // 3.3
    cout << "*p2: " << *p2 << '\n'; // 5.5
    for (int i = 0; i < 5; i++)
        cout << "p3[" << i << "]: " << p3[i] << '\n'; // 1.1 2.1 3.1 4.1 5.1

    // alternatively... dynamically initialize an array of doubles using
    // an initializer list
    double *p4 = new double[]{1.1, 2.1, 3.1, 4.1, 5.1};
    
    for (int i = 0; i < 5; i++)
        cout << "p4[" << i << "]: " << p4[i] << '\n';

    // dynamically allocate one default initialized X
    X* px1 = new X;

    // dynamically allocate an array of 17 default initialized Xs
    X* px2 = new X[17];

    // Y* p1 = new Y; // error: no default constructor
    // Y* py2 = new Y[17]; // error: no default constructor

    Y* py3 = new Y(13); // dynamically allocate a Y via its provided constructor
    Y* py3a = new Y{14}; // same as ^^^ using an initializer list
    
    // NOTE: dynamically allocating an array of Ys requires an initializer list
    Y* py4 = new Y[]{1, 2, 3, 4, 5};

    // return memory for dynamically allocated objects
    delete p1;
    delete p2;
    delete[] p3;
    delete[] p4;
    delete px1;
    delete[] px2;
    delete py3;
    delete py3a;
    delete[] py4;

    return 0;
}
