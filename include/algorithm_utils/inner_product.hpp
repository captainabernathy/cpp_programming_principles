#ifndef INNER_PRODUCT_HPP
#define INNER_PRODUCT_HPP

// function template that returns the inner product of two collections using
// start as the starting point for accumulating the result
//
// the first collection consists of the range of elements between the iterators
// first1 and last1 (range [first1,last1)), and the second collection begins
// at the iterator first2
template<typename Iter1, typename Iter2, typename T>
T inner_product(Iter1 first1, Iter1 last1, Iter2 first2, T start)
{
    while (first1 != last1)
    {
        start += (*first1 * *first2); // accumulate results

        // advance to next position in both collections
        ++first1;
        ++first2;
    }

    return start;
}


// function template that returns the inner product of two collections using
// start as the starting point for accumulating the result
//
// the first collection consists of the range of elements between the iterators
// first1 and last1 (range [first1,last1)), and the second collection begins at
// the iterator first2
//
// the binary operation op2 is successively applied to corresponding elements
// of the first and second collections, and the binary operation op1 is used
// to accumulate the results from op2
template<typename Iter1, typename Iter2, typename T, typename BinOp1,
         typename BinOp2>
T inner_product(Iter1 first1, Iter1 last1, Iter2 first2, T start, BinOp1 op1,
                BinOp2 op2)
{
    while (first1 != last1)
    {
        // output of op2 becomes the second operand of op1
        start = op1(start, op2(*first1, *first2));

        // advance to next position in both collections
        ++first1;
        ++first2;
    }

    return start;
}

#endif
