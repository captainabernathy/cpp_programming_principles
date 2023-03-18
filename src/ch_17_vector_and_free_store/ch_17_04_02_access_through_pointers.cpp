// program demonstrates how to access elements through poiners using the
// dereference operator

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

int main()
{
    double *p = new double[4]; // dynamically allocate an array of  4 doubles
    for (int i = 0; i < 4; i++)
        p[i] = 1.1 + i;
    for (int i = 0; i < 4; i++)
        cout << "p[" << i << "]: " << p[i] << endl; // 1.1 2.1 3.1 4.1
    cout << endl;

    double x = *p; // read value of first double pointed to by p (p[0]) into x
    cout << "x: " << x << endl; // 1.1

    double y = p[2]; // read third double pointed to by p into y
    cout << "y: " << y << endl; // 3.1

    *p = 7.7; // overwrite the value of the first double in p (p[0])
    cout << "*p: " << *p << endl; // 7.7

    p[2] = 9.9; // overwrite the value of the third double in p
    cout << "p[2]: " << p[2] << endl << endl; // 9.9

    {
        double x = *p; // write value of first double p points to, to x
        cout << "x: " << x << endl; // 7.7
        *p = 8.8; // overwrite value of the first double p points to
        cout << "x: " << x << " *p: " << *p << endl << endl; // 7.7 8.8
    }

    {
        double x = p[3]; // write value of fourth double p points to, to x
        cout << "x: " << x << endl; // 4.1
        p[3] = 4.4; // overwrite value of the fourth double p points to
        cout << "x: " << x << " p[3]: " << p[3] << endl; // 4.1 4.4
    }

    delete[] p;  // release memory allocated for p

    return 0;
}
