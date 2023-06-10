#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <list> // for list
#include <text_utils/line.hpp> // for Line
#include <text_utils/text_iterator.hpp> // for Text_iterator

// class that represents a Document as a list of lines
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

#endif
