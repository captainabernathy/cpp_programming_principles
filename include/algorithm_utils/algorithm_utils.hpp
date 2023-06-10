#ifndef ALGORITHM_UTILS_HPP
#define ALGORITHM_UTILS_HPP

// provides:
// template<typename Iter, typename T>
// Iter find(Iter first, Iter last, T const& val)
#include <algorithm_utils/find.hpp>

// provides:
// template<typename Iter, typename Pred>
// Iter find_if(Iter first, Iter last, Pred pred)
#include <algorithm_utils/find_if.hpp>

// provides:
// template<typename Iter, typename T>
// T accumulate(Iter first, Iter last, T start)
#include <algorithm_utils/accumulate.hpp>

// provides:
// template<typename Iter1, typename Iter2, typename T>
// T inner_product(Iter1 first1, Iter1 last1, Iter2 first2, T start)
//
// template<typename Iter1, typename Iter2, typename T, typename BinOp1,
//          typename BinOp2>
// T inner_product(Iter1 first1, Iter1 last1, Iter2 first2, T start,
//                 BinOp1 op1, BinOp2 op2)
#include <algorithm_utils/inner_product.hpp>

// provides:
// template<typename In, typename Out, typename Pred>
// Out copy_if(In first, In last, Out res, Pred p)
#include <algorithm_utils/copy_if.hpp>

// provides:
// template<typename T>
// T advance(T t, int n)
#include <algorithm_utils/advance.hpp>

#endif
