#ifndef ACCUMULATE_HPP
#define ACCUMULATE_HPP

// function template that accumulates and returns the sum of the elements in a
// collection between the iterators first and last (range [first,last)) using
// the value passed to start as the starting point for the accumulation
template<typename Iter, typename T>
T accumulate(Iter first, Iter last, T start)
{
    while (first != last)
    {
        start += *first; // accumulate results
        ++first; // advance to next position in collection
    }

    return start;
}

#endif
