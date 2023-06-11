#include "link_str_utils.hpp"

#include <iostream> // for cout

// displays the contents of a list starting from link p
void print_all(link *p)
{
    // walk links starting from p and write each Line's value to stdout
    std::cout << "{ ";
    while (p != nullptr)
    {
        std::cout << p->value;
        if ((p = p->next) != nullptr)
            std::cout << ", ";
    }

    std::cout << " }";
}
