#include <text_utils/document_utils.hpp>
#include <istream>  // for istream
#include <text_utils/document.hpp> // for Document
#include <text_utils/line.hpp> // for Line

// overloaded input operator to read Document d from input stream is
std::istream& operator>>(std::istream& is, Document& d)
{
    char ch;
    while (is.get(ch))
    {
        // NOTE: back() returns a reference to the last element
        d.lines.back().push_back(ch); // add character

        if (ch == '\n')
            d.lines.push_back(Line { }); // add another line
    }

    if (d.lines.back().size()) // add final empty line if there are characters
        d.lines.push_back(Line { }); // in the last line

    return is;
}
