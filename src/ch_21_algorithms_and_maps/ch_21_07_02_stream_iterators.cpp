// program demonstrates how to use stream iterators to copy from input streams
// to output streams

#include <string> // for string
#include <iostream> // for cin, cout
#include <fstream> // for ifstream, ofstream
#include <iterator> // for istream_iterator, ostream_iterator
#include <vector> // for vector
#include <algorithm> // for sort(), copy()

// function demonstrates how to use ostream and istream iterators to do basic
// I/O
void foo();

int main()
{
    using std::string;
    using std::cout;
    using std::cin;
    using std::ifstream;
    using std::ofstream;
    using std::istream_iterator;
    using std::ostream_iterator;
    using std::vector;
    using std::sort;
    using std::copy;

    string from; // input file name
    string to; // output file name

    cout << "Enter file to copy: ";
    cin >> from; // get source file name
    cout << '\n'; // flushes stream

    cout << "Enter results destination: ";
    cin >> to; // get target file name
    cout << '\n'; // flushes stream

    ifstream is {from.c_str()}; // open input stream
    ofstream os {to.c_str()}; // open output stream

    // make input iterator from stream
    istream_iterator<string> in_iter {is};
    istream_iterator<string> eos; // input sentinel

    // make output iterator for stream using new line as a delimiter
    ostream_iterator<string> out_iter(os, "\n");

    vector<string> buf(in_iter, eos); // initialized buffer from input
    sort(buf.begin(), buf.end()); // sort the buffer
    copy(buf.begin(), buf.end(), out_iter);  // copy buffer to output

    foo();

    return 0;
}

void foo()
{
    // initialize output stream iterator to cout
    // assigning to *oo is to write cout
    std::ostream_iterator<std::string> oo {std::cout};

    *oo = "Hello, "; // meaning cout << "Hello, "
    
    ++oo; // get read for next output operation
    *oo = "world\n"; // meaning cout "world!\n"
    
    ++oo; // get ready for next output operation
    *oo = "\n";
    
    ++oo; // get ready for next output operation
    *oo = "Enter a string: ";

    // initialize input stream itertor to cin
    // reading from *ii is to read a string from cin
    std::istream_iterator<std::string> ii {std::cin};
    
    std::string s1 = *ii; // meaning cin >> s1

    ++oo; // get ready for next output operation
    *oo = "Enter another string: ";
    
    ++ii;  // get ready for next input operation
    std::string s2 = *ii;

    ++oo; // get ready for next input operation
    *oo = "You entered: ";
    ++oo; // get ready for next input operation
    *oo = s1;
    ++oo; // get ready for next input operation
    *oo = "\n";

    ++oo; // get ready for next input operation
    *oo = "and: ";
    ++oo; // get ready for next input operation
    *oo = s2;
    ++oo; // get ready for next input operation
    *oo = "\n";
}
