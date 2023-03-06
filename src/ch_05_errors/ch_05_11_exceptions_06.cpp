// program provides scaffolding for testing code

#include <iostream> // I/O library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
using namespace std;  // add names from std namespace to global namespace

inline void keep_window_open()
{
    cin.get();
}

int main()
{
    try
    {
        // test code here...

        cout << "Enter an key to exit: ";
        keep_window_open();
        return 0;
    }
    catch (exception& ex) // catches checked exceptions
    {
        cerr << "error: " << ex.what() << endl;
        cout << "Enter an key to exit: ";
        keep_window_open();
        return 1;
    }
    catch (...) // catches unchecked exceptions
    {
        cerr << "Oops: unknown exception!" << endl;
        cout << "Enter an key to exit: ";
        keep_window_open();
        return 2;
    }

    return 0;
}
