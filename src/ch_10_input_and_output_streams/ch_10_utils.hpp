#ifndef CH_10_UTILS_HPP
#define CH_10_UTILS_HPP

#include <string>

// utility function for recovering after seeing a bad/unexpected character
void skip_to_int();

// function that reads an integer from cin and returns the result
int get_int();

// function that reads an integer within the range of low and high from cin and
// returns the result
int get_int(int low, int high);

// function that reads an integer with the range of low and high from cin using
// the custom prompt and error messages as prompts to the user and returns
// the result
int get_int(int low, int high, std::string const& prompt,
            std::string const& err_msg);

#endif
