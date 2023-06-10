#ifndef DOCUMENT_UTILS_HPP
#define DOCUMENT_UTILS_HPP

// provides
// Document (class)
//      list<Line> lines
//      Document()
//      Text_iterator begin()
//      Text_iterator end()
// AND
// Text_iterator (class)
//      list<vector<char>>::iterator line_iter
//      Line::iterator position_iter
//      Text_iterator(list<Line>::iterator li_iter, Line::iterator pos_iter)
//      bool operator==(Text_iterator const& rhs) const
//      bool operator!=(Text_iterator const& rhs) const
//      char& operator*()
//      Text_iterator& operator++()
// AND
// Line (alais for vector<char>)
#include <text_utils/document.hpp> // for Document

#include <istream> // for istream
#include <iostream> // for cout

// provides:
// template<typename T>
// T advance(T t, int n)
#include <algorithm_utils/advance.hpp> // for advance<>()

// overloaded input operator that reads Document d from input stream is
std::istream& operator>>(std::istream& is, Document& d);

// writes the lines of text in Document d to stdout
inline void print(Document& d)
{
    // for (Text_iterator p = d.begin(); p != d.end(); ++p)
    //     std::cout << *p;

    for (auto p : d)
        std::cout << p;
}

// removes line n from Document d
inline void erase_line(Document &d, int n)
{
    if (n < 0 || d.lines.size() <= (size_t)n)
        return;  // ignore out-of-range lines
    d.lines.erase(advance(d.lines.begin(), n));
}

#endif
