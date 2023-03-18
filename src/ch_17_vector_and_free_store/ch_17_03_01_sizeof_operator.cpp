// program demonstrates use of the sizeof() operator

#include <iostream> // I/O library header
#include <vector> // vector library header
using namespace std;  // add names from std namespace to global namespace

int main()
{
    // sizeof() operator... values may differ across platforms
    cout << "sizeof(char): " << sizeof(char) << endl; // 1
    cout << "sizeof(\'a\'): " << sizeof('a') << endl; // 1
    cout << "sizeof(int): " << sizeof(int) << endl; // 4
    cout << "sizeof(2+2): " << sizeof(2 + 2) << endl; // 4

    int *p = nullptr;
    cout << "sizeof(int *): " << sizeof(int *) << endl; // 8
    cout << "sizeof(p): " << sizeof(p) << endl; // 8

    vector<int> v(1000);
    cout << "sizeof(vector<int>): " << sizeof(vector<int>) << endl; // 24
    cout << "sizeof(v): " << sizeof(v) << endl; // 24

    return 0;
}
