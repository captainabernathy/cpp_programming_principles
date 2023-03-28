// program implements a template functon that converts an object of any type
// that has defined an input operator into a string
// program implements a template function that converts an object that read in
// as a string into an object of a user specified type
// program also implements a template function that converts object from a
// user specified source type to a user specified destination type

#include <iostream> // I/O library header
#include <istream> // for ws
#include <string> // string library header
#include <sstream> // for ostringstream
#include <exception> // for bad_cast

using Unicode = long;
// typedef long Unicode;

// NOTE: the standard string is simply a basic_string of type char...
// ie: using string = std::basic_string<char>;

std::basic_string<Unicode> a_unicode_string;

using std::string;
using std::stringstream;
using std::ostringstream;
using std::istringstream;
using std::ws;
using std::cout;
using std::cerr;
using std::endl;
using std::exception;

// template function takes an object of any type that has an operator << and
// returns that object as a string
template<typename T>
string to_string(T const& t)
{
    ostringstream os;
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

// template function that attempts to read an object of the type specified from
// the string passed to s.
// NOTE: if s cannot be read as a type T, then the function throws a
// bad_from_string() exception
template<typename T>
T from_string(string const& s)
{
    istringstream is(s); // initialize input string stream with s
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

// template function that attempts to interpret the object provided to src
// as an object of the type provided to Dest and returns the result
// NOTE: if the object provided to src, cannot be interpreted as the type
// provided to Dest, then the function throws a bad_lexical_cast() exception
template<typename Dest, typename Src>
Dest lexical_cast(Src src)
{
    stringstream interpreter;
    Dest dest;

    if (!(interpreter << src)  // write src into stream
        || !(interpreter >> dest) // read result from stream into dest
        || !(interpreter >> ws).eof()) // read remaining through eof into ws
        throw bad_lexical_cast();

    return dest;
}

int main()
{
    string s1 = to_string(12.333);
    cout << "s1: " << s1 << endl;  // 12.333

    string s2 = to_string(1 + 5 * 6 - 99 / 7); // 17
    cout << "s2: " << s2 << endl;

    string s3 = to_string((1 + 5 * 6 - 99 / 7.0)); // 16.8571
    cout << "s3: " << s3 << endl;

    float f1 = 2 * lexical_cast<float, string>(s3);  // 33.1742
    cout << "f1: " << f1 << endl;

    string s4 = lexical_cast<string, float>(f1);  // 33.7142
    cout << "s4: " << s4 << endl;

    try
    {
        int i1 = lexical_cast<int, string>("Mary had a little lamb");
        cout << "i1: " << i1 << endl;
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }

    return 0;
}
