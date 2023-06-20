#include <iostream> // for cout, cerr
#include <exception> // for exception

// define to ensure that solve_linear_system() performs classical Gaussian
// elimination
#ifndef CLASSICAL_ELIMINATION
#define CLASSICAL_ELIMINATION
#endif

#include <numeric_utils/numeric_utils.hpp> // for Matrix, Vector
                                           // solve_linear_system()
#include "ch_24_utils.hpp" // for random_matrix(), random_vector()

// function that solves a random system of linear equations in n variables
void solve_random_system(size_t n);

int main()
{
    solve_random_system(3);
    solve_random_system(4);
    solve_random_system(5);

    return 0;
}


// function that solves a random system of linear equations in n variables
void solve_random_system(size_t n)
{
    Matrix A = random_matrix(n); // initialize Matrix
    Vector b = random_vector(n); // initialize Vector

    // output Matrix and Vector
    std::cout << "A =\n" << A << "\n\n";
    std::cout << "b = " << b << "\n\n";

    try
    {
        // solve Ax=b (for x)
        Vector x = solve_linear_system(A, b);
        
        // output result
        std::cout << "classical elimination solution is x = " << x << "\n\n";

        // validate result
        Vector v = A * x;
        std::cout << "A * x = " << v << "\n\n"; // should equal b
    }
    catch(std::exception const& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}
