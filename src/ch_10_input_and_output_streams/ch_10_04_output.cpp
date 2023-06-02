// program implements a Point class with overloaded input and output
// operators... then writes a vector of points to an output file

#include <istream> // for istream
#include <ostream> // for ostream
#include <iostream> // for cin, cout, cerr
#include <fstream> // for ofstream
#include <string> // for string
#include <vector> // for vector
#include <exception> // for exception
#include <stdexcept> // runtime_error
#include <cpp_facilities/std_lib_facilities.hpp> // error()

// user-define Point type
struct Point {
    int x; // x coordinate
    int y; // y coordinate

    // overloaded input operator for a Point
    // function reads a formated Point "(x,y)" into an input stream
    friend std::istream& operator>>(std::istream& ist, Point& p)
    {
        char a; // '('
        char b; // ','
        char c; // ')'

        if ((ist >> a >> p.x >> b >> p.y >> c)
            && !(a == '(' && b == ',' && c == ')'))
            throw std::runtime_error("Invalid format");

        return ist;
    }

    // overloaded output operator for a Point
    // function formats and writes a Point "(x,y)" to an output stream
    friend std::ostream& operator<<(std::ostream& ost, const Point& p)
    {
        return ost << '(' << p.x << ',' << p.y << ')';
    }
};

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

        cout << "Please enter name of output file: ";

        string name;
        cin >> name; // file to write to

        // create an output file stream object to write to the file
        ofstream ost {name.c_str()};

        if (!ost) // test if file was successfully opened for writing
            error("can't open file", name);

        vector<Point> points; // data to write to file

        for (int i = 0; i < 10; i++)
        {
            Point p {i, i * i}; // create a point
            points.push_back(p); // write it to vector
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
