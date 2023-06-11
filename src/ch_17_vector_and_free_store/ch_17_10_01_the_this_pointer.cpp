// program tests the implementation of a link class that can be used to build
// up a doubly linked list of strings, as well as several methods for working
// with the list
//
// link (class)
//      string value
//      link(string const& v, link *p = nullptr, link *n = nullptr)
//      link *insert(link *n)
//      link *find(string const& s)
//      link *get_next() const
//      link *erase()
//
// void print_all(link *p)
//
// NOTE: implementation does not deallocate dynamically allocated links

#include <iostream> // for cout

// to dislable the struct-defined link class
#ifndef LINK_STR_CLASS
#define LINK_STR_CLASS
#endif

#include "link_str_utils.hpp" // for link, print_all()

int main()
{
    using std::cout;

    // create a link
    link *norse_gods = new link("Thor");
    
    // use link's insert() method to build a list of links
    norse_gods = norse_gods->insert(new link("Odin"));
    norse_gods = norse_gods->insert(new link("Zeus"));
    norse_gods = norse_gods->insert(new link("Freia"));

    // create a link
    link *greek_gods = new link("Hera");
    
    // use link's insert() method to build a list of links
    norse_gods = norse_gods->insert(new link("Odin"));
    greek_gods = greek_gods->insert(new link("Athena"));
    greek_gods = greek_gods->insert(new link("Mars"));
    greek_gods = greek_gods->insert(new link("Poseidon"));

    // display both lists
    print_all(norse_gods);
    cout << "\n\n";

    print_all(greek_gods);
    cout << "\n\n";

    // the Greek god of war is Ares.. not Mars, so update the link containing
    // the value of Mars to be Ares
    link *p = greek_gods->find("Mars"); // find link whose value is Mars
    if (p != nullptr)
        p->value = "Ares";

    // move Zeus into correct pantheon
    {
        // Zeus is not a Norse god, so remove that link for the list of Norse
        // gods, and insert it into the list of Greek gods
        link *p = norse_gods->find("Zeus"); // find link whose value is Zeus
        if (p != nullptr)
        {
            if (p == norse_gods) // if found link is the starting link
                // set starting link to found link's next pointer
                norse_gods = p->get_next();
            p->erase(); // remove link
            greek_gods = greek_gods->insert(p); // insert link into Greek gods
        }
    }

    // display updated lists
    print_all(norse_gods);
    cout << "\n\n";

    print_all(greek_gods);
    cout << "\n\n";

    return 0;
}
