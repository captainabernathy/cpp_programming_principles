#ifndef READ_WORD_HPP
#define READ_WORD_HPP

#include <istream> // for istream

// function reads at most max-1 characters from is into buffer, which will be
// null-terminated
std::istream& read_word(std::istream& is, char *buffer, int max);

#endif
