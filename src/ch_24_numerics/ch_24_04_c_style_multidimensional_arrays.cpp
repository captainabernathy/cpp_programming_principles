// program demonstrates how to use and manipulate multi-dimensional arrays

#include <iostream> // for cout

// function that initializes a 3x5 array of ints
void f1(int a[3][5]);

// function that initializes a dim1x5 array of ints
void f2(int a[][5], int dim1); // ok to omit the first dimension

// void f3(int [3][], int dim2); // invalid... only first may be omitted

// void f5(int [][], int dim1, int dim2); // again... only first may be omitted

// function that initializes a dim1xdim2 array of ints
void f5(int *m, int dim1, int dim2);

int main()
{
    using std::cout;

    int ai[5] = {1, 2, 3, 4}; // 1D array
    ai[4] = 5;

    int ai2[3][5]; // 2D array
    int ai3[3][5]; // 2D array
    int ai4[3][5]; // 2D array

    f1(ai2); // initialize ai2

    // output ai2
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << ai2[i][j] << '\t';
        cout << '\n';
    }
    cout << '\n';

    f5(&ai3[0][0], 3, 5); // initialize ai3

    // output ai3
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << ai3[i][j] << '\t';
        cout << '\n';
    }
    cout << '\n';

    f2(ai4, 3); // initialize ai4

    // output ai4
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << ai4[i][j] << '\t';
        cout << '\n';
    }
    cout << '\n';
    
    return 0;
}

// function that initializes a 3x5 array of ints
void f1(int a[3][5])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            a[i][j] = i * 5 + j; // linear (flat) offset into 2D array (1,..,n)
}

// function that initializes a dim1x5 array of ints
void f2(int a[][5], int dim1)
{
    for (int i = 0; i < dim1; i++)
        for (int j = 0; j < 5; j++)
            a[i][j] = i * 5 + j;
}

// function that initializes a dim1xdim2 array of ints
void f5(int *m, int dim1, int dim2)
{
    for (int i = 0; i < dim1; i++)
        for (int j = 0; j < dim2; j++)
            m[i * dim2 + j] = i * dim2 + j;
}
