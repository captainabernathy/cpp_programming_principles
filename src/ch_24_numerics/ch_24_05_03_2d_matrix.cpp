// program demonstrates how to perform various operations on a two-dimensonal
// Matrix using the class template Matrix<T,2> and other features provided
// by the numeric_utils library

#include <iostream> // for cout
#include <numeric_utils/matrix_utils.hpp> // for Matrix<>, apply<>()

int c; // a dummy global variable

// updates a (in place) to the current value of c, and increments c
inline void f(int& a)
{
    a = c++;
}

// enum that represents chess pieces
enum Piece {none, pawn, knight, queen, king, bishop, rook};

// function that uses a 2D Matrix to represent a chessboard
void board();

int main()
{
    using std::cout;
    using namespace Numeric_lib;

    Matrix<int, 2> a {3, 4}; // a 3x4 Matrix
    size_t s = a.size(); // number of elements in a
    size_t d1 = a.dim1(); // number of elements in a's first dimension
    size_t d2 = a.dim2(); // number of elements in a's second dimension

    cout << s << ' ' << d1 << ' ' << d2 << "\n\n"; // 12, 3, 4

    a.apply(f);
    int *p = a.data(); // extract data as a c-style array

    cout << a << "\n\n"; // {0 1 2 3} {4 5 6 7} {8 9 10 11}

    for (size_t i = 0; i < s; i++)
        cout << *(p + i) << ' '; // 0 1 2 3 4 5 6 7 8 9 10 11
    cout << "\n\n";

    for (size_t i = 0; i < d1; i++)
    {
        for (size_t j = 0; j < d2; j++)
            cout << p[i * d2 + j] << ' '; // linearized 2D offset
        cout << '\n';
    }
    cout << '\n';

    size_t i = 1;
    size_t j = 2;
    size_t n = 2;

    cout << a(i, j) << '\n';
    cout << a[i][j] << "\n\n";

    // from row i to end
    cout << a.slice(i) << "\n\n";  // {4 5 6 7} {8 9 10 11}

    // row i
    cout << a.row(i) << '\n'; // {4 5 6 7}
    cout << a[i] << "\n\n"; //  {4 5 6 7}

    // slice from row i up to row i
    cout << a.slice(i, i) << "\n\n"; // empty

    // slice from row i up to row n (2)
    cout << a.slice(i, n) << "\n\n"; // {4 5 6 7}

    // slice from row i up to row 3
    cout << a.slice(i, 3) << "\n\n"; // {4 5 6 7} {8 9 10 11}

    Matrix<int, 2> a2 = a; // copy initialization
    a2 *= 4; // scaling
    a = a2 / 2; // copy assignment
    
    cout << a << "\n\n"; // {0 2 4 6} {8 10 12 14} {16 18 20 22}
    cout << a2 << "\n\n"; // {0 4 8 12} {16 20 24 28} {32 36 40 44}

    // passing apply() a lambda function
    Matrix<int, 2> b = apply([](int a){ return a * a;}, a);
    cout << b << "\n\n"; // {0 4 16 36} {64 100 144 196} {256 324 400 484}
    
    // another apply() with a lambda function
    b.apply([](int& a, int b){a /= b;}, -4);
    cout << b << "\n\n"; // {0 -4 -16 -9} {-16 -25 -36 -49} {-64 -81 -100 -121}

    // swap the first two rows of a
    a.swap_rows(0, 1); // {8 10 12 14} {0 2 4 6} {16 18 20 22}
    cout << a << "\n\n";

    board();

    return 0;
}

// function that uses a 2D Matrix to represent a chessboard
void board()
{
    using namespace Numeric_lib;
    Matrix<Piece, 2> board(8, 8); // chessboard

    const int white_start_row = 0;
    const int black_start_row = 7;

    Matrix<Piece> const& white_start = board[0];
    Matrix<Piece> const& red_start = board[7];

    Piece a[] = {rook, knight, bishop, queen, king, bishop, knight, rook};
    Matrix<Piece> start_row(a); // row with ^^^
    Matrix<Piece> clear_row(8); // and empty row

    board[white_start_row] = start_row; // reset white pieces
    for (size_t i = 1; i < 7; i++)
        board[i] = clear_row; // clear the middle o the board
    board[black_start_row] = start_row; // reset black pieces
    
    std::cout << board << "\n\n";
}

