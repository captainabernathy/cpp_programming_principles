// program demonstrates how to use the standard library's set collection to
// collect the unique words from an input file and copy them to an output
// file

#include <fstream> // file stream library header
#include <iostream> // I/O library header
#include <iterator> // iterator library header
#include <string> // string library header
#include <set> // set library header
using namespace std;

int main()
{
    string from;
    string to;
    cout << "Enter file to copy: ";
    cin >> from; // get source file name
    cout << "Enter results destination: ";
    cin >> to; // get target file name

    // initialize input file stream for source file
    ifstream is {from};

    // initialize output file stream for target file
    ofstream os {to};

    // initialize input stream iterator to source file
    istream_iterator<string> in_iter(is);
    istream_iterator<string> eos; // end of stream sentinel

    // initialize output stream iterator to target file using space as a
    // delimiter
    ostream_iterator<string> out_iter(os, " ");

    // initialize a set from input... set will contain unique words in input
    set<string> s(in_iter, eos);

    // copy set contents to output
    copy(s.begin(), s.end(), out_iter);  // copy buffer to output

    return 0;
}
