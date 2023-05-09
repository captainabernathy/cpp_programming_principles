// program demonstrates the use of block scope as well as various variable
// initialization and assignment statements

#include <iostream> // I/O library header
#include <string> // string library header

int main()
{
    using std::cout;
    using std::string;

    //names restricted to scope of {  }
    {
        int a = 3; // initialize a to 3
        cout << a << '\n'; // 3

        a = 4; // assign 4 to a
        cout << a << '\n'; // 4

        int b = a; // initialize b with value in a
        cout << b << '\n'; // 4
    }

    {
        string a = "alpha";
        cout << a << '\n'; // alpha

        string b = a; // initialize b with value in a
        cout << b << '\n'; // alpha

        b = a + "gamma"; // assign result of concatenating a and "gamma" to b
        cout << b << '\n'; // alphagamma

        a = a + "delta"; // assign result of concatenating a and "delta" to a
        cout << a << '\n';
    }

    {
        int y = 8; // initialize y to 8
        cout << y << '\n'; // 8

        int x; // declare x
        x = 9; // assign 9 to x
        cout << x << '\n'; // 9

        string t = "howdy"; // initialize t to "howdy"
        cout << t << '\n'; // howdy

        string s; // declare s
        s = "G'day"; // assign "G'day" to s
        cout << s << '\n'; // G'day
    }

    return 0;
}
