// first attempt at testing the Token class to represent the elements of a
// calculator's grammar

#include <iostream> // for cout
#include <calculator_utils/token.hpp> // for Token

int main()
{
    using std::cout;

    // create a token from a character
    Token t1('+');  // '+', 0
    
    // create a token from a character and a double
    Token t2('8', 11.5); // '8', 11.5

    // write results to stdout
    cout << "t1: " << t1.kind << ' ' << t1.value << '\n'; // t1: + 0
    cout << "t2: " << t2.kind << ' ' << t2.value << '\n'; // t2: 8 11.5

    return 0;
}
