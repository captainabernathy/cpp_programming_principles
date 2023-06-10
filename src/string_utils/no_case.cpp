#include <string_utils/string_utils.hpp>

#include <string> // for string
#include <cctype> // for tolower()

// function object that performs a case-insensitive comparison between two
// strings...
// returns true when x comes before y, false otherwise
bool No_case::operator()(std::string const& x, std::string const& y) const
{
    // loop over first string
    for (size_t i = 0; i < x.length(); i++)
    {
        if (i == y.length())
            return false; // y < x... (fewer characters in y)

        char xx = tolower(x[i]);
        char yy = tolower(y[i]);

        if (xx < yy)
            return true; // x < y

        if (yy < xx)
            return false; // y < x
    }

    if (x.length() == y.length())
        return false; // x == y

    return true; // x < y (fewer characters in x)
}
