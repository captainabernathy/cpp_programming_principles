// program demonstrates how to use input and output stream objects to read from
// and write to binary files
//
// program also tests the function template as_bytes<>() to get the address of
// the the first byte of an object's representation
//
// template<typename T>
// char *as_bytes(T& i)

#include <ios> // for ios_base
#include <iostream> // for cin, cout, cerr
#include <string> // for string
#include <fstream> // for ifstream, ofstream
#include <vector> // for vector
#include <exception> // for exception
#include <mem_utils/mem_utils.hpp> // for as_bytes<>()
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::cout;
        using std::string;
        using std::cin;
        using std::ifstream;
        using std::ios_base;
        using std::ofstream;
        using std::vector;

        // open istream for binary input from a file
        cout << "Please enter input file name: "; // infile.bin
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
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Oops: unknown exception!\n";
        return 2;
    }

    return 0;
}
