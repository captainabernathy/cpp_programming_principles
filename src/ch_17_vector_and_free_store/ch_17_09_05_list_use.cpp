// program implements a Link struct that can be used to build up a doubly
// linked list of strings.
// it also implements several functions for manipulating such a list.
//
// NOTE: implementation does NOT deallocate dynamically allocated resources

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std;  // add names from std namespace to global namespace

// a struct used to build an ad-hoc doubly linked list of strings
struct Link {
    string value; // value at this Link
    Link *prev; // pointer to previous Link
    Link *next; // pointer to next Link

    // constructor sets this Link's value to v and its previous and next Links
    // to nullptr by default if they are not supplied by the caller
    Link(const string& v, Link *p = nullptr, Link *n = nullptr)
        : value(v), prev(p), next(n) {  }
};

// insert Link n before Link p and return Link n
Link *insert(Link *p, Link *n);

// insert Link n after Link p and return Link n
Link *add(Link *p, Link *n);

// remove Link p from a list and return p->prev
Link *erase(Link *p);

// find String s in list Link(-ed list) p... return it if found, or nullptr if
// not
Link *find(Link *p, const string& s);

// move Link p, n positions in list... +n moves forward, -n moves backwards
Link* advance(Link *p, int n);

// display contents of list starting from Link p
void print_all(Link *p);

int main()
{
    // create a Link... for a list of Norse gods
    Link *norse_gods = new Link("Thor");

    // build a list of Links with insert()
    // NOTE: insert(p, n) inserts p after n and returns n, so successive calls
    // create a stack where the Link returned is the top of the stack
    norse_gods = insert(norse_gods, new Link("Odin"));
    norse_gods = insert(norse_gods, new Link("Zeus"));
    norse_gods = insert(norse_gods, new Link("Freia"));

    // create a Link... for a list of Greek  gods
    Link *greek_gods = new Link("Hera");
    
    // build a list of Links with insert()
    greek_gods = insert(greek_gods, new Link("Athena"));
    greek_gods = insert(greek_gods, new Link("Mars"));
    greek_gods = insert(greek_gods, new Link("Poseidon"));

    // display both lists
    print_all(norse_gods);
    cout << endl << endl;
    print_all(greek_gods);
    cout << endl << endl;

    // the Greek god of war is Ares.. not Mars, so update the Link containing
    // the value of Mars to be Ares
    Link *p = find(greek_gods, "Mars"); // find Link whose value is Mars
    if (p != nullptr)
    {
        cout << p->value << endl;
        p->value = "Ares"; // change value of Link to Ares
        cout << p->value << endl;
    }
    cout << endl;

    // the deletion below does not properly account for the removal of a
    // Link at the head of the list
    // {
    //     Link *p = find(norse_gods, "Zeus");
    //     if (p != nullptr)
    //     {
    //         erase(p);
    //         insert(greek_gods, p);
    //     }
    // }

    {
        // Zeus is not a Norse god, so remove that Link for the list of Norse
        // gods, and insert it into the list of Greek gods
        Link *p = find(norse_gods, "Zeus"); // find Link whose value is Zeus
        if (p != nullptr)
        {
            if (p == norse_gods) // if found link is the starting Link
                // set starting Link to found Link's next pointer
                norse_gods = p->next;

            erase(p); // remove Link
            greek_gods = insert(greek_gods, p); // insert Link into Greek gods
        }
    }

    // display updated lists
    print_all(norse_gods);
    cout << endl << endl;
    print_all(greek_gods);
    cout << endl << endl;


    Link *Thor = new Link("Thor");
    Link *norse_gods1 = Thor; // keep a pointer to the start of the list

    // NOTE: add(p,n) inserts n after p and returns n, so successive calls
    // create a queue where the Link return is at the bottom of the queue
    // So, if we didn't keep a pointer to the top of the queue, we'd have to
    // follow the last Link's prev pointer up to the start of the list to
    // get there
    Link *ng_bottom  = add(norse_gods1, new Link("Odin"));
    ng_bottom  = add(ng_bottom, new Link("Zeus"));
    ng_bottom = add(ng_bottom, new Link("Freia"));

    Link *Hera = new Link("Hera");
    Link *greek_gods1 = Hera; // keep a pointer to the start of the list
    Link *gg_bottom = add(greek_gods1, new Link("Athena"));
    gg_bottom = add(gg_bottom, new Link("Mars"));
    gg_bottom = add(gg_bottom, new Link("Poseidon"));

    print_all(norse_gods1);
    cout << endl << endl;
    print_all(greek_gods1);
    cout << endl << endl;

    {
        Link *p = find(greek_gods1, "Mars");
        if (p != nullptr)
        {
            cout << p->value << endl;
            p->value = "Ares";
            cout << p->value << endl;
        }
        cout << endl;
    }
    
    {
        Link *p = find(norse_gods1, "Zeus");
        if (p != nullptr)
        {
            if (p == norse_gods1)
                norse_gods1 = p->next;

            erase(p);
            greek_gods1 = insert(greek_gods1, p);
        }
    }

    print_all(norse_gods1);
    cout << endl << endl;
    print_all(greek_gods1);
    cout << endl << endl;

    return 0;
}

