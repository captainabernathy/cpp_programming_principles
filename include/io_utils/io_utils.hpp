#ifndef IO_UTILS_HPP
#define IO_UTILS_HPP

// provides:
// bad_fron_string (class)
// bad_lexical_cast (class)
#include <io_utils/io_errors.hpp>

// provides:
// template<typename T>
// string to_string(T t)
//
// template<typename T>
// T from_string(string s)
//
// template<typename Dest, typename Src>
// Dest lexical_cast(Src source)
#include <io_utils/io_conversion.hpp>

// provides:
// istream& read_word(istream& is, char * buffer, int max)
#include <io_utils/read_word.hpp>

// provides:
// double str_to_double(string s)
#include <io_utils/str_to_double.hpp>

#endif
