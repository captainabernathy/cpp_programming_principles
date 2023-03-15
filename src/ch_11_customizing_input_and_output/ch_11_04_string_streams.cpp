// program demonstrates to use string streams to read from and write to input
// and output streams

#include <iostream> // I/O library header
#include <string> // string library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include <fstream> // file I/O library
#include <sstream> // provides stream classes for operating on strings
#include "std_lib_facilities.h" // project header containing header functions
using namespace std;  // add names from std namespace to global namespace

// function that converts the characters in s to a double and returns it
double str_to_double(string s);

// testing function for str_to_double()
void test();

int main()
{
    try
    {
        test(); // test str_to_double()

        // ostringstream stores characters written to it in a string
        ostringstream name;
        name << "myfile" << 17;
        
        // ostringsream's str() member function returns the string that was
        // composed by the output operations on it
        cout << name.str() << endl; // myfile17

        // create file myfile17
        ofstream logfile {name.str()};

        logfile << "this is some stuff" << endl; // write to logfile
    }
    catch (exception &ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "error: unknown" << endl;
        return 2;
    }
}

double str_to_double(string s)
{
    istringstream is {s}; // create a string stream to read from s
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
        cout << d1 << " " << d2 << endl;
    }
    catch (exception &ex)
    {
        cerr << "error: " << ex.what() << endl;
    }
    catch (...)
    {
        cerr << "error: unknown" << endl;
    }
}
