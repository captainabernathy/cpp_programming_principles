// program demonstrates how to read in a Matrix from a file

#include <iostream> // for cin, cout
#include <string> // for string
#include <fstream> // for ifstream
#include <numeric_utils/matrix_utils.hpp> // for Matrix<>
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

int main()
{
    using namespace Numeric_lib;
    using std::cout;
    using std::string;
    using std::cin;
    using std::ifstream;

    cout << "Please enter input file name: "; // matrix_infile.txt
    string name;
    cin >> name; // read file name

    ifstream ist {name.c_str()};

    if (!ist)
        error("failed to open file ", name);

    Matrix<double> a {4};

    // a 1D Matrix of doubles from ist into a
    ist >> a;

    Matrix<int, 2> m(2, 2);

    // read a 2x2 Matrix of ints from ist into m
    ist >> m;

    ist.close(); // close input file stream

    // output the Matrix a and m
    cout << a << "\n\n";
    cout << m << "\n\n";

    return 0;
}
