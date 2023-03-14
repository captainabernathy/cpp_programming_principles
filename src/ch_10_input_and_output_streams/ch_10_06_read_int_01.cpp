// program implements a function that reads integers from an input stream into
// a vector

#include <iostream> // I/O library header
#include <string> // string library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include <vector> // vector library header
#include <fstream> // file I/O library
using namespace std;  // add names from std namespace to global namespace

// reads integers from input stream ist into integer vector v until reaching
// eof() or terminator
void fill_vector(istream& ist, vector<int>& v, char terminator);

int main()
{
    try
    {
        // make cin throw if it goes bad anytime it goes bad
        cin.exceptions(cin.exceptions()|ios_base::badbit);

        vector<int> v; // vector to fill

        // fill v with integers read from cin until reading '*'
        fill_vector(cin, v, '*');

        // write each integer in v to stdout
        for (auto it : v)
            cout << it << ' ';
        cout << endl;
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }
}

void fill_vector(istream& ist, vector<int>& v, char terminator)
{
    int i = 0; // variable to read from ist into
    while (ist >> i)
        v.push_back(i); // write integers read into i from ist to v

    if (ist.eof()) // test if at end of file
        return;

    // not good(), not bad(), and not eof()... ist must be fail()
    ist.clear(); // clear stream state... clear stream flags
    
    char c;
    ist >> c;  // read a character... hopefully a terminator

    if (c != terminator) // not the terminator, so fail
    {
        ist.unget(); // put charcter back into ist
        ist.clear(ios_base::failbit); // set state to fail()
    }
}
