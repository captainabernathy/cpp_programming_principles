// program provides an introduction to pointers, pointer initialization and
// dereferencing
#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

int main()
{
    int var = 17;
    int *ptr = &var; // initialize pointer ptr to address of var
    cout << "var: " << var << endl; // 17
    cout << "*ptr: " << *ptr << endl << endl; // 17

    char ch = 'c';
    char *pc = &ch; // initialize pointer pc to address of ch
    cout << "ch: " << ch << endl; // c
    cout << "*pc: " << *pc << endl << endl; // c

    int ii = 17;
    int *pi = &ii; // initialize pointer pi to address of ii
    cout << "ii: " << ii << endl; // 17
    cout << "*pi: " << *pi << endl << endl; // 17

    *pc = 'x'; // ok... changes value of ch... the variable pc points to
    *pi = 27; // ok... changes value of ii... the variable pi points to
    cout << "ch: " << ch << endl; // x
    cout << "*pc: " << *pc << endl << endl; // x
    cout << "ii: " << ii << endl;  // 27
    cout << "*pi: " << *pi << endl << endl; // 27

    *pi = *pc; // ok to assign a char to an int
    cout << "ch: " << ch << endl; // x
    cout << "*pc: " << *pc << endl << endl; // x
    cout << "ii: " << ii << endl; // 120... acii value of x
    cout << "*pi: " << *pi << endl << endl; // 120... ascii value of x

    {
        char ch1 = 'a';
        char ch2 = 'b';
        char ch3 = 'c';
        char ch4 = 'd';
        // int *iptr = &ch3; // can't convert char* to int*
        cout << "ch1: " << ch1 << " ch2: " << ch2 << " ch3: " << ch3 << " ch4: "
            << ch4 << endl << endl;  // a b c d

        *pi = 12345; // changes ii... the varaible pi points to
        cout << "ii: " << ii << endl; // 12345
        cout << "*pi: " << *pi << endl << endl; // 12345

        *pi = 67890; // changes ii... the variable pi points to
        cout << "ii: " << ii << endl; // 67890
        cout << "*pi: " << *pi << endl << endl; // 67890
    }

    return 0;
}
