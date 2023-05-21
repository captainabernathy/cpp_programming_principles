// program demonstrates how to use input, output, and file stream objects to
// open files for reading and writing

#include <fstream> // for ofstream, ifstream, fstream
#include <iostream> // for cerr, ios_base

int main()
{
    using std::ofstream;
    using std::ifstream;
    using std::fstream;
    using std::cerr;
    using std::ios_base;

    // NOTE: when an attempt is made to open a previously non-existent file
    // for reading, the operating system will crate an empty file with the
    // specified name... HOWEVER, when an attempt to read from a non-existent
    // file is made, the operating system will NOT create a file of that name
    // AND the stream will be left in a bad state
    const char *name = "myfile0";
    const char *name1 = "myfile1";
    const char *name2 = "myfile2";

    // open/create file for writing
    ofstream of1 {name1}; // defaults to ios_base::out
    
    // open file for reading
    ifstream if1 {name2}; // defaults to ios_base::in

    // open file for writing in append mode
    ofstream ofs {name, ios_base::app}; // append mode
    
    // open file for reading and writing
    fstream fs {"myfile", ios_base::in|ios_base::out}; // both in and out

    if (!fs) // stream in bad state
    {
        // couldn't open file
        cerr << "could not open file" << '\n';
    }

    // open file for reading
    ifstream ifs {"readings"};
    if (!ifs) // stream in bad state
    {
        // couldn't open "readings" for reading
        cerr << "failed to open file: \"readings\" for reading" << '\n';
    }

    {
        ofstream ofs {"no-such-file"}; // creates new file
        ifstream ifs {"no-file-of-this-name"}; // error!!! file must exist

        if (!ifs)
            cerr << "failed to open file: \"no-file-of-this-name\" for reading"
                << '\n';
    }

    return 0;
}
