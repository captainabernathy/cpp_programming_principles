// program provides an introduction to dynamic memory allocation and
// deallocatoin using the new and delete operators, respectively

#include <iostream> // for cout

int main()
{
    using std::cout;

    int n = 7;
    int *pi = new int; // dynamically allocate one int
    *pi = n + 2;

    cout << "n: " << n << " *pi: " << *pi << "\n\n"; // 7 9

    int *qi = new int[4]; // dynamically allocate an array of 4 ints
    for (int i = 0; i < 4; i++)
        qi[i] = i + 1;

    for (int i = 0; i < 4; i++)
        cout << "qi[" << i << "]: " << qi[i] << '\n';  // 1 2 3 4
    cout << '\n';

    double *pd = new double; // dynamically allocate a double
    *pd = 8.8;

    cout << "*pd: " << *pd << '\n'; // 8.8

    double *qd = new double[n]; // dynamically allocate an array of 7 doubles
    for (int i = 0; i < n; i++)
        qd[i] = 1.1 + i;

    for (int i = 0; i < n; i++)
        cout << "qd[" << i << "]: " << qd[i] << '\n';  // 1.1 ... 7.1
    cout << '\n';

    // NOTE: the name of an array is a pointer to the address of the first
    // element it contains... ie: arr == &arr[0]
    // the address of an array is the address of the pointer assigned to it.
    // when dereferenced, this pointer points to the address of the first
    // element in the array... ie: *&arr == arr == &arr[0]
    cout << "sizeof(qi): " << sizeof(qi) << '\n'; // 8... address size
    cout << "sizeof(*qi): " << sizeof(*qi) << '\n'; // 4... integer size
    cout << "sizeof(&qi): " << sizeof(&qi) << '\n'; // 8... address size
    cout << "sizeof(qd): " << sizeof(qd) << '\n'; // 8... address size
    cout << "sizeof(*qd): " << sizeof(*qd) << '\n'; // 8... double size
    cout << "sizeof(&qd): " << sizeof(&qd) << '\n'; // 8... address size

    // release memeory for dynamically allocated variables
    delete pi;
    delete[] qi;
    delete pd;
    delete[] qd;

    return 0;
}
