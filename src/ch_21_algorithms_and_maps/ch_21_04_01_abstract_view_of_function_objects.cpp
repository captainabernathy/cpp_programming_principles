#include <iostream>
using namespace std;

typedef int S;
typedef double T;

class F {
    S s; // state

public:
    // establish initial state
    F(const S& ss)
        : s(ss) {  }

    T operator() (const S& ss) const
    {
        return ss * ss;
    }

    // reveal state
    const S& state() const
    {
        return s;
    }

    // reset state
    void reset(const S& ss)
    {
        s = ss;
    }
};

int main()
{
    S s = 3;
    F f(s); // create F
    cout << f(s) << endl; // apply f

    return 0;
}
