// program demonstrates how to implement and call function that have pointer
// and reference parameters

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include <string> // string library header

// simple error function that throws a runtime_error with the proivded message
inline void error(std::string const& msg)
{
    throw std::runtime_error(msg);
}

// compute a new value and return it
int incr_v(int x);

// pass a pointer
// function dereference the pointer it receives and increments its value
void incr_p(int *p);

// pass a reference
// funciton increments the value of the reference it receives
void incr_r(int& r);

// function derefernece the value p points to and increments it...
// calls error() if p is NULL
void incr_p(char *p);

int main()
{
    using std::cerr;
    using std::exception;

    try
    {
        using std::cout;

        {
            int x = 2;
            cout << "x: " << x << '\n'; // 2
            x = incr_v(x);
            cout << "x: " << x << "\n\n"; // 3
        }

        {
            int x = 7;
            cout << "x: " << x << '\n'; // 7

            incr_p(&x); // pass pointer
            cout << "x: " << x << '\n'; // 8

            incr_r(x); // pass reference... address of operator not needed
            cout << "x: " << x << '\n'; // 9
        }

        {
            char *p = nullptr;
            incr_p(p); // will throw exception
        }
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Oops: unknown exception!" << '\n';
        return 2;
    }

    return 0;
}

int incr_v(int x)
{
    return x + 1;
}

void incr_p(int *p)
{
    ++*p; // dereference and increment value being pointed to
}

void incr_p(char *p)
{
    if (p == nullptr)
        error("null pointer argument to incr_p()");
    ++*p; // dereference and increment value being pointed to
}

void incr_r(int& r)
{
    ++r; // increment referenced value
}
