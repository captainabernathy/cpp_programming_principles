#ifndef YEAR_HPP
#define YEAR_HPP

// user-defined Year type
class Year {
    // private class members
    static const int min = 1800;
    static const int max = 2200;

public:
    // public attributes
    // embedded class for throwing
    class Invalid {};

    // public member functions
    // constructor
    Year(int y)
        : yr {y}
    {
        if (yr < min || max < yr) // input must fall within range of min and max
            throw Invalid();
    }

    // get value of year
    int year() { return yr; }

private:
    // private attributes
    int yr;
};

#endif
