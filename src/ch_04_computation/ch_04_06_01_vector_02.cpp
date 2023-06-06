// program demonstrates how to fill a vector using its push_back() method

#include <vector> // for vector
#include <iostream> // for cout

int main()
{
    using std::vector;
    using std::cout;

    // declare a vector of doubles
    vector<double> v;

    // use vector's push_back() method to add values to it
    v.push_back(2.7);
    v.push_back(5.6);
    v.push_back(7.9);

    // iterate over the vector and display the results
    for (size_t i = 0; i < v.size(); i++)
        cout << "v[" << i << "] == " << v[i] << '\n';

    return 0;
}
