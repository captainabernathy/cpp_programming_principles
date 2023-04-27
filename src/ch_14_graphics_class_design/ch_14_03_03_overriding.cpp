// program demonstrates how functions are resolved within a class hierarchy
// as well as how to declare and override virtual functions within a class
// hierarchy

#include <iostream> // I/O library header
#include <stdexcept> // provides classes for logic and runtime errors
using namespace std;

struct B {
    // NOTE: the "virtual" keyword indicates that a function maybe be overridden
    // in a subclass
    virtual void f() const
    {
        cout << "B::f  " << endl;
    }

    void g() const // not virtual
    {
        cout << "B::g  " << endl;
    }
};

struct D : B {
    // NOTE: in order to override a virtual function, it is necessary to match
    // the virtual function's signature exactly
    // the override keyword can be used to explicitly mark a function that
    // overrides a virtual function
    void f() const override // overrides B::f
    {
        cout << "D::f  " << endl;
    }

    void g()
    {
        cout << "D::g  " << endl;
    }
};

struct DD : D {
    void f() // doesn't override D::f.. not const.. declaration doesn't match
    {
        cout << "DD::f" << endl;
    }

    // DD's own g()
    void g() const
    {
        cout << "DD::g  " << endl;
    }
};

void call(const B& b)
{
    /* D is a kinde of B... so call() can accept a D
     * DD is a kind of D, and D is a kind of B, so call() can accept a DD */
    b.f();
    b.g();
}

int main()
{
    try
    {
        B b;
        D d; // d is D is a B
        DD dd; // dd is a DD is a D is a B

        cout << "call(b)" << endl;
        // b does B things
        call(b); // B::f B::g
        cout << endl;

        cout << "call(d)" << endl;
        // NOTE: D overrides B::f() and provides it's own g(), which does not
        // override B::g(). So, since call() accepts a B that makes a call to
        // g(), the call is made to B::g()
        call(d); // D::f B::g
        cout << endl;

        // NOTE: DD provides its own f() and g(). It does not override D::f()
        // or D::g(). However, dd is a D, and D::f() overrides B::f().
        cout << "call(dd)" << endl;
        call(dd); // D::f B::g
        cout << endl;

        cout << "b.f()" << endl;
        b.f(); // B::f
        cout << endl;
        cout << "b.g()" << endl;
        b.g(); // B::g
        cout << endl;

        cout << "d.f()" << endl;
        d.f(); // D::f
        cout << endl;
        cout << "d.g()" << endl;
        d.g(); // D::g
        cout << endl;

        cout << "dd.f()" << endl;
        dd.f(); // DD::f
        cout << endl;
        cout << "dd.g()" << endl;
        dd.g(); // DD::g
    }
    catch (exception& ex)
    {
        cerr << ex.what();
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }

    return 0;
}
