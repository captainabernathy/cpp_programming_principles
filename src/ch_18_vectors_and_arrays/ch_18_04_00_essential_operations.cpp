// program demonstrates some of the essential operations provided by the
// standard library's string and vector classes
//
// NOTE: the term "essential operations" refers to the following 7 operations:
// 1) Constructors from one or more arguments
// 2) Default constructor (no-arguments)
// 3) Copy constructor
// 4) Copy assignment
// 5) Move constructor
// 6) Move assignment
// 7) Destructor

#include <iostream> // I/O library header
#include <string> // string library header
#include <vector> // vector library header
using namespace std;  // add names from std namespace to global namespace

int main()
{
    string s("Triumph"); // copy constructor
    vector<double> vd(10); // fill constructor... 10 doubles to default 0.0
    vector<string> vs(10); // fill constructor... 10 empty strings

    // vector of 10 int vectors initialized to vector()
    vector<vector<int>> vvi(10);
    vvi[0].push_back(4);
    vvi[0].push_back(2);

    cout << "s.size(): " << s.size() << endl  // 7
         << "vd.size(): " << vd.size() << endl // 10
         << "vs.size(): " << vs.size() << endl //  10
         << "vvi.size(): " << vvi.size() << endl // 10
         << "vvi[0].size(): " << vvi[0].size() << endl; // 2
    cout<< vvi[0][0] << " " << vvi[0][1] << endl; // 4 2

    return 0;
}