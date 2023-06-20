#include <numeric_utils/linear_equations_utils.hpp>
#include <numeric_utils/linear_equations_types.hpp> // for Matrix, Vector
// for pivotal_elimination(), classical_gaussian_elimination()
#include <numeric_utils/linear_equations.hpp>

// returns the result of solving the linear system of equations Ax=b for x
Vector solve_linear_system(Matrix A, Vector b)
{
#ifndef CLASSICAL_ELIMINATION
    return pivotal_elimination(A, b);
#else
    return classical_gaussian_elimination(A, b);
#endif
}
