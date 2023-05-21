// program demonstrates how to use standard library algorithm find() to locate
// an element in a collection
//
// program also implements a Document class to represents a document and a
// Text_iterator class to keep track of line and character positions within a
// Document
//
// program use a Text_iterator object to search for a character in a document
// using find()

#include <iostream> // for cout
#include <list> // for list 
#include <iterator> // for forward_iterator_tag
#include <vector> // for vector 
#include <string> // for string 
#include <algorithm> // for find()

using Line = std::vector<char>; // same as typedef std::vector<char> Line;

// keeps track of line and character position within a line
class Text_iterator {
    // std::list<std::vector<char>>::iterator line_iter;
    std::list<Line>::iterator line_iter;

    // std::vector<char>::iterator position_iter;
    Line::iterator position_iter;

public:
    // typedef std::forward_iterator_tag iterator_category;
    using iterator_category = std::forward_iterator_tag;

    // typedef char value_type;
    using value_type = char;

    // typedef size_t difference_type;
    using difference_type = std::size_t;

    // typedef char* pointer;
    using pointer = char *;

    // typedef char& reference;
    using reference = char &;

    // start iterator at line line_itr's character position pos_itr
    Text_iterator(std::list<Line>::iterator line_iter, Line::iterator pos_iter)
        : line_iter{line_iter}, position_iter{pos_iter}
    { }

    // dereference operator... returns a reference to the character at
    // position_iter
    // char& operator*()
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

    // inequality operator... true when ^^^ isn't
    bool operator!=(Text_iterator const& rhs) const
    {
        return !(*this == rhs);
    }
};

// pre-increment operator
Text_iterator& Text_iterator::operator++()
{
    ++position_iter; // advance to next character

    if (position_iter == line_iter->end()) // at the end of the line?
    {
        ++line_iter; // advance to next line
        
        // set position iterator to the beginning of the next line
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
        return Text_iterator(lines.begin(), lines.begin()->begin());
    }

    // returns a Text_iterator to one beyond the last character of the last line
    Text_iterator end()
    {
        std::list<Line>::iterator last = lines.end();
        --last; // since we know that the document isn't empty
        return Text_iterator(last, last->end());
    }
};

// function tests whether or not the integer x exists in the vector of integers
// v references
void f(std::vector<int>& v, int x);

// function tests whether or not the string x exists in the vector of strings
// v references
void f(std::list<std::string>& v, std::string x);

// function tests whether or not the character x exists in the document v
// references
void f(Document& v, char x);

int main()
{
    {
        int arr[7] = {1, 2, 3, 4, 5, 6, 7};
        int *first = arr;
        int *last = arr + 7;
        std::vector<int> v(first, last);
        f(v, 4);
    }

    {
        const char *arr[7] = {"one", "two", "three", "four", "five", "six",
                              "seven"};
        const char **first = arr;
        const char **last = arr + 7;
        std::list<std::string> l(first, last);
        f(l, "six");
    }

    {
        Document d;
        f(d, 'A');
    }

    return 0;
}

void f(std::vector<int>& v, int x)
{
    std::vector<int>::iterator p = std::find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << '\n';
    else
        std::cout << "Did not find: " << x << '\n';
}

void f(std::list<std::string>& v, std::string x)
{
    std::list<std::string>::iterator p = std::find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << '\n';
    else
        std::cout << "Did not find: " << x << '\n';
}

void f(Document& v, char x)
{
    Text_iterator p = std::find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << '\n';
    else
        std::cout << "Did not find: " << x << '\n';
}
