// program demonstrates the relationship between the size and precision of 
// integer and floating point types... and why care must be taken when using
// them

#include <iostream> // for cout
#include <iomanip> // for setprecision()

int main()
{
    using std::cout;
    using std::setprecision;

    {
        float x = 1.0 / 333;
        float sum = 0.;

        for (int i = 0; i < 333; i++)
            sum += x;

        // rounding error visible
        cout << setprecision(15) << sum << "\n\n"; // 0.999...197
    }

    {
        short y = 40000; // beyond range of 16-bit signed short
        int i = 1000000; // i * i is beyond the range of a 32-bit signed int
        cout << y << "  " << i * i << "\n\n"; // -25536  -727379968
    }

    {
        cout << "sizes (int, float): " << sizeof(int) << ' ' << sizeof(float)
            << '\n';

        int x = 2100000009;
        float f = x; // float will not be able to represent x exactly... when
                     // sizeof(int) == sizeof(float)

        cout << x << ' ' << f << '\n'; // 2100000009 2100000000

        // 2100000009 2100000000
        cout << setprecision(15) << x << ' ' << f << "\n\n";
    }

    {
        float f = 2.8;
        int x = f; // x loses precision
        cout << x << ' ' << f << '\n'; // 2 2.8
    }

    return 0;
}
