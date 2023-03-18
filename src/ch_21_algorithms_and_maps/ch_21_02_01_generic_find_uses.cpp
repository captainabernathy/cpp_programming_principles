#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

typedef std::vector<char> Line;

class Text_iterator {
    std::list<Line>::iterator line_iterator;
    Line::iterator position_iterator;

public:
    typedef std::forward_iterator_tag iterator_category;
    typedef char value_type;
    typedef size_t difference_type;
    typedef char* pointer;
    typedef char& reference;

    // start this Text_iterator at line_iter's position_iter
    Text_iterator(std::list<Line>::iterator line_iter, Line::iterator pos_iter)
        : line_iterator(line_iter), position_iterator(pos_iter)
    { }

    // dereference operator
    char& operator*()
    {
        return *position_iterator;
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
    if (position_iterator == line_iterator->end()) // start next line
    {
        ++line_iterator;
        position_iterator = line_iterator->begin();
    }

    ++position_iterator;
    return *this;
}

bool Text_iterator::operator==(const Text_iterator& rhs) const
{
    return (line_iterator == rhs.line_iterator)
            && (position_iterator == rhs.position_iterator);
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

void f(std::vector<int>& v, int x);
void f(std::list<std::string>& v, std::string x);
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
        std::cout << "Found: " << *p << std::endl;
    else
        std::cout << "Did not find: " << x << std::endl;
}

void f(std::list<std::string>& v, std::string x)
{
    std::list<std::string>::iterator p = std::find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << std::endl;
    else
        std::cout << "Did not find: " << x << std::endl;
}

void f(Document& v, char x)
{
    Text_iterator p = std::find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << std::endl;
    else
        std::cout << "Did not find: " << x << std::endl;
}
