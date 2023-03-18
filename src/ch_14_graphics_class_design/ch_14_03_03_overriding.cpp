#include <iostream>
#include <stdexcept>
using namespace std;

struct B {
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
    void f() const // overrides B::f
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
        D d; // D is a B
        DD dd; // DD is a D is a B

        cout << "call(b)" << endl;
        call(b); // B::f ... B::g
        cout << endl;

        cout << "call(d)" << endl;
        call(d); // D::f ... B::g
        cout << endl;

        cout << "call(dd)" << endl;
        call(dd); // D::f ... B::g ... doesn't properly override
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
        dd.f(); // DD:f
        cout << endl;
        cout << "dd.g()" << endl;
        dd.g(); // DD:g
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
