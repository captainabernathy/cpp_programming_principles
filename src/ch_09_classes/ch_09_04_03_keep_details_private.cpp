// program demonstrates implementation of a constructor that is used to
// initialize an object's private attributes

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

// user-defined date type
class Date {
    // private attributes
    int y;
    int m;
    int d;

public:
    // public member functions
    // constructor declaration
    Date(int y, int m, int d);
    
    // function declaration
    void add_day(int n);

    int month() { return m; }
    int day() { return d; }
    int year() { return y; }
};

// constructor definition... uses input to initialize a Date's private
// attributes
Date::Date(int y, int m, int d)
    : y(y), m(m), d(d) {  }

int main()
{
    Date birthday(1970, 12, 30); // construct a date
    // call birthday's public functions...
    cout << birthday.month() << endl; // 12
    cout << birthday.year() << endl; // 1970
    cout << birthday.day() << endl; // 30

    return 0;
}
