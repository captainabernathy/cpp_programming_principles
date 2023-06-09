#include "mail_file.hpp"

#include <string> // for string, getline()
#include <fstream> // for ifstream
#include <iostream> // for cerr, endl
#include <cstdlib> // for exit(), EXIT_FAILURE
#include "message.hpp" // for Line_iter


// conversion constructor... builds a mail file from a file
Mail_file::Mail_file(std::string const& file)
{
    std::ifstream ifs {file.c_str()}; // open file
    if (!ifs)
    {
        std::cerr << "failed to open " << file << std::endl;
        std::exit(EXIT_FAILURE);
    }

    name = file; // set name attribute

    // build up lines attribute
    std::string s;
    while (getline(ifs, s)) // read lines from the input stream to s
        lines.push_back(s); // build vector of lines

    // build up messages attributes
    Line_iter first = lines.begin(); // build vector of Messages
    for (Line_iter li = lines.begin(); li != lines.end(); ++li)
        if (*li == "----") // end of message
        {
            messages.push_back(Message(first, li));
            first = li + 1; // not part of message
        }
}
