// program tests the implementation of the function get_from_jack(), which
// fills a dynamically allocated array of doubles and returns a pointer to it,
// as well as the function get_from_jill() which fills a dynamically allocated
// vector of doubles and returns a pointer to it.
//
// program also tests the implementation of a function template that takes
// pointers (iterators) to the first and last elements of an iterable
// colletion and returns a pointer (iterator) to the largest element in the
// collection
//
// double *get_from_jack(size_t *count);
//
// vector<double> *get_from_jill();
//
// template<typename T>
// T high(T first, T last)

#include <vector>  // for vector
#include <iostream> // for cout
#include "jack_and_jill.hpp" // for get_from_jack(), get_from_jill()
#include "high.hpp" // for high<>()

// tests get_from_jack(), get_from_jill(), and high<>()
void fct();

int main()
{
    fct();

    return 0;
}

// tests get_from_jack(), get_from_jill(), and high<>()
void fct()
{
    size_t jack_count = 0;
    double *jack_data = get_from_jack(&jack_count);
    std::vector<double> *jill_data = get_from_jill();

    // NOTE: jack_data = pointer to first element returned from get_from_jack()
    // jack_data + jack_count = pointer to last element returned from
    // get_from_jack()
    double *jack_high = high(jack_data, jack_data + jack_count);

    std::vector<double> &v = *jill_data; // reference to jill's data

    double *jill_high = high(&v[0], &v[0] + v.size());

    std::cout << "Jill's high: " << *jill_high << '\n';
    std::cout << "Jack's high: " << *jack_high << '\n';

    delete[] jack_data; // return memory allocated for jack
    delete jill_data; // return memory allocated for jill
}
