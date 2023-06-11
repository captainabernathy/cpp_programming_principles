// program tests the implementation of a link class that can be used to build
// up a doubly linked list of strings, as well as several functions for
// working with the list
//
// link (class)
//      string value
//      link(string const& s, link *p = nullptr, link *n = nullptr)
//
// link *insert(link *p, link *n)
// link *add(link *p, link *n)
// link *erase(link *p)
// link *find(link *p, string const& s)
// void print_all(link *p)
//
// NOTE: implementation does NOT deallocate dynamically allocated resources

#include <iostream> // for cout
#include "link_str_utils.hpp" // for link, print_all()

int main()
{
    using std::cout;

    // create a link... for a list of Norse gods
    link *norse_gods = new link("Thor");

    // build a list of links with insert()
    // NOTE: insert(p, n) inserts p after n and returns n, so successive calls
    // create a stack where the link returned is the top of the stack
    norse_gods = insert(norse_gods, new link("Odin"));
    norse_gods = insert(norse_gods, new link("Zeus"));
    norse_gods = insert(norse_gods, new link("Freia"));

    // create a link... for a list of Greek  gods
    link *greek_gods = new link("Hera");
    
    // build a list of links with insert()
    greek_gods = insert(greek_gods, new link("Athena"));
    greek_gods = insert(greek_gods, new link("Mars"));
    greek_gods = insert(greek_gods, new link("Poseidon"));

    // display both lists
    print_all(norse_gods);
    cout << "\n\n";

    print_all(greek_gods);
    cout << "\n\n";

    // the Greek god of war is Ares.. not Mars, so update the link containing
    // the value of Mars to be Ares
    link *p = find(greek_gods, "Mars"); // find link whose value is Mars
    if (p != nullptr)
    {
        cout << p->value << '\n';
        p->value = "Ares"; // change value of link to Ares
        cout << p->value << '\n';
    }
    cout << '\n';

    // the deletion below does not properly account for the removal of a
    // link at the head of the list
    // {
    //     link *p = find(norse_gods, "Zeus");
    //     if (p != nullptr)
    //     {
    //         erase(p);
    //         insert(greek_gods, p);
    //     }
    // }

    {
        // Zeus is not a Norse god, so remove that link for the list of Norse
        // gods, and insert it into the list of Greek gods
        link *p = find(norse_gods, "Zeus"); // find link whose value is Zeus
        if (p != nullptr)
        {
            if (p == norse_gods) // if found link is the starting link
                // set starting link to found link's next pointer
                norse_gods = p->next;

            erase(p); // remove link
            greek_gods = insert(greek_gods, p); // insert link into Greek gods
        }
    }

    // display updated lists
    print_all(norse_gods);
    cout << "\n\n";
    print_all(greek_gods);
    cout << "\n\n";


    link *Thor = new link("Thor");
    link *norse_gods1 = Thor; // keep a pointer to the start of the list

    // NOTE: add(p,n) inserts n after p and returns n, so successive calls
    // create a queue where the link return is at the bottom of the queue
    // So, if we didn't keep a pointer to the top of the queue, we'd have to
    // follow the last link's prev pointer up to the start of the list to
    // get there
    link *ng_bottom  = add(norse_gods1, new link("Odin"));
    ng_bottom  = add(ng_bottom, new link("Zeus"));
    ng_bottom = add(ng_bottom, new link("Freia"));

    link *Hera = new link("Hera");
    link *greek_gods1 = Hera; // keep a pointer to the start of the list
    link *gg_bottom = add(greek_gods1, new link("Athena"));
    gg_bottom = add(gg_bottom, new link("Mars"));
    gg_bottom = add(gg_bottom, new link("Poseidon"));

    print_all(norse_gods1);
    cout << "\n\n";
    print_all(greek_gods1);
    cout << "\n\n";

    {
        link *p = find(greek_gods1, "Mars");
        if (p != nullptr)
        {
            cout << p->value << '\n';
            p->value = "Ares";
            cout << p->value << '\n';
        }
        cout << '\n';
    }
    
    {
        link *p = find(norse_gods1, "Zeus");
        if (p != nullptr)
        {
            if (p == norse_gods1)
                norse_gods1 = p->next;

            erase(p);
            greek_gods1 = insert(greek_gods1, p);
        }
    }

    print_all(norse_gods1);
    cout << "\n\n";

    print_all(greek_gods1);
    cout << "\n\n";

    return 0;
}
