// program implements a function that fills a dynamically allocated array of
// doubles and returns a pointer to it, as well as a function that fills a
// dynamically allocated vector of doubles and returns a pointer to it.
//
// additionally, program implements a template function that takes
// pointers (iterators) to the first and last elements of an iterable
// colletion and returns a pointer (iterator) to the largest element in the
// collection

#include <iostream> // I/O library header
#include <vector>  // vector library header
using namespace std;

// template function that returns an iterator to the element in a collection
// between first and last... [first, last)... that has the highest value
template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
    // assume value of first iteraor is the highest in the range
    Iterator high = first;
    for (Iterator p = first; p != last; p++) // iterate over range
        if (*high < *p) // update high if value at current high is less than
            high = p;   // value at current iterator
    return high; // return iterator to highest element in range
}

// jack fills a dynamically allocated array of doubles and returns it. the
// number of elements contained in the array will be returned through the
// pointer it receives
// NOTE: function returns a dynamically allocated pointer to *count doubles, so
// remember to delete it when done
double *get_from_jack(int *count);

// jill fills a vector and returns a pointer to it
// NOTE: function returns a dynamically allocated pointer to a vector of
// doubles, so remember to delete it when done
vector<double>* get_from_jill();

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

vector<double> *get_from_jill()
{
    const int n = 10;

    // allocate pointer to vector of 10 doubles
    vector<double> *arr = new vector<double>(n);

    if (arr) // fill vector if allocation was successful
    {
        for (size_t i = 0; i < n; i++) // fill vector
            // (*arr)[i] = i;
            arr->push_back(i * 1.2);
    }

    return arr; // return pointer to vector
}

void fct()
{
    int jack_count = 0;
    double *jack_data = get_from_jack(&jack_count);
    vector<double> *jill_data = get_from_jill();

    // NOTE: jack_data = pointer to first element returned from get_from_jack()
    // jack_data + jack_count = pointer to last element returned from
    // get_from_jack()
    double *jack_high = high(jack_data, jack_data + jack_count);

    vector<double> &v = *jill_data; // reference to jill's data

    double *jill_high = high(&v[0], &v[0] + v.size());

    cout << "Jill's high: " << *jill_high << endl;
    cout << "Jack's high: " << *jack_high << endl;

    delete[] jack_data; // return memory allocated for jack
    delete jill_data; // return memory allocated for jill
}
