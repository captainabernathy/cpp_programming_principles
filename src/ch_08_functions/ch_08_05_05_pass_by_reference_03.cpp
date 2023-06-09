// program implements a function that swaps two doubles using pass by reference

#include <iostream> // for cout

// function receives two doubles by references and swaps their values
inline void swap(double& d1, double& d2)
{
    double temp = d1;
    d1 = d2;
    d2 = temp;
}

int main()
{
    using std::cout;

    double x = 1;
    double y = 2;
    cout << "x == " << x << " y == " << y << '\n'; // 1, 2
    swap(x, y); // swaps x and y by reference
    cout << "x == " << x << " y == " << y << '\n'; // 2, 1

    return 0;
}
