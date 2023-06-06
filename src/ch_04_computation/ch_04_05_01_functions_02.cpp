// another program that demonstrates the implementation of a simple inline
// function

#include <iostream> // for cout

// simple function that writes the square of its input to stdout
inline void print_square(int v)
{
    std::cout << v << '\t' << v * v << '\n';
}

int main()
{
    for (int i = 0; i < 100; i++)
        // function writes each integer and its square to stdout
        print_square(i);

    return 0;
}
