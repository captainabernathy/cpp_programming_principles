#include "jack_and_jill.hpp"

// jack fills a dynamically allocated array of doubles and returns it. the
// number of elements contained in the array will be returned through the
// pointer it receives
// NOTE: function returns a dynamically allocated pointer to *count doubles, so
// remember to delete it when done
double *get_from_jack(size_t *count)
{
    if (!count)  // return 0 if count is NULL
        return 0;

    const size_t n = 10;
    double *arr = new double[n];  // allocate array of 10 doubles

    if (arr) // if allocation was successful, fill array
    {
        *count = n; // update the count
        for (size_t i = 0; i < n; i++) // fill array
            arr[i] = i * 1.1;
    }

    return arr; // return array
}

// jill fills a vector and returns a pointer to it
// NOTE: function returns a dynamically allocated pointer to a vector of
// doubles, so remember to delete it when done
std::vector<double> *get_from_jill()
{
    const size_t n = 10;

    // allocate pointer to a vector of 10 doubles
    std::vector<double>* arr = new std::vector<double>(n);

    if (arr)  // fill vector if allocation was successful
    {
        for (size_t i = 0; i < n; i++)  // fill vector
            // (*arr)[i] = i * 1.2;
            arr->push_back(i * 1.2);
    }

    return arr;  // return pointer to vector
}
