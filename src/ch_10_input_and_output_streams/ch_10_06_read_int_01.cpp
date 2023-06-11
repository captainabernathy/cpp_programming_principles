// program implements a function that reads integers from an input stream into
// a vector

#include <ios> // for ios_base
#include <istream> // for istream
#include <iostream> // for cin, cout, cerr
#include <vector> // for vector
#include <exception> // for exception

// reads integers from input stream ist into integer vector v until reaching
// eof() or terminator
void fill_vector(std::istream& ist, std::vector<int>& v, char terminator);

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::cin;
        using std::ios_base;
        using std::vector;
        using std::cout;

        // make cin throw if it goes bad anytime it goes bad
        cin.exceptions(cin.exceptions()|ios_base::badbit);

        vector<int> v; // vector to fill

        // fill v with integers read from cin until reading '*'
        fill_vector(cin, v, '*');

        // write each integer in v to stdout
        for (auto it : v)
            cout << it << ' ';
        cout << '\n';
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}

void fill_vector(std::istream& ist, std::vector<int>& v, char terminator)
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
        ist.clear(std::ios_base::failbit); // set state to fail()
    }
}
