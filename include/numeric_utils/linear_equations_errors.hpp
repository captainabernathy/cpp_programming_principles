#ifndef LINEAR_EQUATIONS_ERRORS_HPP
#define LINEAR_EQUATIONS_ERRORS_HPP

#include <stdexcept> // for domain_error
#include <string> // for string

// class for throwing when an error occurs during the elimination step of
// solving a system of linear equations
struct Elim_failure : std::domain_error {
    Elim_failure(std::string s)
        : std::domain_error {s} { }
};

// class for throwing when an error occurs during the back substitution step of
// solving a system of linear equations
struct Back_subst_failure : std::domain_error {
    Back_subst_failure(std::string s)
        : std::domain_error {s} {  }
};

#endif
