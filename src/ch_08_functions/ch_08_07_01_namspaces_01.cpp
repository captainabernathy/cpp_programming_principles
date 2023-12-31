// program demonstrates how to qualify names that belong to a namespace

#include <string> // for string
#include <iostream> // for cin, cout, endl

int main()
{
    // it's necessary to qualify names in the standard library when they are not
    // included with a using declaration
    std::string name;
    std::cout << "Please enter your first name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << std::endl;

    return 0;
}
