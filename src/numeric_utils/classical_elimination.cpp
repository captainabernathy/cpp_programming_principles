#include <numeric_utils/linear_equations.hpp>
#include <numeric_utils/linear_equations_errors.hpp> // for Elim_failure
#include <io_utils/to_string.hpp> // for to_string()
#include <numeric_utils/matrix_scale_and_add.hpp> // for scale_and_add<>()

// performs the elimination step when computing the solution to Ax=b (for x)
// via classical gaussian elimination
void classical_elimination(Matrix& A, Vector& b)
{
    const size_t n = A.dim1();

    // loop over one less than the number of rows in A
    for (size_t j = 0; j < n - 1; j++)
    {
        // pivot moves along the diagonal
        const double pivot = A(j, j);

        // NOTE: having a +/- tolerance might improve this test
        if (pivot == 0) // no solution if pivot is 0
            throw Elim_failure("Elimination failure in row " + to_string(j));

        // loop over the subsequent rows in a after j
        for (size_t i = j + 1; i < n; i++)
        {
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
