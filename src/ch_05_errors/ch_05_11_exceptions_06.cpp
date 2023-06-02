// program provides scaffolding for testing code

#include <iostream> //  for cout, cerr
#include <exception> // for exception
#include <cpp_facilities/std_lib_facilities.hpp> // for keep_window_open()

int main()
{
    using std::cout;
    using std::exception;
    using std::cerr;

    try
    {
        using std::cout;
        // test code here...

        cout << "Enter an key to exit: ";
        keep_window_open();
        return 0;
    }
    catch (exception& ex) // catches checked exceptions
    {
        cerr << "error: " << ex.what() << '\n';
        cout << "Enter an key to exit: ";
        keep_window_open();
        return 1;
    }
    catch (...) // catches unchecked exceptions
    {
        cerr << "Oops: unknown exception!\n";
        cout << "Enter an key to exit: ";
        keep_window_open();
        return 2;
    }

    return 0;
}
