// program demonstrates the importance of proper variable initializations in
// preventing potential logic errors

#include <iostream> // I/O library header
using namespace std;  // add names from std namespace to global namespace

int main()
{
    double temp; // placeholder variable for reading input
    double sum = 0; // accumulates the sum of inputs
    double high_temp = -1000; // initialize to impossibly low
    double low_temp = 1000; // initialize to impossibly high
    int num_temps = 0; // counter

    cout << "Enter a temperature or CTRL-D to exit: ";
    while (cin >> temp) // read temp
    {
        num_temps++;    // count temps
        sum += temp;    // compute sum
        if (temp > high_temp)
            high_temp = temp;   // find high
        if (temp < low_temp)
            low_temp = temp;    // find low
        cout << "Enter a temperature or CTRL-D to exit: ";
    }

    // write high, low, and average temperatures to stdout
    cout << "High temperature: " << high_temp << endl;
    cout << "Low temperature: " << low_temp << endl;
    cout << "Average temperature: " << sum/num_temps << endl;

    return 0;
}
