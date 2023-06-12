// program tests the Text_iterator class, which can be used to keep track of
// the line and character position within a line when reading a Document
//
// program also tests the function find_text(), which determines if a string
// exists between two Text_iterators and returns a Text_iterator to the first
// character of the string if so or a Text_iterator to the end of the sequence
// if not
//
// Line (alais for vector<char>)
//
// Document (class)
//      list<Line> lines
//      Document()
//      Text_iterator begin()
//      Text_iterator end()
//
// istream& operator>>(istream& is, Document& d)
// print(Document& d)
//
// Text_iterator (class)
//      Text_iterator(list<Line>::iterator li_iter, Line::iterator pos_iter)
//
// Text_iterator find_text(Text_iterator first, Text_iterator last,
//                         string const& s)

#include <iostream> // for cin, cout
#include <text_utils/document_utils.hpp> // for Document, for print()
#include <text_utils/text_utils.hpp> // for Text_iterator, find_text()

int main()
{
    Document my_doc;
    std::cout << "Enter lines of text or press CTRL-D to exit.\n";
    std::cin >> my_doc;
    Text_iterator p = find_text(my_doc.begin(), my_doc.end(),
                                "secret\nhomestead");

    std::cout << '\n';

    if (p == my_doc.end())
        std::cout << "not found\n";
    else
    {
        std::cout << "found: secret\nhomestead\n\n";
    }

    print(my_doc);
    std::cout << '\n';

    return 0;
}
