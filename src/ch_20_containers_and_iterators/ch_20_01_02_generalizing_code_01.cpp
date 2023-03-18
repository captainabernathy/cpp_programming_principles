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
vector<double>* get_from_jill();

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

    if (arr) // fill array if allocation was successful
    {
        *count = n; // update count
        for (int i = 0; i < n; i++) // fill array
            arr[i] = i;
    }

    return arr; // return array
}

vector<double>* get_from_jill()
{
    const int n = 10;

    // allocate pointer to vector of 10 doubles
    vector<double>* arr = new vector<double>(n);

    if (arr) // fill vector if allocation was successful
    {
        for (size_t i = 0; i < n; i++) // fill vector
            (*arr)[i] = i;
    }

    return arr; // return pointer to vector
}

void fct()
{
    int jack_count = 0;
    // jack gets a pointer to a dynamically allocated array of doubles
    double *jack_data = get_from_jack(&jack_count);
    // gill gets a pointer to a dynamically allocated vector of doubles
    vector<double> *jill_data = get_from_jill();
    double h = -1;
    double *jack_high;
    double *jill_high;

    for (int i = 0; i < jack_count; i++)
        if (h < jack_data[i])
            jack_high = &jack_data[i]; // save address of largest element

    h = -1;
    vector<double>& v = *jill_data; // instead of accessing jill_data directly
    for (size_t i = 0; i < v.size(); i++)
        if (h < v[i])
            jill_high = &v[i];

    cout << "Jill's max: " << *jill_high << endl;
    cout << "Jack's max: " << *jack_high << endl;

    delete[] jack_data; // return memory allocated for jack
    delete jill_data; // return memory allocated for jill
}
