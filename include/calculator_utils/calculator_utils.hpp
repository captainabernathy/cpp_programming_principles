#ifndef CALCULATOR_UTILS_HPP
#define CALCULATOR_UTILS_HPP

// provides:
// Calculator (class)
//      Calculator()
//      double get_value(string var)
//      bool is_declared(string var)
//      double define_name(string var, double val)
//      void set_value(string var, double val)
//
// Token (class)
//      char kind
//      double value
//      string name
//      Token(char ch)
//      Token(char ch, double val)
//      Token(char ch, string str)
//
// Token_stream (class)
//      Token_stream()
//      Token get()
//      void putback(Token t)
//      void ignore(char ch)
//
// Variable
//      string name
//      double value
//      Variable(string n, double v)
#include <calculator_utils/calculator.hpp>

#endif
