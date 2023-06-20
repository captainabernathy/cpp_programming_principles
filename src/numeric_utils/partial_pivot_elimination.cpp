#include <numeric_utils/linear_equations.hpp>
#include <numeric_utils/linear_equations_types.hpp> // for Matrix, Vector
#include <cmath> // abs()
#include <algorithm> // for swap()
#include <numeric_utils/matrix_scale_and_add.hpp> // for scale_and_add<>()
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

// performs the elimination step when computing the solution to Ax=b (for x)
// when solving the system with pivotal elimination (default). algorithm is
// less sensitive to rounding errors than classical_elimination(), as it
// optimizes the selection of the pivot row
void partial_pivot_elimination(Matrix& A, Vector& b)
{
    const size_t n = A.dim1(); // number of rows in A

    // loop over rows
    for (size_t j = 0; j < n; j++)
    {
        size_t pivot_row = j; // greedily assume row j is the best to pivot on

        // loop over rows following j and choose the pivot row as the row that
        // contains the element with the largest magnitude in column j
        for (size_t k = j + 1; k < n; k++)
            if (abs(A(k, j)) > abs(A(pivot_row, j)))
                pivot_row = k;

        // if the pivot changed, swap rows
        if (pivot_row != j)
        {
            A.swap_rows(j, pivot_row);
            std::swap(b(j), b(pivot_row));
        }

        // loop over the rows following j
        for (size_t i = j + 1; i < n; i++)
        {
            // choose the element on the diagonal as the pivot
            const double pivot = A(j, j);

            // NOTE: having a +/- tolerance might improve this test
            if (pivot == 0) // no solution if pivot is 0
                error("no solution: pivot == 0");

            const double mult = A(i, j) / pivot; // multiplier for row i

            // compute elimination step on A and update row i...
            // NOTE: update can change the elements on row i of A from the
            // pivot element to the end of the row
            A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));

            // compute elimination step on b for row i
            b(i) -= mult * b(j);
        }
    }
}
