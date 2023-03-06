// program demonstrates various integer expressions and operations

#include <iostream> // I/O library header
using namespace std; // add names from std namespace to global namespace

int main()
{
    int len = 20; // initializationa via literal
    cout << len << endl; // 20
 
    int width = 40; // initialization via literal
    cout << width << endl; // 40

    int area = len * width;  // initialization via multiplication expression
    cout << area << endl; // 800

    len = 99; // assignment
    cout << len << endl; // 99

    {
        // parentheses have higher precedence than multiplication
        int perimeter = (len + width) * 2;
        cout << perimeter << endl; // 278
    }

    {
        int perimeter = len * 2 + width * 2; // same result as above
        cout << perimeter << endl; // 278
    }

    {
        // multiplication has higher precedence than addition
        int perimeter = len + width * 2;
        cout << perimeter << endl; // 179
    }

    return 0;
}
