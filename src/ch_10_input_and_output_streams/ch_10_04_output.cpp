// program implements a Point structure with overloaded input and output
// operators. then it writes a vector of points to an output file

#include <iostream> // I/O library header
#include <fstream> // file I/O library
#include <string> // string library header
#include <vector> // vector library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.h" // project header containing header functions
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
        cout << "Please enter name of output file: ";

        string name;
        cin >> name; // file to write to

        // create an output file stream object to write to the file
        ofstream ost(name.c_str());

        if (!ost) // test if file was successfully opened for writing
            error("can't open file", name);

        vector<Point> points; // data to write to file

        for (int i = 0; i < 10; i++)
        {
            Point p{i, i * i}; // create a point
            points.push_back(p); // write it to vector
        }

        // write each point in the points vector to the file
        for (size_t i = 0; i < points.size(); i++)
            ost << '(' << points[i].x << ',' << points[i].y << ')' << endl;
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
