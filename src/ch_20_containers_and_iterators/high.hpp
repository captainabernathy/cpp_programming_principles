#ifndef HIGH_HPP
#define HIGH_HPP

// function template that returns an iterator to the element in a collection
// between first and last... [first, last)... that has the highest value
template<typename T>
T high(T first, T last)
{
    // assume value of first iteraor is the highest in the range
    T highest = first;
    for (T t = first; t != last; ++t) // iterate over range
        if (*highest < *t) // update high if value at current high is less than
            highest = t;   // value at current iterator
    return highest; // return iterator to highest element in range
}

#endif
