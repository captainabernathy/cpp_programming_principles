// program demonstrates how to use references and the difference between
// references and pointers

#include <iostream> // I/O library header

int main()
{
    using std::cout;

    int x = 10;
    int *p = &x; // initialize pointer p to address of x
    cout << "x: " << x << '\n'; // 10
    cout << "*p: " << *p << "\n\n"; // 10

    *p = 7; // assign to x through p
    cout << "x: " << x << '\n'; // 7
    cout << "*p: " << *p << "\n\n"; // 7

    int x2 = *p; // read x through p into x2
    cout << "x: " << x << '\n'; // 7
    cout << "*p: " << *p << '\n'; // 7
    cout << "x2: " << x2 << "\n\n"; // 7

    int *p2 = &x2; // initialize pointer p2 to address of x2
    cout << "x: " << x << '\n'; // 7
    cout << "*p: " << *p << '\n'; // 7
    cout << "x2: " << x2 << '\n'; // 7
    cout << "*p2 " << *p2 << "\n\n"; // 7

    p2 = p; // p2 and p both point to x... since p points to x
    x2 = 9; // update  x2
    cout << "x: " << x << '\n'; // 7
    cout << "*p: " << *p << '\n'; // 7
    cout << "x2: " << x2 << '\n'; // 9
    cout << "*p2 " << *p2 << "\n\n"; // 7

    p = &x2; // p now points to x2
    cout << "x: " << x << '\n'; // 7
    cout << "*p: " << *p << '\n'; // 9
    cout << "x2: " << x2 << '\n'; // 9
    cout << "*p2 " << *p2 << "\n\n"; // 7... since p2 points to x

    // example with references
    int y = 10;
    int& r = y; // initialize r to y... address of operator not needed
    cout << "y: " << y << '\n'; // 10
    cout << "r: " << r << "\n\n"; // 10... dereference operator not needed

    r = 3; // assign y through r (no * needed)
    cout << "y: " << y << '\n'; // 3
    cout << "r: " << r << "\n\n"; // 3

    int y2 = r; // read y through r into y2... dereference operator not needed
    int& r2 = y2; // initialize r2... address of operator not needed
    cout << "y: " << y << '\n'; // 3
    cout << "r: " << r << '\n'; // 3
    cout << "y2: " << y2 << '\n'; // 3
    cout << "r2: " << r2 << "\n\n"; // 3

    r = 5; // updating r assigns y through r
    cout << "y: " << y << '\n'; // 5
    cout << "r: " << r << '\n'; // 5
    cout << "y2: " << y2 << '\n'; // 3
    cout << "r2: " << r2 << "\n\n"; // 3

    r2 = r; // read y through r into y2 via r2
    cout << "y: " << y << '\n'; // 5
    cout << "r: " << r << '\n'; // 5
    cout << "y2: " << y2 << '\n'; // 5
    cout << "r2: " << r2 << '\n'; // 5

    return 0;
}
