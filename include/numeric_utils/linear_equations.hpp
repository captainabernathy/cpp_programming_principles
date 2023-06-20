#ifndef LINEAR_EQUATIONS_HPP
#define LINEAR_EQUATIONS_HPP

#include <numeric_utils/linear_equations_types.hpp> // for Matrix, Vector

// returns the result of solving the linear system of equations Ax=b for x
// using gaussian elimination
Vector classical_gaussian_elimination(Matrix& A, Vector& b);

// performs the elimination step when computing the solution to Ax=b (for x)
// via classical gaussian elimination
void classical_elimination(Matrix& A, Vector& b);

// returns the result of solving the linear system of equations Ax=b for x
// using pivotal elimination
Vector pivotal_elimination(Matrix& A, Vector& b);

// performs the elimination step when computing the solution to Ax=b (for x)
// when solving the system with pivotal elimination (default).
// algorithm is less sensitive to rounding errors than classical_elimination(),
// as it optimizes the selection of the pivot row
void partial_pivot_elimination(Matrix& A, Vector& b);

// performs the back substitution step when computing the solution to
// Ax=b (for x)
Vector back_substitution(Matrix const& A, Vector const& b);

#endif
