#ifndef JACK_AND_JILL_HPP
#define JACK_AND_JILL_HPP

#include <cstddef> // for size_t
#include <vector> // for vector

// jack fills a dynamically allocated array of doubles and returns it. the
// number of elements contained in the array will be returned through the
// pointer it receives
// NOTE: function returns a dynamically allocated pointer to *count doubles, so
// remember to delete it when done
double *get_from_jack(size_t *count);

// jill fills a vector and returns a pointer to it
// NOTE: function returns a dynamically allocated pointer to a vector of
// doubles, so remember to delete it when done
std::vector<double> *get_from_jill();

#endif
