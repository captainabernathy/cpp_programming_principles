#include <numeric_utils/linear_equations.hpp>
#include <numeric_utils/linear_equations_types.hpp> // for Matrix, Vector
#include <numeric_utils/matrix_dot_product.hpp> // for dot_product<>()
#include <numeric_utils/linear_equations_errors.hpp> // for Back_subst_failure
#include <io_utils/io_conversion.hpp> // for to_string()

#ifndef CLASSICAL_ELIMINATION
#include <cpp_facilities/std_lib_facilities.hpp> // for error()
#endif

// performs the back substitution step when computing the solution to
// Ax=b (for x)
Vector back_substitution(Matrix const& A, Vector const& b)
{
    const size_t n = A.dim1(); // number of rows in A
    Vector x(n); // allocate and initialize an empty results vector

    // loop from the last row to the first
    for (long i = n - 1; i >= 0; i--)
    {
        // NOTE: this isn't the best check... lacks a +/- tolerance
        if (double m = A(i, i)) // don't compute if the diagonal element is 0
        {
            // subtract the current b value from the dot product of the
            // elements following the pivot in A and the corresponding elements
            // in x and divide the result by the pivot

            // double s = b(i) - dot_product(A[i].slice(i + 1), x.slice(i + 1));
            // x(i) = s / m;
            x(i) = (b(i) - dot_product(A[i].slice(i + 1), x.slice(i + 1))) / m;
        }
        else
#ifndef CLASSICAL_ELIMINATION
            error("no solution: diagonal element zero duing back substitution");
#else
            throw Back_subst_failure("Back substitution failure in row"
                                     + to_string(i));
#endif
    }

    return x;
}