// insert Link n before Link p and return Link n
Link *insert(Link *p, Link *n)
{
    if (n == nullptr)
        return p;
    if (p == nullptr)
        return n;

    n->next = p; // set Link n's next pointer to Link p

    if (p->prev != nullptr)
        // set the next pointer of Link p's prev pointer to Link n
        p->prev->next = n;

    // set Link n's prev pointer to Link p's prev pointer
    n->prev = p->prev;
    
    // set Link p's prev pointer to Link n
    p->prev = n;
    return n;
}

// insert Link n after Link p and return Link n
Link *add(Link *p, Link *n)
{
    if (n == nullptr)
        return p;
    if (p == nullptr)
        return n;
   
    n->prev = p; // set Link n's prev pointer to Link p
    if (p->next != nullptr)
        // set the prev pointer of Link p's next pointer to Link n
        p->next->prev = n;

    // set Link n's next pointer to Link p's next pointer
    n->next = p->next;
    
    // set Link p's next pointer to Link n
    p->next = n;
    return n;
}

// remove Link p from a list and return p->next
Link *erase(Link *p)
{
    if (p == nullptr)
        return nullptr;

    if (p->next != nullptr) // there's a Link after Link p
        // set the prev pointer of Link p's next pointer to Link p's
        // prev pointer
        p->next->prev = p->prev;

    if (p->prev != nullptr) // there's a Link before Link p
        // set the next pointer of Link p's prev pointer to Link p's
        // prev pointer
        p->prev->next = p->next;

    return p->next;
}

// find String s in list Link(-ed list) p... return it if found, or nullptr if
// not
Link *find(Link *p, const string& s)
{
    while (p != nullptr)
    {
        if (p->value == s) // found value
            return p;
        p = p->next; // advance pointer to next Link
    }

    return nullptr;
}

// move Link p, n positions in list... +n moves forward, -n moves backwards
Link* advance(Link *p, int n)
{
    if (p == nullptr)
        return nullptr;

    // moving p forward
    if (0 < n)
    {
        while (n != 0)
        {
            if (p->next == nullptr)
                return nullptr;
            p = p->next; // move p forward and
            n--; // decrement n
        }
    }

    // moving p backwards
    if (n < 0)
    {
        while (n != 0)
        {
            if (p->prev == nullptr)
                return nullptr;
            p = p->prev; // move p backwards and
            n++; // increment n
        }
    }

    return p;
}

// display contents of list starting from Link p
void print_all(Link *p)
{
    // walk Links starting from p and write each value to stdout
    cout << "{ ";
    while (p != nullptr)
    {
        cout << p->value;
        if ((p = p->next) != nullptr)
            cout << ", ";
    }

    cout << " }";
}
