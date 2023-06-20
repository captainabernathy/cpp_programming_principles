#include <numeric_utils/linear_equations.hpp>
#include <numeric_utils/linear_equations_types.hpp> // for Matrix, Vector

// returns the result of solving the linear system of equations Ax=b for x
// using gaussian elimination
Vector classical_gaussian_elimination(Matrix& A, Vector& b)
{
    classical_elimination(A, b);
    return back_substitution(A, b);
}
