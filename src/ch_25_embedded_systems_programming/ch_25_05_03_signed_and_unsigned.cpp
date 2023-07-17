// program demonstrates potential issues that may occur with signed and
// unsigned integers

#include <iostream> // for cout
#include <vector> // for vector

// function template that writes an argument of type T to stdout
template<typename T>
void print(T i)
{
    std::cout << i << '\t';
}

// overload of print() for char
inline void print(char i)
{
    std::cout << int(i) << '\t';
}

// overload of print() for signed char
inline void print(signed char i)
{
    std::cout << int(i) << '\t';
}

// overload of print() for unsigned char
inline void print(unsigned char i)
{
    std::cout << int(i) << '\t';
}

int main()
{
    using std::vector;
    using std::cout;
    
    vector<int> v(5);

    // beware mixing signed and unsigned types
    for (int i = 0; i < v.size(); i++)
        cout << i << ' ';
    cout << '\n';

    // NOTE: to avoid mixing types, use a containers built in size_type member
    for (vector<int>::size_type i = 0; i < v.size(); i++)
        cout << i << ' ';
    cout << '\n';

    // explicityly initialize iterator
    for(vector<int>::iterator p = v.begin(); p != v.end(); ++p)
        cout << p - v.begin() << ' ';
    cout << '\n';

    // let complier deduce iterator type
    for (auto p = v.begin(); p != v.end(); ++p)
        cout << p - v.begin() << ' ';
    cout << '\n';

    {
        unsigned int ui = -1; // whoops!
        int si = ui;
        int si2 = ui + 2;

        cout << ui << '\n'; // 4,294,967,295 UINT_MAX
        cout << si << '\n'; // -1
        cout << si2 << '\n'; // 1
    }
    cout << '\n';

    int si = 257; // too large for a char
    char c = si; // implicit conversion to char
    unsigned char uc = si;
    signed char sc = si;
    print(si); // 257
    print(c); // 1
    print(uc); // 1
    print(sc); // 1
    cout << "\n\n";

    si = 129; // too large for a signed char
    c = si;
    uc = si;
    sc = si;
    print(si); // 129
    print(c); // -127
    print(uc); // 129
    print(sc); // -127
    cout << "\n\n";

    return 0;
}
