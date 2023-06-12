// program tests the implementation of the Document class, which represents
// a document as a list of lines (where each line consists of a vector of
// characters) and provides an overloaded input operator to read a Document
// from an input stream
//
// Line (alais for vector<char>)
//
// Document (class)
//      list<Line> lines
//      Document()
//
// istream& operator>>(istream& is, Document& d)

#include <iostream> // for cin, cout
#include <text_utils/document_utils.hpp> // for Document

int main()
{
    Document d;
    std::cout << "Enter lines of text or press CTRL-D to exit.\n";
    std::cin >> d;

    return 0;
}
