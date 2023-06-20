#ifndef ROW_HPP
#define ROW_HPP

#include <cstddef> // for size_t

namespace Numeric_lib {

// NOTE: this template serves only as a prop for its specializations... which,
// in turn, can be used to represent a Row of a Matrix
template<typename T = double, size_t D = 1>
class Row {
    Row() = delete;
};

}

#endif
