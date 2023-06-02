// program provides an introduction to pointers, pointer initialization and
// dereferencing

#include <iostream> // for cout

int main()
{
    using std::cout;

    int var = 17;
    int *ptr = &var; // initialize pointer ptr to address of var

    cout << "var: " << var << '\n'; // 17
    cout << "*ptr: " << *ptr << "\n\n"; // 17

    char ch = 'c';
    char *pc = &ch; // initialize pointer pc to address of ch

    cout << "ch: " << ch << '\n'; // c
    cout << "*pc: " << *pc << "\n\n"; // c

    int ii = 17;
    int *pi = &ii; // initialize pointer pi to address of ii

    cout << "ii: " << ii << '\n'; // 17
    cout << "*pi: " << *pi << "\n\n"; // 17

    *pc = 'x'; // ok... changes value of ch... the variable pc points to
    *pi = 27; // ok... changes value of ii... the variable pi points to

    cout << "ch: " << ch << '\n'; // x
    cout << "*pc: " << *pc << "\n\n"; // x
    cout << "ii: " << ii << '\n';  // 27
    cout << "*pi: " << *pi << "\n\n"; // 27

    *pi = *pc; // ok to assign a char to an int

    cout << "ch: " << ch << '\n'; // x
    cout << "*pc: " << *pc << "\n\n"; // x
    cout << "ii: " << ii << '\n'; // 120... acii value of x
    cout << "*pi: " << *pi << "\n\n"; // 120... ascii value of x

    {
        char ch1 = 'a';
        char ch2 = 'b';
        char ch3 = 'c';
        char ch4 = 'd';

        // int *iptr = &ch3; // can't convert char* to int*
        cout << "ch1: " << ch1 << " ch2: " << ch2 << " ch3: " << ch3
            << " ch4: " << ch4 << "\n\n";  // a b c d

        *pi = 12345; // changes ii... the varaible pi points to

        cout << "ii: " << ii << '\n'; // 12345
        cout << "*pi: " << *pi << "\n\n"; // 12345

        *pi = 67890; // changes ii... the variable pi points to

        cout << "ii: " << ii << '\n'; // 67890
        cout << "*pi: " << *pi << "\n\n"; // 67890
    }

    return 0;
}
