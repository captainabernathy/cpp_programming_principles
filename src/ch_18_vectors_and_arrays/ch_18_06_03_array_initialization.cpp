// program demonstrates various techniques for initializing an array

#include <iostream> // I/O library header

// simple string length function that returns the number of characters in its
// input
size_t strlen(const char *p);

int main()
{
    using std::cout;

    char ac[] = "Beron"; // array of 6 chars... includes \0
    
    // NOTE: this may issue a warning since ISO C++ forbids converting a string
    // const to a char *
    char *pc = "Howdy"; // pointier to an array of 6 chars... includes \0
    
    int ai[] = {1, 2, 3, 4, 5, 6}; // array of 6 ints
    
    int ai2[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // last 90 elem = 0
    
    double ad[100] = {  }; // all elems initialized to 0.0
    
    char chars[] = {'a', 'b', 'c'}; // array of 3 chars... no terminal '\0'
    
    // array of 6 characters
    char c2[] = {'a', 'a', 'r', 'o', 'n', '\0' };

    cout << ac << " " << strlen(ac) << '\n'; // 5
    cout << pc << " " << strlen(pc) << '\n'; // 5
    cout << c2 << " " << strlen(c2) << '\n'; // 5
    cout << '\n';

    for (int i = 0; i < 3; i++)
        cout << chars[i] << ' ';
    cout << '\n';

    for (int i = 0; i < 6; i++)
        cout << ai[i] << ' ';
    cout << '\n';

    for (int i = 0; i < 10; i++)
        cout << ai2[i] << ' ';
    cout << '\n';

    return 0;
}

size_t strlen(const char *p)
{
    size_t n = 0;
    while (p[n])
        n++;
    return n;
}
