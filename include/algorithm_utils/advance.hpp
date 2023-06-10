#ifndef ADVANCE_HPP
#define ADVANCE_HPP

// template for a function that advances an iterator of type t, n positions
// NOTE: +n moves forward, -n moves backwards
template<typename T>
T advance(T t, int n)
{
    while (n > 0)
    {
        ++t;
        n--;
    }

    while (n < 0)
    {
        --t;
        n++;
    }

    return t;
}

#endif
