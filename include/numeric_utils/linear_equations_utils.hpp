#ifndef LINEAR_EQUATIONS_UTILS_HPP
#define LINEAR_EQUATIONS_UTILS_HPP

#include <numeric_utils/linear_equations_types.hpp> // for Matrix, Vector

// returns the result of solving the linear system of equations Ax=b for x
Vector solve_linear_system(Matrix A, Vector b);

#endif
