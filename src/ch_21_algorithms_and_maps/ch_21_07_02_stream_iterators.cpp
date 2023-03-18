#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

void foo();

int main()
{
    string from;
    string to;
    cout << "Enter file to copy: ";
    cin >> from;
    cout << "Enter results destination: ";
    cin >> to; // get source and target file names

    ifstream is(from.c_str()); // open input stream
    ofstream os(to.c_str()); // open output stream

    istream_iterator<string> in_iter(is); // make input iterator from stream
    istream_iterator<string> eos; // input sentinel

    // make output iterator for stream
    ostream_iterator<string> out_iter(os, "\n");

    vector<string> b(in_iter, eos); // vector initialized from input
    sort(b.begin(), b.end()); // sort the buffer
    copy(b.begin(), b.end(), out_iter);  // copy buffer to output

    foo();

    return 0;
}

void foo()
{
    // assigning to *oo is to write cout
    ostream_iterator<string> oo(cout);

    *oo = "Hello, "; // meaning cout << "Hello, "
    ++oo; // get read for next output operation
    *oo = "world\n"; // meaning cout "world!\n"

    // reading from *ii is to read a string from cin
    istream_iterator<string> ii(cin);
    string s1 = *ii; // meaning cin >> s1
    ++ii;  // get ready for next input operation
    string s2 = *ii;
    ++ii;

    *oo = s1;
    oo++;
    *oo = s2;
    ++oo;
    *oo = "\n";
}
