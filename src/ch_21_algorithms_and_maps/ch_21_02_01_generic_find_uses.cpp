// program demonstrates how to use standard library algorithm find() to locate
// an element in a collection
//
// program tests the implementation of a class that represents a Document as a
// list of Lines, where each Line is represented as a vector a characters, and
// uses a Text_iterator to keep track of the Line and character positions
// within a the Document
//
// program also uses a Text_iterator to search for a character in a Document
// with find()
//
// Line (alais for vector<char>)
//
// Document (class)
//      list<Line> lines
//      Document()
//      Text_iterator begin()
//      Text_iterator end()
//
// Text_iterator (class)
//      Text_iterator(list<Line>::iterator li_iter, Line::iterator pos_iter)

#include <vector> // for vector
#include <string> // for string
#include <list> // for list
#include <algorithm> // for find()
#include <iostream> // for cout
#include <text_utils/document_utils.hpp> // for Document, Text_iterator

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

// function tests whether or not the integer x exists in the vector of integers
// v references
void f(std::vector<int>& v, int x)
{
    std::vector<int>::iterator p = std::find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << '\n';
    else
        std::cout << "Did not find: " << x << '\n';
}

// function tests whether or not the string x exists in the vector of strings
// v references
void f(std::list<std::string>& v, std::string x)
{
    std::list<std::string>::iterator p = std::find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << '\n';
    else
        std::cout << "Did not find: " << x << '\n';
}

// function tests whether or not the character x exists in the document v
// references
void f(Document& v, char x)
{
    Text_iterator p = std::find(v.begin(), v.end(), x);
    if (p != v.end())
        std::cout << "Found: " << *p << '\n';
    else
        std::cout << "Did not find: " << x << '\n';
}
