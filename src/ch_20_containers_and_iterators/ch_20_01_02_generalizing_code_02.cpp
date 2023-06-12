// program tests the implementation of the function get_from_jack(), which
// fills a dynamically allocated array of doubles and returns a pointer to it,
// as well as the function get_from_jill() which fills a dynamically allocated
// vector of doubles and returns a pointer to it.
//
// additionally, program implements a function that takes pointers to the first
// and last elements in a collection of doubles, finds the largest double in
// the collection, and returns a pointer to the element
//
// double *get_from_jack(size_t *count);
//
// vector<double> *get_from_jill();

#include <vector>  // for vector
#include <iostream> // for cout
#include "jack_and_jill.hpp" // for get_from_jack(), get_from_jill()

// takes pointers to first and last elements in a collection of doubles and
// returns a pointer to the element in [first, last) that has the highest value
double *high(double *first, double *last);

// tests get_from_jack(), get_from_jill(), and high()
void fct();

int main()
{
    fct();

    return 0;
}

double *high(double *first, double *last)
{
    double h = -1.0;
    double *high; // pointer for highest element

    // iterate over collection
    for (double *p = first; p != last; p++)
        if (h < *p)
        {
            high = p; // update high
            h = *p; // update test value for next iteration
        }
    return high; // return highest element
}

void fct()
{
    size_t jack_count = 0;
    double *jack_data = get_from_jack(&jack_count);
    std::vector<double> *jill_data = get_from_jill();

    // NOTE: jack_data = pointer to first element returned from get_from_jack()
    // jack_data + jack_count = pointer to last element returned from
    // get_from_jack()
    double *jack_high = high(jack_data, jack_data + jack_count);

    std::vector<double>& v = *jill_data; // reference to jill's data

    // double *jill_high = high(&(*jill_data)[0],
    //                          &(*jill_data)[0] + jill_data->size());

    // double *jill_high = high(&jill_data->front(),
    //                          &jill_data->front() + jill_data->size());
    
    // more simply
    double *jill_high = high(&v[0], &v[0] + v.size());

    std::cout << "Jill's max: " << *jill_high << '\n';
    std::cout << "Jack's max: " << *jack_high << '\n';

    delete[] jack_data; // return memory allocated for jack
    delete jill_data; // return memory allocated for jill
}
