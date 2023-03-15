// program demonstrates how to read and write to various positions in a file

#include <iostream> // I/O library header
#include <string> // string library header
#include <fstream> // file I/O library
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.h" // project header containing header functions
using namespace std;  // add names from std namespace to global namespace

int main()
{
    try
    {
        string name = "positioning.txt";
        // NOTE: an fstream's ios_base::openmode argument is set by default to
        // ios_base::in|ios_base::out
        fstream fs {name}; // open file for input and output

        if (!fs) // stream in bad state
            error("can't open ", name);

        // move reading position... 'g' for get in seekg()
        fs.seekg(5); // get 6th character

        // read and increment reading position
        char ch;
        fs >> ch; // read charcter in fs into ch

        cout << "character 6 is " << ch << '(' << int(ch) << ')' << endl;

        fs.seekg(1); // set position in input sequence
        fs >> ch; // read from fs into ch
        cout << "character 2 is " << ch << '(' << int(ch) << ')' << endl;

        // move writing position... 'p' for put in seekp()
        fs.seekp(1);
        
        // write and increment writing position
        fs << 'y'; // write y to second position in fs
        
        char c;
        fs.seekg(1); // set position in input sequqnce
        fs >> c ;
        cout << "character 2 is now " << c << '(' << int(c) << ')' << endl;

        fs.seekp(1); // set position in output sequence
        fs << ch; // write ch to fs

        return 0;
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
