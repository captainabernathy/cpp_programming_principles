#include <iostream>
#include <istream>
#include <string>
#include <sstream> // for ostringstream
#include <exception> // for bad_cast

typedef long Unicode;
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

template<typename T>
string to_string(const T& t)
{
    ostringstream os;
    os << t;  // read t into s
    return os.str();
}

// class for reporting string cast errors
struct bad_from_string : std::bad_cast {

    const char *what() const throw() // override bad_cast's what()
    {
        return "bad cast from string";
    }
};

template<typename T>
T from_string(const string& s)
{
    istringstream is(s);
    T t;
    if (!(is >> t))
        throw bad_from_string();
    return t;
}

struct bad_lexical_cast : std::bad_cast {

    const char *what() const throw()
    {
        return "bad lexical cast";
    }
};

template<typename Dest, typename Src>
Dest lexical_cast(Src src)
{
    stringstream interpreter;
    Dest dest;

    if (!(interpreter << src)  // read src into stream
        || !(interpreter >> dest) // read result from stream into dest
        || !(interpreter >> ws).eof()) // read remaining through eof into ws
        throw bad_lexical_cast();

    return dest;
}

int main()
{
    string s1 = to_string(12.333);
    cout << "s1: " << s1 << endl;

    string s2 = to_string(1 + 5 * 6 - 99 / 7);
    cout << "s2: " << s2 << endl;

    string s3 = to_string((1 + 5 * 6 - 99 / 7.0));
    cout << "s3: " << s3 << endl;

    float f1 = 2 * lexical_cast<float, string>(s3);
    cout << "f1: " << f1 << endl;

    string s4 = lexical_cast<string, float>(f1);
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
