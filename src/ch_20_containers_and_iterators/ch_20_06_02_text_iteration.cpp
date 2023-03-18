// not clear what he wants this program to do... doesn't provide a working
// example or test
#include <iostream> // I/O library header
#include <vector>  // vector library header
#include <string> // string library header
#include <list> // list library header
#include <iterator> // iterator library header
#include <algorithm> // algorithm library header

using Line = std::vector<char>;  // same as typdef vector<char> Line;

// keeps track of line and character position within a line
class Text_iterator {
    std::list<Line>::iterator line_iter;
    Line::iterator position_iter;

public:
    // using iterator_category = std::forward_iterator_tag;
    // typedef size_t difference_type;
    typedef std::forward_iterator_tag iterator_category;
    typedef char value_type;
    typedef size_t difference_type;
    typedef char *pointer;
    typedef char& reference;

    // start iterator at line line_itr's character position pos_itr
    Text_iterator(std::list<Line>::iterator line_itr, Line::iterator pos_itr)
        : line_iter{line_itr}, position_iter{pos_itr}
    {  }

    char& operator*()
    {
        return *position_iter;
    }

    Text_iterator& operator++();
    bool operator==(const Text_iterator& rhs) const;
    bool operator!=(const Text_iterator& rhs) const
    {
        return !(*this == rhs);
    }
};

Text_iterator& Text_iterator::operator++()
{
    if (position_iter == (*line_iter).end())
    // if (position_iter == line_iter->end())
    {
        ++line_iter;
        position_iter = (*line_iter).begin();
        // position_iter = line_iter->begin();
    }

    ++position_iter;
    return *this;
}

bool Text_iterator::operator==(const Text_iterator& rhs) const
{
    return (line_iter == rhs.line_iter) && (position_iter == rhs.position_iter);
}

struct Document {
    std::list<Line> line;

    Document()
    {
        line.push_back(Line());
    }

    // first character of first line
    Text_iterator begin()
    {
        return Text_iterator(line.begin(), line.begin()->begin());
    }

    // one beyond the last line
    Text_iterator end()
    {
        std::list<Line>::iterator last = line.end();
        --last;
        return Text_iterator(last, last->end());
    }
};

void print(Document& d)
{
    // for (auto p : d)
    //     std::cout << p;
    for (Text_iterator p = d.begin(); p != d.end(); ++p)
        std::cout << *p;
}

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

void erase_line(Document &d, int n)
{
    if (n < 0 || d.line.size() <= (size_t)n)
        return;  // ignore out-of-range lines
    d.line.erase(advance(d.line.begin(), n));
}

bool match(Text_iterator first, Text_iterator last, const std::string& s)
{
    std::string::const_iterator pos;

    for (pos = s.begin();
         pos != s.end() && first != last && *pos == *first;
         ++pos, ++first) {  }

    return pos == s.end(); // if we reached the end, we matched the string
}

Text_iterator find_text(Text_iterator first, Text_iterator last,
    const std::string& s)
{
    if (s.size() == 0) // string is empty
        return last;

    char first_char = s[0];
    while (true)
    {
        Text_iterator pos = std::find(first, last, first_char);
        if (pos == last || match(pos, last, s))
            return pos;
    }

}

int main()
{
    Document my_doc;
    Text_iterator p = find_text(my_doc.begin(), my_doc.end(),
                                "secret\nhomestead");
    if (p == my_doc.end())
        std::cout << "not found" << std::endl;
    else
    {
        // do something
    }

    print(my_doc);

    return 0;
}
