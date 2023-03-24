// program implements a Point structure with overloaded input and output
// operators. then it reads points from a file and writes them to stdout

#include <iostream> // I/O library header
#include <fstream> // file I/O library
#include <string> // string library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include <vector> // vector library header
#include "std_lib_facilities.hpp" // project header containing helper functions
using namespace std;  // add names from std namespace to global namespace

// user-define Point type
struct Point {
    int x; // x coordinate
    int y; // y coordinate

    // overloaded input operator for a Point
    // function reads a formated Point "(x,y)" into an input stream
    friend istream& operator>>(istream& ist, Point& p)
    {
        char a; // '('
        char b; // ','
        char c; // ')'

        if ((ist >> a >> p.x >> b >> p.y >> c)
            && !(a == '(' && b == ',' && c == ')'))
            throw runtime_error("Invalid format");

        return ist;
    }

    // overloaded output operator for a Point
    // function formats and writes a Point "(x,y)" to an output stream
    friend ostream& operator<<(ostream& ost, const Point& p)
    {
        return ost << '(' << p.x << ',' << p.y << ')' << endl;
    }
};

int main()
{
    try
    {
        cout << "Please enter input file name: ";
        string name;
        cin >> name; // read file name

        // create an input file stream object to read the file
        ifstream ist(name.c_str());

        if (!ist) // test if file was opened
            error("can't open input file ", name);

        vector<Point> points; // to store data from file
        Point p; // to read a each point in the file

        // read each point in the file and write it to the vector points
        while (ist >> p)
            points.push_back(p);

        // write each point read from the file to stdout
        for (auto it: points)
            cout << it;
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

    return 0;
}
