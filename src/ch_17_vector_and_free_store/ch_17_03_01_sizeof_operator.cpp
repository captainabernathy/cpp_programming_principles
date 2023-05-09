// program demonstrates use of the sizeof() operator

#include <iostream> // I/O library header
#include <vector> // vector library header

int main()
{
    using std::cout;
    using std::vector;

    // sizeof() operator... values may differ across platforms
    cout << "sizeof(char): " << sizeof(char) << '\n'; // 1
    cout << "sizeof('a'): " << sizeof('a') << '\n'; // 1
    cout << "sizeof(int): " << sizeof(int) << '\n'; // 4
    cout << "sizeof(2+2): " << sizeof(2 + 2) << '\n'; // 4

    int *p = nullptr;

    cout << "sizeof(int *): " << sizeof(int *) << '\n'; // 8
    cout << "sizeof(p): " << sizeof(p) << '\n'; // 8

    vector<int> v(1000);

    cout << "sizeof(vector<int>): " << sizeof(vector<int>) << '\n'; // 24
    cout << "sizeof(v): " << sizeof(v) << '\n'; // 24

    return 0;
}
