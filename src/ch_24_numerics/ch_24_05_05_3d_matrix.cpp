// program demonstrates how to perform various operations on a three-dimensonal
// Matrix using the class template Matrix<T,3> and other features provided

#include <iostream> // for cout
#include <numeric_utils/matrix_utils.hpp> // for Matrix<>, apply<>()

int c;

// function template to print a 3D matrix
template<typename T>
void print_3d(const Numeric_lib::Matrix<T, 3>& m)
{
    for (size_t i = 0; i < m.dim1(); i++)
    {
        std::cout << m[i] << '\n';

    }
}

int main()
{
    using namespace Numeric_lib;
    using std::cout;

    Matrix<int, 3> a(4, 5, 3); // a 4x5x3 Matrix
   
    size_t sz = a.size(); // total number of elements in a
    size_t d1 = a.dim1(); // number of elements in dimension 1
    size_t d2 = a.dim2(); // number of elements in dimension 2
    size_t d3 = a.dim3(); // number of elements in dimension 3

    cout << sz << ' ' << d1 << ' ' << d2 << ' ' << d3 << "\n\n"; // 40 4 5 2

    // initialize a's elements with a lambda
    a.apply([](int& a){ a = c++; });

    print_3d(a);
    cout << '\n';

    int *p = a.data();  // a's raw data

    for (size_t i = 0; i < d1; i++)
    {
        cout << "{\n";
        for (size_t j = 0; j < d2; j++)
        {
            cout <<"\t{  ";
            for (size_t k = 0; k < d3; k++)
            {
                // 3D linearized offset
                cout << p[i * d2 * d3 + j * d3 + k] << "  ";
            }
            cout << "}\n";
        }
        cout << "}\n";
    }
    cout << '\n';

    size_t i = 1;
    size_t j = 3;
    size_t k = 2;

    cout << a(i, j, k) << '\n'; // 41
    cout << a[i][j][k] << "\n\n"; // 41

    cout << a[i][j] << "\n\n"; // 3x1 matrix... 4th row at depth i { 24 25 26 }
    cout << a[i] << "\n\n"; // 5x3 Matrix at depth i (elements 15-29)
    
    print_3d(a.slice(i)); // each 5x3 Matrix from depth i to the end
    cout << "\n\n";
    
    print_3d(a.slice(i, j)); // each 5x3 Matrix from depth i up to depth j
    cout << "\n\n";

    Matrix<int, 3> a2 = apply([](int a){return a * a;}, a); // copy initialize
    print_3d(a2);

    Matrix<int, 3> a3 = apply([](int a, int b){ return a * b; }, a, 2);

    print_3d(a3);
    cout << "\n\n";

    a.swap_rows(1, 3); // swap the second and fourth rows in a
    print_3d(a);
    cout << "\n\n";

    size_t grid_nx = 5;
    size_t grid_ny = 5;
    size_t grid_nz = 5;

    Matrix<double, 3> cube {grid_nx, grid_ny, grid_nz};
    c = 0;
    
    cube.apply([](double& a){ a = c++; });

    print_3d(cube);

    return 0;
}
