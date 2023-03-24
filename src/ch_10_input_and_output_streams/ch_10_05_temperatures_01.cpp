// program defines a structure for representing hourly temperature readings.
// then it reads temperature readings from an input file and writes them to an
// output file

#include <iostream> // I/O library header
#include <fstream> // file I/O library
#include <string> // string library header
#include <vector> // vector library header
#include <stdexcept> // provides convenience classes for logic and runtime errors
#include "std_lib_facilities.hpp" // project header containing header functions
using namespace std;  // add names from std namespace to global namespace

// structure representing a temperature reading
struct Reading {
    int hour;
    double temperature;
    Reading(int h, double t)
        : hour(h), temperature(t){}
};

int main()
{
    try
    {
        cout << "Please enter input file name: ";

        string name;
        cin >> name; // read file name

        // create an input file stream object to read the file
        ifstream ist(name.c_str());

        // test if file was opened successfully
        if (!ist)
            error("can't open input file ", name);

        cout << "Please enter name of output file: ";
        cin >> name;

        // create an output file stream object to write to the file
        ofstream ost(name.c_str());

        // test if file was opended successfully
        if (!ost)
            error("can't open output file ", name);

        vector<Reading> temps; // to store data read from file
        
        // data memebers to read
        int hour;
        double temperature;

        // read data from input file
        while (ist >> hour >> temperature)
        {
            if (hour < 0 || 23 < hour) // validate hour
                error("hour out of range");
            // add temperature reading to temps vector
            temps.push_back(Reading(hour, temperature));
        }

        // write each reading in temps vector to output file
        for (size_t i = 0; i < temps.size(); i++)
            ost << '(' << temps[i].hour << ',' << temps[i].temperature << ')'
                << endl;
    }
    catch (exception& ex)
    {
        cerr << "error: " << ex.what() << endl;
        return 1;
    }
    catch (...)
    {
        cerr << "unknown exception" << endl;
        return 2;
    }
}
