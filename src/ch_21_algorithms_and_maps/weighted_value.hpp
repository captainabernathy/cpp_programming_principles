#ifndef WEIGHTED_VALUE_HPP
#define WEIGHTED_VALUE_HPP

#include <utility> // for pair
#include <string> // for string

// NOTE: a pair object collects two values that may be of different types
// and can be accessed via its public first and second members
//
// function returns the the product of the second members of a and b
inline double weighted_value(std::pair<std::string, double> const& a,
                             std::pair<std::string, double> const& b)
{
    return a.second * b.second;
}

#endif
