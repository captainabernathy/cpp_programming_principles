// program demonsrates how to implement a class that overloads the function
// call operator so that objects derived from the class can be used as a
// function object

#include <iostream> // for cout

// typedef int S;
using S = int;

// typedef double T;
using T = double;

class F {
    S s; // state

public:
    // establish initial state
    F(S const& ss)
        : s(ss) {  }

    // implement the function call operator to create a function object
    T operator() (S const& ss) const
    {
        return ss * ss;
    }

    // reveal state
    S const& state() const
    {
        return s;
    }

    // reset state
    void reset(S const& ss)
    {
        s = ss;
    }
};

int main()
{
    S s = 3;
    F f(s); // create F
    std::cout << f(s) << '\n'; // 9... apply f

    return 0;
}
