// program provides scaffolding for testing code

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors

inline void keep_window_open()
{
    std::cin.get();
}

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
        cerr << "Oops: unknown exception!" << '\n';
        cout << "Enter an key to exit: ";
        keep_window_open();
        return 2;
    }

    return 0;
}
