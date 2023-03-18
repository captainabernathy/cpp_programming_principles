#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <set>
using namespace std;

int main()
{
    string from;
    string to;
    cout << "Enter file to copy: ";
    cin >> from;
    cout << "Enter results destination: ";
    cin >> to; // get source and target file names

    ifstream is {from};
    ofstream os {to};

    istream_iterator<string> in_iter(is);
    istream_iterator<string> eos;
    ostream_iterator<string> out_iter(os, " ");

    set<string> s(in_iter, eos); // initialize set from input
    copy(s.begin(), s.end(), out_iter);  // copy buffer to output

    return 0;
}
