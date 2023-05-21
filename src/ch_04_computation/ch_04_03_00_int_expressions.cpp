// program demonstrates various integer expressions and operations

#include <iostream> // for cout

int main()
{
    using std::cout;

    int len = 20; // initializationa via literal
    cout << len << '\n'; // 20
 
    int width = 40; // initialization via literal
    cout << width << '\n'; // 40

    int area = len * width;  // initialization via multiplication expression
    cout << area << '\n'; // 800

    len = 99; // assignment
    cout << len << '\n'; // 99

    {
        // parentheses have higher precedence than multiplication
        int perimeter = (len + width) * 2;
        cout << perimeter << '\n'; // 278
    }

    {
        int perimeter = len * 2 + width * 2; // same result as above
        cout << perimeter << '\n'; // 278
    }

    {
        // multiplication has higher precedence than addition
        int perimeter = len + width * 2;
        cout << perimeter << '\n'; // 179
    }

    return 0;
}
