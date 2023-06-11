// program tests the implementation of the Point class's overloaded output
// operator by writing a vector of Points to a file
//
// Point (class)
//      Point(int xi = 0, yi = 0)
//
// istream& operator>>(istream& ist, Point& p)
// ostream& operator<<(ostream& ost, Point const& p)

#include <iostream> // for cin, cout, cerr
#include <string> // for string
#include <fstream> // for ofstream
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
        using std::ofstream;
        using std::vector;

        cout << "Please enter name of output file: "; // points_outfile.txt
        string name;
        cin >> name; // file to write to

        // create an output file stream object to write to the file
        ofstream ost {name.c_str()};

        if (!ost) // test if file was successfully opened for writing
            error("can't open file", name);

        vector<Point> points; // data to write to file

        for (int i = 0; i < 10; i++)
        {
            // Point p {i, i * i}; // create a point
            // points.push_back(p); // write it to vector
            points.push_back({i, i * i}); // write Point to vector
        }

        // write each point in the points vector to the file
        for (size_t i = 0; i < points.size(); i++)
            // ost << '(' << points[i].x << ',' << points[i].y << ')' << '\n';
            ost << points[i] << '\n';
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
