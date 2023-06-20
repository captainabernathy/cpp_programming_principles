// program demonstrates how to use the numeric library to solve a system of
// linear equations using classical Gaussian elimination

#include <iostream> // for cout, cerr
#include <exception> // for exception

// define to ensure that solve_linear_system() performs classical Gaussian
// elimination
#ifndef CLASSICAL_ELIMINATION
#define CLASSICAL_ELIMINATION
#endif

#include <numeric_utils/numeric_utils.hpp> // for Matrix, Vector,
                                           // solve_linear_system()

int main()
{
    using std::cout;
    using std::cerr;
    using std::exception;

    try
    {
        // Matrix data
        double a[3][3] = { {1., 2., 3.}, {2., 3., 4.}, {3., 4., 1.} };

        // Vector data
        double b[3] = {14., 20., 14.};

        Matrix A {a}; // initialize Matrix
        Vector B {b}; // initialize Vector

        cout << "Solving A*x=B" << '\n'
            << "A=\n" << A << '\n'
            << "B= " << B << '\n';

        // solve Ax=b (for x)
        Vector x = solve_linear_system(A, B);

        // output result
        cout << "x= " << x << '\n';
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Unknown exception\n";
        return 2;
    }

    return 0;
}
