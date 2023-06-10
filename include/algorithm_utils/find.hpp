#ifndef FIND_HPP
#define FIND_HPP

// function template that finds the first element between the iterators
// first and last (range [first,last)) that is equal to val and returns an
// iterator to it...
// if val is not found the iterator returned will be equal to last
template<typename Iter, typename T>
Iter find(Iter first, Iter last, T const& val)
{
// only defined when testing the for loop below
#ifndef FIND_02
    // while (first != last && *first != val)
    while (!(first == last || *first == val))
        ++first; // advance to next position in collection
    return first;
#else
    // NOTE: this implementation is less efficient that the one above
    for (Iter p = first; p != last; ++p)
        if (*p == val) // test predicate
            return p;
    return last;
#endif
}

#endif
