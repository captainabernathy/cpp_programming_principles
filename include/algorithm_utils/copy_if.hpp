#ifndef COPY_IF_HPP
#define COPY_IF_HPP

// function template that copies the elements between the iterators first
// and last in one collection (range [first,last)) to another collection
// based on the predicated pred and starting from the position of the iterator
// res
//
// returns an iterator to the last element copied into the second collection
template<typename In, typename Out, typename Pred>
Out copy_if(In first, In last, Out res, Pred p)
{
    while (first != last)
    {
        if (p(*first)) // test predicate
        {
            *res = *first; // copy result
            ++res; // advance to next position in output collection
        }
        ++first; // advance to next position in input collection
    }

    return res;
}

#endif
