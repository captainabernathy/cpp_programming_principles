#include <iostream> // I/O library header
#include <vector>  // vector library header
using namespace std;

// jack puts doubles into an array and returns the number of elements in
// *count
// NOTE: function returns a dynamically allocated pointer to *count doubles, so
// remember to delete it when done
double *get_from_jack(int *count);

// jill fills a vector and returns it
// NOTE: function returns a dynamically allocated pointer to a vector of
// doubles, so remember to delete it when done
vector<double> *get_from_jill();

// tests get_from_jack() and get_from_jill()
void fct();

int main()
{
    fct();
    return 0;
}

double *get_from_jack(int *count)
{
    if (!count)  // return 0 if count is NULL
        return 0;

    const int n = 10;
    double *arr = new double[n];  // allocate array of 10 doubles

    if (arr) // if allocation was successful, fill array
    {
        *count = n; // update the count

        for (size_t i = 0; i < n; i++) // fill array
            arr[i] = i;
    }

    return arr; // return array
}

vector<double> *get_from_jill()
{
    const int n = 10;

    // allocate pointer to a vector of 10 doubles
    vector<double>* arr = new vector<double>(n);

    if (arr)  // fill vector if allocation was successful
    {
        for (size_t i = 0; i < n; i++)  // fill vector
            (*arr)[i] = i;
    }

    return arr;  // return pointer to vector
}

void fct()
{
    int jack_count = 0;
    // jack will receive a pointer to an dynamically allocated array of doubles
    double *jack_data = get_from_jack(&jack_count);
    // jill will receive a pointer to a dynamically allocated vector of doubles
    vector<double>* jill_data = get_from_jill();

    double h = -1;
    double *jack_high;
    double *jill_high;

    for (int i = 0; i < jack_count; i++)
        if (h < jack_data[i])
            jack_high = &jack_data[i];  // update jack high

    h = -1;
    for (size_t i = 0; i < jill_data->size(); i++)
        if (h < (*jill_data)[i])
            jill_high = &(*jill_data)[i];  // update jill high

    cout << "Jill's max: " << *jill_high << endl;
    cout << "Jack's max: " << *jack_high << endl;

    delete[] jack_data; // return memory allocated for jack
    delete jill_data; // return memory allocated for jill
}
