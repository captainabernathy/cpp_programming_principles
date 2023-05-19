// program demonstrates to use string streams to read from and write to input
// and output streams

#include <iostream> // I/O library header
#include <string> // string library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include <fstream> // file I/O library
#include <sstream> // provides stream classes for operating on strings
#include <cpp_facilities/std_lib_facilities.hpp> // project helper functions

// function that converts the characters in s to a double and returns it
double str_to_double(std::string s);

// testing function for str_to_double()
void test();

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::ostringstream;
        using std::cout;
        using std::ofstream;

        test(); // test str_to_double()

        // ostringstream stores characters written to it in a string
        ostringstream name;
        name << "myfile" << 17;
        
        // ostringsream's str() member function returns the string that was
        // composed by the output operations on it
        cout << name.str() << '\n'; // myfile17

        // create file myfile17
        ofstream logfile {name.str()};

        logfile << "this is some stuff" << '\n'; // write to logfile
    }
    catch (exception &ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "error: unknown" << '\n';
        return 2;
    }
}

double str_to_double(std::string s)
{
    std::istringstream is {s}; // create a string stream to read from s
    double d;
    is >> d; // read contents of s into d

    if (!is) // stream in bad state
        error("double format error: ", s);

    return d;
}

void test()
{
    try
    {
        // test str_to_double()
        double d1 = str_to_double("12.4");
        double d2 = str_to_double("1.34e-3");
        // double d3 = str_to_double("twelve point three"); // error
        // write results of test to stdout
        std::cout << d1 << " " << d2 << '\n';
    }
    catch (std::exception &ex)
    {
        std::cerr << "error: " << ex.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "error: unknown" << '\n';
    }
}
