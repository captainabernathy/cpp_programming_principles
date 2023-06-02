// program demonstrates how functions are resolved within a class hierarchy
// as well as how to declare and override virtual functions within a class
// hierarchy

#include <iostream> // for cout, cerr
#include <exception> // for exception

struct B {
    // NOTE: the "virtual" keyword indicates that a function maybe be overridden
    // in a subclass
    virtual void f() const
    {
        std::cout << "B::f  \n";
    }

    void g() const // not virtual
    {
        std::cout << "B::g  \n";
    }
};

struct D : B {
    // NOTE: in order to override a virtual function, it is necessary to match
    // the virtual function's signature exactly
    // the override keyword can be used to explicitly mark a function that
    // overrides a virtual function
    void f() const override // overrides B::f
    {
        std::cout << "D::f  \n";
    }

    void g()
    {
        std::cout << "D::g  \n";
    }
};

struct DD : D {
    void f() // doesn't override D::f.. not const.. declaration doesn't match
    {
        std::cout << "DD::f  \n";
    }

    // DD's own g()
    void g() const
    {
        std::cout << "DD::g  \n";
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
    using std::exception;
    using std::cerr;

    try
    {
        using std::cout;

        B b;
        D d; // d is D is a B
        DD dd; // dd is a DD is a D is a B

        cout << "call(b)\n";
        // b does B things
        call(b); // B::f B::g
        cout << '\n';

        cout << "call(d)\n";
        // NOTE: D overrides B::f() and provides it's own g(), which does not
        // override B::g(). So, since call() accepts a B that makes a call to
        // g(), the call is made to B::g()
        call(d); // D::f B::g
        cout << '\n';

        // NOTE: DD provides its own f() and g(). It does not override D::f()
        // or D::g(). However, dd is a D, and D::f() overrides B::f().
        cout << "call(dd)\n";
        call(dd); // D::f B::g
        cout << '\n';

        cout << "b.f()\n";
        b.f(); // B::f
        cout << '\n';
        cout << "b.g()\n";
        b.g(); // B::g
        cout << '\n';

        cout << "d.f()\n";
        d.f(); // D::f
        cout << '\n';
        cout << "d.g()\n";
        d.g(); // D::g
        cout << '\n';

        cout << "dd.f()\n";
        dd.f(); // DD::f
        cout << '\n';
        cout << "dd.g()\n";
        dd.g(); // DD::g
    }
    catch (exception& ex)
    {
        cerr << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}
