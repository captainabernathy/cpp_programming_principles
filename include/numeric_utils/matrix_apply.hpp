#ifndef MATRIX_APPLY_HPP
#define MATRIX_APPLY_HPP

#include <numeric_utils/matrix_xfer.hpp> // for xfer<>()

namespace Numeric_lib {

// returns an object of type A that represents the result of applying the
// function f to x
// NOTE: x must have a constructor that takes an A and an F, and X must also
// have a xfer() method that takes an A
template<typename F, typename A>
A apply(F f, A x)
{
    A res(x, f);

    return xfer(res);
}

// returns an object of type A that represents the result of applying the
// function f to x using a as an additional argument to the call
// NOTE: x must have a constructor that takes an A, an F, and an Arg, and X
// must also have a xfer() method than takes an A
template<typename F, typename Arg, typename A>
A apply(F f, A x, Arg a)
{
    A res(x, f, a);

    return xfer(res);
}

}

#endif
