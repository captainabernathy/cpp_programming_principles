#ifndef MATRIX_IO_HPP
#define MATRIX_IO_HPP

#include <ostream> // for ostream
#include <istream> // for istream
#include <numeric_utils/matrix.hpp> // for Matrix<>
#include <numeric_utils/matrix_error.hpp> // for error()

namespace Numeric_lib {

// template function for an output operator for a Matrix
template<typename T>
std::ostream& operator<<(std::ostream& os, Matrix<T> const& v)
{
    os << '{';

    for (size_t i = 0; i < v.dim1(); i++)
    {
        os << "  ";
        os << v(i);
    }

    os << "  }";

    return os;
}

// template function for an output operator for a two-dimensional Matrix
template<typename T>
std::ostream& operator<<(std::ostream& os, Matrix<T, 2> const& m)
{
    os << "{\n";

    for (size_t i = 0; i < m.dim1(); i++)
        os << '\t' << m[i] << '\n'; // uses template for << above

    os << '}';

    return os;
}

// template function for an input operator for a Matrix
template<typename T>
std::istream& operator>>(std::istream& is, Matrix<T>& v)
{
    char ch;
    is >> ch;

    if (ch != '{')
        error("'{' missing in Matrix<T, 1> input");

    for (size_t i = 0; i < v.dim1(); i++)
        is >> v(i);

    is >> ch;

    if (ch != '}')
        error("'}' missing in Matrix<T, 1> input");

    return is;
}

// template function for an input operator for a two-dimensional Matrix
template<typename T>
std::istream& operator>>(std::istream& is, Matrix<T, 2>& m)
{
    char ch;
    is >> ch;

    if (ch != '{')
        error("'{' missing in Matrix<T, 2> input");

    for (size_t i = 0; i < m.dim1(); i++)
    {
        Matrix<T, 1> tmp {m.dim2()};
        is >> tmp; // uses >> for Marix<T> above
        m[i] = tmp;
    }

    is >> ch;

    if (ch != '}')
        error("'}' missing in Matrix<T, 2> input");

    return is;
}

}
#endif
