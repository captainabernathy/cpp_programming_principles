// program implements a text iterator object to keep track of line and
// character position within a line when reading a document
// program implements a data structure that represents a document as
// a collection of lines
// program also implements a function to find text within a document as well as
// another function to determine if the characters between two text iterators
// match a string

#include <iostream> // I/O library header
#include <vector>  // vector library header
#include <string> // string library header
#include <list> // list library header
#include <iterator> // iterator library header
#include <algorithm> // algorithm library header

using Line = std::vector<char>;  // same as typdef vector<char> Line;

// keeps track of line and character position within a line
class Text_iterator {
    // std::list<std::vector<char>>::iterator line_iter;
    std::list<Line>::iterator line_iter;
    // std::vector<char>::iterator position_iter;
    Line::iterator position_iter;

public:
    using iterator_category = std::forward_iterator_tag;
    // typedef std::forward_iterator_tag iterator_category;
    using value_type = char;
    // typedef char value_type;
    using difference_type = std::size_t;
    // typedef size_t difference_type;
    using pointer = char *;
    // typedef char *pointer;
    using reference = char &;
    // typedef char& reference;

    // start iterator at line line_itr's character position pos_itr
    Text_iterator(std::list<Line>::iterator line_itr, Line::iterator pos_itr)
        : line_iter {line_itr}, position_iter {pos_itr}
    {  }

    // dereference operator... returns a reference to the character at
    // position_iter
    // char& operator*()
    reference operator*()
    {
        return *position_iter;
    }

    // pre-increment operator... advances position_iter... and line_iter when
    // position_iter reaches the end of a line
    Text_iterator& operator++();
    
    // equality operator... Text_iterators are equal when their line_iterators
    // and position_iterators are equal
    bool operator==(Text_iterator const& rhs) const
    {
        return (line_iter == rhs.line_iter)
                && (position_iter == rhs.position_iter);
    }

    // inequality operator... true with ^^^ isn't
    bool operator!=(Text_iterator const& rhs) const
    {
        return !(*this == rhs);
    }
};

// pre-increment operator
Text_iterator& Text_iterator::operator++()
{
    ++position_iter; // advance position iterator

    // if (position_iter == (*line_iter).end())
    if (position_iter == line_iter->end())  // at the end of the line?
    {
        ++line_iter; // advance to the next line

        // set position iterator to the beginning of the next line
        // position_iter = (*line_iter).begin();
        position_iter = line_iter->begin();
    }

    return *this;
}

// data structure that represents a document as a list of lines
struct Document {
    std::list<Line> lines;

    // constructor... adds an empty line to the list of lines
    Document()
    {
        lines.push_back(Line());
    }

    // returns an Text_iterator that begins at the first character of the first
    // line
    Text_iterator begin()
    {
        return Text_iterator {lines.begin(), lines.begin()->begin()};
    }

    // returns a Text_iterator to one beyond the last character of the last line
    Text_iterator end()
    {
        std::list<Line>::iterator last = lines.end();
        --last; // since we know that the document isn't empty
        return Text_iterator {last, last->end()};
    }
};

// overloaded input operator to read Document d from input stream is
std::istream& operator>>(std::istream& is, Document& d);

// writes the lines of text in Document d to stdout
inline void print(Document& d)
{
    // for (auto p : d)
    //     std::cout << p;
    for (Text_iterator p = d.begin(); p != d.end(); ++p)
        std::cout << *p;
}

// template for a function that advances an iterator of type t, n positions
// advance n places in t
template<typename T>
T advance(T t, int n)
{
    while (n > 0)
    {
        ++t;
        n--;
    }

    return t;
}

// removes line n from Document d
inline void erase_line(Document &d, int n)
{
    if (n < 0 || d.lines.size() <= (size_t)n)
        return;  // ignore out-of-range lines
    d.lines.erase(advance(d.lines.begin(), n));
}

// determines if the text between first and last match the string s
bool match(Text_iterator first, Text_iterator last, std::string const& s);

// if string s exists between first and last, return a Text_iterator to the
// first character... or an iterator to the end of the sequence when it does
// not
Text_iterator find_text(Text_iterator first, Text_iterator last,
    std::string const& s);

int main()
{
    Document my_doc;
    std::cout << "Enter lines of text or press CTRL-D to exit." << std::endl;
    std::cin >> my_doc;
    Text_iterator p = find_text(my_doc.begin(), my_doc.end(),
                                "secret\nhomestead");

    std::cout << std::endl;

    if (p == my_doc.end())
        std::cout << "not found" << std::endl;
    else
    {
        std::cout << "found: secret\nhomestead" << std::endl << std::endl;
    }

    print(my_doc);
    std::cout << '\n';
    return 0;
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
            d.lines.push_back(Line{}); // add another line
    }

    if (d.lines.back().size()) // add final empty line if there are characters
        d.lines.push_back(Line{}); // in the last line

    return is;
}

bool match(Text_iterator first, Text_iterator last, std::string const& s)
{
    std::string::const_iterator pos;

    for (pos = s.begin();
         pos != s.end() && first != last && *pos == *first;
         ++pos, ++first) {  }

    return pos == s.end(); // if we reached the end, we matched the string
}

Text_iterator find_text(Text_iterator first, Text_iterator last,
    std::string const& s)
{
    if (s.size() == 0) // string is empty
        return last;

    char first_char = s[0];
    while (true)
    {
        // look for an occurrence of first_char between first and last
        Text_iterator pos = std::find(first, last, first_char);

        // return an iterator to first character of s when found or an iterator
        // to the end of the sequence otherwise
        if (pos == last || match(pos, last, s))
            return pos;

        first = ++pos; // loot at next character in pos
    }
}
