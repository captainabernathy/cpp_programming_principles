// program tests the implementation of the Point class's overloaded input and
// output operators by reading Points from from the file points_infile.txt and
// writing them to stdout
//
// Point (class)
//      Point(int xi = 0, yi = 0)
//
// istream& operator>>(istream& ist, Point& p)
// ostream& operator<<(ostream& ost, Point const& p)

#include <iostream> // for cin, cout, cerr
#include <string> // for string
#include <fstream> // for ifstream
#include <vector> // for vector
#include <exception> // for exception

// make Point I/O methods visible to syntax checkers
#ifndef POINT_IO
#define POINT_IO
#endif

#include <GUI/Point.hpp> // for Point
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
        using std::vector;

        cout << "Please enter input file name: "; // points_infile.txt
        string name;
        cin >> name; // read file name

        // create an input file stream object to read the file
        ifstream ist {name.c_str()};

        if (!ist) // test if file was opened
            error("can't open input file ", name);

        std::vector<Point> points; // to store data from file
        Point p; // to read a each point in the file

        // read each point in the file and write it to the vector points
        while (ist >> p)
            points.push_back(p);

        // write each point read from the file to stdout
        for (auto it: points)
            cout << it << '\n';
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
