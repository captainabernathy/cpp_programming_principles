#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <string> // for string

// class that represents a Variable as string and a double
class Variable {
public:
    std::string name;
    double value;
    
    // builds a Variable with name n and value v
    Variable(std::string n, double v)
        : name {n},
          value {v} { }
};

#endif
