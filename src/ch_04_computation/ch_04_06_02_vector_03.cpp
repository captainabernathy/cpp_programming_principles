// program demonstrates various common vector operations as well as the usage of
// C++'s standard sorting algorithm as it computes the mean and median of a
// vector of doubles

#include <iostream> // for cin, cout
#include <algorithm> // for sort()
#include <vector> // for vector

int main()
{
    using std::vector;
    using std::cout;
    using std::cin;
    using std::sort;

    // empty vector of doubles
    vector<double> temps;
    double temp; // variable used to fill store values added to vector

    cout << "Enter double values (or CTRL-D when done): "; // prompt user
    while (cin >> temp) // read double into temp
    {
        temps.push_back(temp); // write temp to vector
        cout << "Enter double values (or CTRL-D when done): "; // prompt user
    }

    // iterate over vector and accumulate the sum of its values
    double sum = 0;
    for (unsigned int i = 0; i < temps.size(); i++)
        sum += temps[i];

    // write average vector value to stdout
    cout << "Average temperature: " << sum / temps.size() << '\n';

    // compute median temperature...
    // default sort... provied by algorithm library
    // requires iterator to first and last elements in the range of the
    // container to be sorted
    sort(temps.begin(), temps.end());

    // write median vector value to stdout
    cout << "Median temperature: " << temps[temps.size() / 2] << '\n';

    return 0;
}
