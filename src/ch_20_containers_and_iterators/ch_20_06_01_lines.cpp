// program implements a data structure that represents a document as a list
// of lines (where each line consists of a vector of characters) and provides
// an overloaded input operator to read a document from an input stream

#include <iostream> // I/O library header
#include <vector>  // vector library header
#include <list> // list library header

using Line = std::vector<char>; // same as typedef vector<char> Line;

// a document consists of list of lines (character vectors)
struct Document {
    std::list<Line> lines; // list of lines

    // constructor... adds an empty line to the list of lines
    Document()
    {
        lines.push_back(Line());
    }
};

// overloaded input operator to read Document d from input stream is
std::istream& operator>>(std::istream& is, Document& d);

int main()
{
    Document d;
    std::cout << "Enter lines of text or press CTRL-D to exit." << '\n';
    std::cin >> d;
}

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
