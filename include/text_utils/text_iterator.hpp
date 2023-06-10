#ifndef TEXT_ITERATOR_HPP
#define TEXT_ITERATOR_HPP

#include <list> // for list
#include <text_utils/line.hpp> // for Line
#include <iterator> // for forward_iterator_tag


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
    Text_iterator(std::list<Line>::iterator li_iter, Line::iterator pos_iter)
        : line_iter {li_iter}, position_iter {pos_iter}
    { }

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
    Text_iterator& operator++()
    {
        ++position_iter; // advance to next character

        // upon reaching the end of the Line...
        // advance to the next Line, and...
        // set position_iter to the beginning of the next Line
        if (position_iter == line_iter->end()) // at end of line?
        {
            ++line_iter;
            position_iter = line_iter->begin();
        }

        return *this;
    }
};

#endif
