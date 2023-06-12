// program tests the implementation of the function get_from_jack(), which
// fills a dynamically allocated array of doubles and returns a pointer to it,
// as well as the function get_from_jill() which fills a dynamically allocated
// vector of doubles and returns a pointer to it.
//
// double *get_from_jack(size_t *count);
//
// vector<double> *get_from_jill();

#include <vector>  // for vector
#include <iostream> // for cout
#include "jack_and_jill.hpp" // for get_from_jack(), get_from_jill()

// tests get_from_jack() and get_from_jill()
void fct();

int main()
{
    fct();

    return 0;
}

// tests get_from_jack() and get_from_jill()
void fct()
{
    size_t jack_count = 0;

    // jack will receive a pointer to a dynamically allocated array of doubles,
    // and jack_count will be updated with the number of elements in the
    // returned array
    double *jack_data = get_from_jack(&jack_count);

    // jill will receive a pointer to a dynamically allocated vector of doubles
    std::vector<double> *jill_data = get_from_jill();

    double h = -1.0;
    double *jack_high;
    double *jill_high;

    for (size_t i = 0; i < jack_count; i++)
        if (h < jack_data[i])
        {
            jack_high = &jack_data[i]; // save address of largest element
            h = jack_data[i];
        }

    h = -1.0;
    // instead of accessing jill_data directly
    std::vector<double>& v = *jill_data;
    for (size_t i = 0; i < v.size(); i++)
        if (h < v[i])
        {
            // jill_high = &v.at(i);
            // h = v.at(i);
            jill_high = &v[i];
            h = v[i];
        }
    std::cout << "Jill's max: " << *jill_high << '\n';
    std::cout << "Jack's max: " << *jack_high << '\n';

    delete[] jack_data; // return memory allocated for jack
    delete jill_data; // return memory allocated for jill
}
