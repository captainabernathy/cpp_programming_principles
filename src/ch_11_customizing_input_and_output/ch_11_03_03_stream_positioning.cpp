// program demonstrates how to read and write to various positions in a file

#include <iostream> // for cout, cerr
#include <string> // for string
#include <fstream> // for fstream
#include <exception> // for exception
#include <cpp_facilities/std_lib_facilities.hpp> // for error()

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::string;
        using std::fstream;
        using std::cout;

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

        cout << "character 6 is " << ch << '(' << int(ch) << ')' << '\n';

        fs.seekg(1); // set position in input sequence
        fs >> ch; // read from fs into ch
        cout << "character 2 is " << ch << '(' << int(ch) << ')' << '\n';

        // move writing position... 'p' for put in seekp()
        fs.seekp(1);
        
        // write and increment writing position
        fs << 'y'; // write y to second position in fs
        
        char c;
        fs.seekg(1); // set position in input sequqnce
        fs >> c ;
        cout << "character 2 is now " << c << '(' << int(c) << ')' << '\n';

        fs.seekp(1); // set position in output sequence
        fs << ch; // write ch to fs

        return 0;
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
