#ifndef TEXT_UTILS_HPP
#define TEXT_UTILS_HPP

// provides:
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
#include <text_utils/text_iterator.hpp> // for Text_iterator

#include <string> // for string

// determines if the text between first and last match the string s
bool match(Text_iterator first, Text_iterator last, std::string const& s);

// returns a Text_iterator to the first character if string s exists between
// first and last... or an iterator to the end of the sequence when it does
// not
Text_iterator find_text(Text_iterator first, Text_iterator last,
    std::string const& s);

#endif
