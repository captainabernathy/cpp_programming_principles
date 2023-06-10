#ifndef FIND_IF_HPP
#define FIND_IF_HPP

// function template that returns the first element in a collection between
// the iterators first and last (range [first,last)) that satisfies the
// predicate function pred and returns an iterator to it...
// if no element satisfies the predicate function the iterator returned will be
// equal to last
template<typename Iter, typename Pred>
Iter find_if(Iter first, Iter last, Pred pred)
{
    while (!(first == last || pred(*first)))
        ++first; // advance to next position in collection
    return first;
}

#endif
