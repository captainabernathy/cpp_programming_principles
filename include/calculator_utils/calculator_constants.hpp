#ifndef CALCULATOR_CONSTANTS_HPP
#define CALCULATOR_CONSTANTS_HPP

#include <string> // for string

// symbolic constants used to reduce the number of hard-coded values in the
// Calculator class
constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
const std::string prompt = "> ";
const std::string result = "= ";

// not defined when a Calculator supports declarations
#ifndef NO_DECL
constexpr char name = 'a';
constexpr char let = 'L';
const std::string declkey = "let";
#endif

#endif
