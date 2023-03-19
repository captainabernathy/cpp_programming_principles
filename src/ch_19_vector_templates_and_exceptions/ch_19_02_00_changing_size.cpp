// program performs various operations on a vector to illustrate the
// relationship between size and capacity

#include <iostream> // I/O library header
#include <vector> // vector library header

using namespace std;

// function outputs vector v's size and capacity, prepended by string s
void print_info(vector<double> const& v, string const& s);

int main()
{
    int n = 100;
    vector<double> v(n); // v's size and capacity are 100
    print_info(v, "v"); // 100, 100
    cout << endl;

    v.resize(10); // v's size is 10 and capacity is 100
    cout << "after v.resize(10)..." << endl;
    print_info(v, "v"); // 10, 100
    cout << endl;

    v.push_back(7); // increases size by 1... v's size is 11 and capacity is 100
    cout << "after v.push_back(7)..." << endl;
    print_info(v, "v"); // 11, 100
    cout << endl;

    vector<double> v2(7); // v2's size and capacity are 7
    print_info(v2, "v2"); // 7, 7
    cout << endl;

    v = v2; // v's size is now 7 but it's capacity is still 100
    cout << "after v = v2..." << endl;
    print_info(v, "v"); // 7, 100

    return 0;
}

void print_info(vector<double> const& v, string const& s)
{
    cout << s << ".size(): " << v.size() << endl;
    cout << s << ".capacity(): " << v.capacity() << endl;
}
