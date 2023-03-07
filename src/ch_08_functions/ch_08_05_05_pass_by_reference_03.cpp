// program implements a function that swaps two doubles using pass by reference

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

// function receives two doubles by references and swaps their values
inline void swap(double& d1, double& d2)
{
    double temp = d1;
    d1 = d2;
    d2 = temp;
}

int main()
{
    double x = 1;
    double y = 2;
    cout << "x == " << x << " y == " << y << endl; // 1, 2
    swap(x, y); // swaps x and y by reference
    cout << "x == " << x << " y == " << y << endl; // 2, 1
    return 0;
}
