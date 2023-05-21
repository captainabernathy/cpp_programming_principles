// program implements a function that fills a dynamically allocated array of
// doubles and returns a pointer to it, as well as a function that fills a
// dynamically allocated vector of doubles and returns a pointer to it.
// next the program determines the largest element in each

#include <iostream> // for cout
#include <vector>  // for vector

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

// tests get_from_jack() and get_from_jill()
void fct();

int main()
{
    fct();
    return 0;
}

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

std::vector<double> *get_from_jill()
{
    const size_t n = 10;

    // allocate pointer to a vector of 10 doubles
    std::vector<double>* arr = new std::vector<double>(n);

    if (arr)  // fill vector if allocation was successful
    {
        for (size_t i = 0; i < n; i++)  // fill vector
        {
            // (*arr)[i] = i * 1.2;
            arr->push_back(i * 1.2);
        }
    }

    return arr;  // return pointer to vector
}

void fct()
{
    size_t jack_count = 0;

    // jack will receive a pointer to a dynamically allocated array of doubles,
    // and jack_count will be updated with the number of elements in the
    // returned array
    double *jack_data = get_from_jack(&jack_count);
    
    // jill will receive a pointer to a dynamically allocated vector of doubles
    std::vector<double>* jill_data = get_from_jill();

    double h = -1.0;
    double *jack_high;
    double *jill_high;

    for (size_t i = 0; i < jack_count; i++)
        if (h < jack_data[i])
        {
            // NOTE: &jack_data[i] == &*(jack_data + i) == (jack_data + i)
            jack_high = &jack_data[i];  // update jack high
            h = jack_data[i]; // update high
        }

    h = -1.0;
    for (size_t i = 0; i < jill_data->size(); i++)
        if (h < (*jill_data)[i])
        {
            // jill_high = &(*jill_data)[i];  // update jill high
            // h = (*jill_data)[i];

            // NOTE: the function call () and pointer access -> operators
            // both have higher precedence than the address of operator &
            jill_high = &jill_data->at(i);
            h = jill_data->at(i);
        }

    std::cout << "Jill's max: " << *jill_high << '\n';
    std::cout << "Jack's max: " << *jack_high << '\n';

    delete[] jack_data; // return memory allocated for jack
    delete jill_data; // return memory allocated for jill
}
