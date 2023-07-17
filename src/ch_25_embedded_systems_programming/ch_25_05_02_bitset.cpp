// program demonstrates how to use the standard library's bitset<> template

#include <exception> // for exception
#include <iostream> // for cin, cout, cerr
#include <bitset> // for bitset
#include <string> // for string

// function that demonstrates how to use the bitset<> template
void test();

int main()
{
    using std::exception;
    using std::cerr;

    try
    {
        using std::bitset;
        using std::cout;
        using std::cin;

        test();

        const int max = 10;
        bitset<max> b; // a 10-bit set

        // prompt user to enter a bit string
        std::cout << "Enter a bit string up to 10 digits (or Ctrl-D) to "
            << "quit: ";

        // read bit string
        while (cin >> b)
        {
            cout << "b: " << b << '\n'
                << "b reversed: ";

            // NOTE: bitsets are numbered from right to left (lsb to msb), so
            // when indexing into a bitset, the lsb is found at position 0,
            // and the msb is found at position n-1
            for (int i = 0; i < max; i++)
                cout << b[i];
            cout << '\n';
            std::cout << "Enter a bit string up to 10 digits (or Ctrl-D) to "
                << "quit: ";
        }
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }



    return 0;
}

void test()
{
    std::bitset<4> flags = 0xb; // 11 decimal
    std::cout << flags << '\n'; // 1101

    // NOTE: when providing a bit string that contains fewer elements than the
    // size of a bitset, the bit set will be 0-filled from the msb to the
    // first element of the bit string
    std::bitset<128> dword_bits(std::string {"1010101010101010"});
    std::cout << dword_bits << "\n\n";  // 0000...1010101010101010

    std::bitset<16> b1;
    std::bitset<16> b2 {"1010101010101010"};
    std::bitset<16> b3 {"1111000011110000"};

    std::cout << "b2: " << b2 << '\n';
    std::cout << "b3: " << b3 << '\n';

    b1 = b2 & b3; // bitwise and
    std::cout << "b2 & b3: " << b1 << '\n'; // 1010|0000|1010|0000

    b1 = b2 | b3; // bitwise or
    std::cout << "b2 | b3: " << b1 << '\n'; // 1111|1010|1111|1010

    b1 = b2 ^ b3; // bitwise xor
    std::cout << "b2 ^ b3: " << b1 << '\n'; // 0101|1010|0101|1010

    b1 = ~b2; // bitwise not
    std::cout << "~b2: " << b1 << '\n'; // 0101|0101|0101|0101

    b1 = b2 << 2; // left shift... equivalent to lhs * pow(2,rhs)
    std::cout << "b2 << 2: " << b1 << '\n'; // 1010|1010|1010\1000

    b1 = b2 >> 3; // right shift... equivalent to lhs / pow(2,rhs)
    std::cout << "b2 >> 3: " << b1 << "\n\n"; // 0001|0101|0101|0101

    // bit pattern for character 'c'
    std::cout << std::bitset<8>('c') << '\n'; // 0110|0011
}
