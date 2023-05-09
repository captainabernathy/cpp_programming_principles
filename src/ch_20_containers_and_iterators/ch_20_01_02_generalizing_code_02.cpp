// program implements a function that fills a dynamically allocated array of
// doubles and returns a pointer to it, as well as a function that fills a
// dynamically allocated vector of doubles and returns a pointer to it.
//
// additionally, program implements a function that takes pointers to the
// first and last elements in a collection, finds the largest element in
// the collection, and returns a pointer to it
//
// program also assigns the pointer to the vector of doubles to a reference to
// a vector of doubles to simplify accessing it

#include <iostream> // I/O library header
#include <vector>  // vector library header

// jack fills a dynamically allocated array of doubles and returns it. the
// number of elements contained in the array will be returned through the
// pointer it receives
// NOTE: function returns a dynamically allocated pointer to *count doubles, so
// remember to delete it when done
double *get_from_jack(int *count);

// jill fills a vector and returns a pointer to it
// NOTE: function returns a dynamically allocated pointer to a vector of
// doubles, so remember to delete it when done
std::vector<double>* get_from_jill(); // jill fills the vector

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

double *get_from_jack(int *count)
{
    if (!count) // return 0 if count is NULL
        return 0;

    const int n = 10;
    double *arr = new double[n]; // allocate array of 10 doubles

    if (arr) // fill array if allocation was successful
    {
        *count = n; // update count
        for (int i = 0; i < n; i++) // fill array
            arr[i] = i * 1.1;
    }

    return arr; // return array
}

std::vector<double> *get_from_jill()
{
    const int n = 10;

    // allocate pointer to vector of 10 doubles
    std::vector<double> *arr = new std::vector<double>(n);

    if (arr) // fill vector if allocation was successful
    {
        for (size_t i = 0; i < n; i++) // fill vector
            // (*arr)[i] = i;
            arr->push_back(i * 1.2);
    }

    return arr; // return pointer to vector
}

double *high(double *first, double *last)
{
    double h = -1;
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
    int jack_count = 0;
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
