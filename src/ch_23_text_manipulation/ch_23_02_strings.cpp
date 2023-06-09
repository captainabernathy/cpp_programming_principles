// program tests the function template to_string<>() that converts an object of
// any type that has defined an input operator into a string
//
// additionally, program tests the function template from_string<>() that
// converts a string into an object of a user specified type
//
// program also tests the function template lexical_cast<>() that  converts an
// object of a user specified source type to a user specified destination type

#include <iostream> // for cout, cerr
#include <string> // for string, basic_string
#include <exception> // for exception
#include <io_utils/io_utils.hpp> // for to_string<>(), from_string<>(), 
                                 // lexical_cast<>()

// not sure why book included this in the example...
// typedef long Unicode;
using Unicode = long;

// also not sure why book included this in the example...
// NOTE: the standard string is simply a basic_string of type char...
// ie: using string = std::basic_string<char>;
std::basic_string<Unicode> a_unicode_string;

int main()
{
    using std::cout;
    using std::cerr;
    using std::exception;
    using std::string;

    string s1 = to_string(12.333);
    cout << "s1: " << s1 << '\n';  // 12.333

    double d1 = from_string<double>(s1);
    cout << "d1: " << d1 << '\n';  // 12.333

    string s2 = to_string(1 + 5 * 6 - 99 / 7);
    cout << "s2: " << s2 << '\n'; // 17

    int i1 = from_string<int>(s2);
    cout << "i1: " << i1 << '\n'; // 17

    string s3 = to_string((1 + 5 * 6 - 99 / 7.0));
    cout << "s3: " << s3 << '\n'; // 16.8571

    float f1 = 2 * lexical_cast<float, string>(s3);
    cout << "f1: " << f1 << '\n'; // 33.1742

    string s4 = lexical_cast<string, float>(f1);
    cout << "s4: " << s4 << '\n'; // 33.7142

    try
    {
        // throws bad_lexical_cast
        int i2 = lexical_cast<int, string>("Mary had a little lamb");
        cout << "i2: " << i2 << '\n';
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception\n";
        return 2;
    }

    return 0;
}
