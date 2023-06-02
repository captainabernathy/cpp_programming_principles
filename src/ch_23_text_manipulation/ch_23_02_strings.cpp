// program implements a functon template that converts an object of any type
// that has defined an input operator into a string
//
// additionally, program implements a function template that converts an object
// read in as a string into an object of a user specified type
//
// program also implements a function template that converts an object of a
// user specified source type to a user specified destination type

#include <iostream> // for cout, cerr
#include <istream> // for ws
#include <string> // for string, basic_string
#include <sstream> // for istringstream, ostringstream
#include <typeinfo> // for bad_cast
#include <exception> // for exception

// typedef long Unicode;
using Unicode = long;

// NOTE: the standard string is simply a basic_string of type char...
// ie: using string = std::basic_string<char>;
std::basic_string<Unicode> a_unicode_string;

// function template takes an object of any type that has an operator << and
// returns that object as a string
template<typename T>
std::string to_string(T const& t)
{
    std::ostringstream os;
    os << t;  // write t into os
    return os.str();
}

// class for reporting string cast errors
struct bad_from_string : std::bad_cast {

    const char *what() const throw() // override bad_cast's what()
    {
        return "bad cast from string";
    }
};

// function template that attempts to read an object of the type specified from
// the string passed to s
// NOTE: if s cannot be read as a type T, then the function throws a
// bad_from_string() exception
template<typename T>
T from_string(std::string const& s)
{
    std::istringstream is {s}; // initialize input string stream with s
    T t; // target type
    if (!(is >> t)) // read t from stream
        throw bad_from_string();
    return t;
}

// class for reporting lexical cast errors
struct bad_lexical_cast : std::bad_cast {

    const char *what() const throw()
    {
        return "bad lexical cast";
    }
};

// function template that attempts to interpret the object provided to src
// as an object of the type provided to Dest and returns the result
// NOTE: if the object provided to src, cannot be interpreted as the type
// provided to Dest, then the function throws a bad_lexical_cast() exception
template<typename Dest, typename Src>
Dest lexical_cast(Src src)
{
    std::stringstream interpreter;
    Dest dest;

    // write src into stream
    // read result from stream into dest
    // read remaining through eof into ws
    if (!(interpreter << src)
        || !(interpreter >> dest)
        || !(interpreter >> std::ws).eof())
        throw bad_lexical_cast();

    return dest;
}

int main()
{
    using std::cout;
    using std::exception;
    using std::cerr;
    using std::string;

    string s1 = to_string(12.333);
    cout << "s1: " << s1 << '\n';  // 12.333

    string s2 = to_string(1 + 5 * 6 - 99 / 7); // 17
    cout << "s2: " << s2 << '\n';

    string s3 = to_string((1 + 5 * 6 - 99 / 7.0)); // 16.8571
    cout << "s3: " << s3 << '\n';

    float f1 = 2 * lexical_cast<float, string>(s3);  // 33.1742
    cout << "f1: " << f1 << '\n';

    string s4 = lexical_cast<string, float>(f1);  // 33.7142
    cout << "s4: " << s4 << '\n';

    try
    {
        int i1 = lexical_cast<int, string>("Mary had a little lamb");
        cout << "i1: " << i1 << '\n';
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
