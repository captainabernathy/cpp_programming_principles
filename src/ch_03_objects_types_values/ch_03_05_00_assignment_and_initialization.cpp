// program demonstrates the use of block scope as well as various variable
// initialization and assignment statements

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    //names restricted to scope of {  }
    {
        int a = 3; // initialize a to 3
        cout << a << endl; // 3

        a = 4; // assign 4 to a
        cout << a << endl; // 4

        int b = a; // initialize b with value in a
        cout << b << endl; // 4
    }

    {
        string a = "alpha";
        cout << a << endl; // alpha

        string b = a; // initialize b with value in a
        cout << b << endl; // alpha

        b = a + "gamma"; // assign result of concatenating a and "gamma" to b
        cout << b << endl; // alphagamma

        a = a + "delta"; // assign result of concatenating a and "delta" to a
        cout << a << endl;
    }

    {
        int y = 8; // initialize y to 8
        cout << y << endl; // 8

        int x; // declare x
        x = 9; // assign 9 to x
        cout << x << endl; // 9

        string t = "howdy"; // initialize t to "howdy"
        cout << t << endl; // howdy

        string s; // declare s
        s = "G'day"; // assign "G'day" to s
        cout << s << endl; // G'day
    }

    return 0;
}
