// program demonstrates how to use input and output stream object to read from
// and write to binary files
// program also implements a template function to get the address of the
// the first byte of an object's representation

#include <iostream> // I/O library header
#include <fstream> // file I/O library
#include <string> // string library header
#include <vector> // vector library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.hpp" // project header containing helper functions
using namespace std;  // add names from std namespace to global namespace

// template function that gets the address of the first byte of an object's
// representation
template<typename T>
char *as_bytes(T& i) // treat T as a sequence of bytes
{
    // get the address of the first byte of memory used to store object
    void *addr = &i;

    return static_cast<char *>(addr); // treat that memory as bytes
}

int main()
{
    try
    {
        // open istream for binary input from a file
        cout << "Please enter input file name: ";
        string name;
        cin >> name;

        // open file for reading in binary mode
        ifstream ifs {name, ios_base::binary}; // binary mode
        if (!ifs) // stream in bad state
            error("can't open input file ", name);

        // open an ostream for binary output from a file
        cout << "Please enter output file name: ";
        cin >> name;

        // open file for output in binary mode
        ofstream ofs {name, ios_base::binary}; // binary mode
        if (!ofs) // stream in bad state
            error("can't open output file ", name);

        vector<int> v; // to store data read

        // read from binary file
        int i;
        // read file as bytes
        while (ifs.read(as_bytes(i), sizeof(int)))
            v.push_back(i); // write results to v

        // ... do something with v ...

        // write to binary file
        for (size_t i = 0; i < v.size(); i++)
            ofs.write(as_bytes(v[i]), sizeof(int)); // write bytes to file

        return 0;
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "Oops: unknown exception!" << endl;
        return 2;
    }
}
