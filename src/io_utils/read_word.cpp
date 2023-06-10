#include <io_utils/read_word.hpp>

#include <istream> // for istream

// function reads at most max-1 characters from is into buffer, which will be
// null-terminated
std::istream& read_word(std::istream& is, char *buffer, int max)
{
    is.width(max); // read at most max-1 characters in the next input operation
    is >> buffer; // read whitespace-terminated word, and add \0 after the last
                  // character read into the buffer
    return is;
}
