#include <iostream> // I/O library header
#include <vector>  // vector library header
#include <list> // list library header

using Line = std::vector<char>; // same as typedef vector<char> Line;

// a document consists of list of lines (character vectors)
struct Document {
    std::list<Line> line;

    // constructor... adds an empty line to the list of lines
    Document()
    {
        line.push_back(Line());
    }
};

std::istream& operator>>(std::istream& is, Document& d)
{
    char ch;
    while (is.get(ch))
    {
        // NOTE: back() returns a reference to the last element
        d.line.back().push_back(ch); // add character

        if (ch == '\n')
            d.line.push_back(Line()); // add another line
    }

    // if (d.line.back().size()) // add final empty line if there are characters
    //     d.line.push_back(Line()); // in the last line

    return is;
}

int main()
{
    Document d;
    std::cout << "Enter lines of text or press CTRL-D to exit." << std::endl;
    std::cin >> d;
}
