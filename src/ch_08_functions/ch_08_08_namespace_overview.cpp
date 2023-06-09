// program provides an overview of the rules regarding namespaces and scope

#include <iostream> // for cout

using std::cout; // add cout to file scope

// NOTE: namespaces create their own scopes
namespace X
{
    int var = 0;
    inline void print() { cout << var << '\n'; }
}

namespace Y
{
    int var = 0;
    inline void print() { cout << var << '\n'; }
}

namespace Z
{
    int var = 0;
    inline void print() { cout << var << '\n'; }
}

int main()
{
    // NOTE: operatore :: resolves scope
    X::var = 7;
    X::print(); // 7

    using namespace Y; // bring names from Y into main's scope
    // no need to use ::
    var = 9;
    print(); // 9

    // blocks create their own scope
    {
        using Z::var; // bring Z's var into block's scope
        using Z::print; // bring Z's print into block's scope
        var = 11;
        print(); // 11
    }

    print(); // 9... since Y's namespace is in main's scope
    X::print(); // 7... "::" required to call X's print

    return 0;
}
