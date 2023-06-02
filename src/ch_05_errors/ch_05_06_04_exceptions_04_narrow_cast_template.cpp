// program demonstrates the use of a template class to evaluate type
// conversions that may result in loss of data
// NOTE: implementation of narrow_cast<> template located in
// std_lib_facilities header

#include <iostream> // for cerr, cout
#include <exception> // for exception
#include <cpp_facilities/std_lib_facilities.hpp> // for narrow_cast<>

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::cout;

        int x = 2.9; // truncated to 2
        cout << x << '\n';
    
        char c = 2000; // cannot be represented by a char
        cout << c << '\n';

        // NOTE: narrow_cast template provided by std_lib_facilities.h
        // narrow_cast produces a new type of the desired target if its source
        // operand does not change value upon conversion
        int x1 = narrow_cast<int>(2.9); // error due to truncation of 2.9
        cout << x1 << '\n';

        int x2 = narrow_cast<int>(2.0); // cast ok
        cout << x2 << '\n';

        int c1 = narrow_cast<char>(2000); // error char cannot express 2000
        cout << c1 << '\n';

        char c2 = narrow_cast<int>(85); // ok chan can represent 85
        cout << c2 << '\n';
    }
    catch (exception &ex) // catches checked exceptions
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...) // catches unchecked exceptions
    {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }

    return 0;
}
