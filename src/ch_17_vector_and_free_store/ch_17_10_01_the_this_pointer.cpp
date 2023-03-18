// program implements a Link class that can be used to build up a doubly
// linked list of strings.
// the Link class also provides several methods for manipulating such a list.
//
// NOTE: implementation does not deallocate dynamically allocated objects

#include <iostream> // I/O library header
#include <string> // string library header
using namespace std;  // add names from std namespace to global namespace

// a class used to build an ad-hoc doubly linked list of strings
class Link {
public:
    string value;

    Link(const string& v, Link *p = nullptr, Link *n = nullptr)
        : value(v), prev(p), next(n) {  }

    // insert Link n before this object and return a pointer to it
    Link *insert(Link *n);
    
    // remove this object from a list and return this->next
    Link *erase();
    
    // find Link whose value s in and return a pointer to it
    Link *find(const string& s);
   
    // finds s in list starting from this object and return a pointer to it
    const Link *find(const string& s) const;
   
    // move this object n positions in list... +n moves, -n moves backwards
    Link *advance(int n) const;

    // return pointer to this object's next Link
    Link *get_next() const { return next; }

    // return pointer to this object's previous Link
    Link *get_prev() const { return prev; }

private:
    Link *prev; // pointer to previous Link
    Link *next; // pointer to next Link
};

// insert Link n before this object and return a pointer to it
Link *Link::insert(Link *n)
{
    if (n == nullptr) // return this pointer if n is NULL
        return this;

    if (this == nullptr) // return n if this pointer is NULL
        return n;

    n->next = this; // set Link n's next pointer to this

    if (prev != nullptr)
        // set the next pointer of this object's prev pointer to Link n
        prev->next = n;

    // set Link n's prev pointer to this object's prev pointer
    n->prev = prev;
    
    // set this object's prev pointer to Link n
    prev = n;

    return n;
}

// remove this object from the list and return this->next
Link *Link::erase()
{
    if (this == nullptr)
        return nullptr;

    if (next != nullptr) // this object has Link after it
        // set the prev pointer of this object next pointer to this object's
        // prev pointer
        next->prev = prev;

    if (prev != nullptr) // this object has a Link before it
        // set the next pointer of this object prev pointer to this object's
        // next pointer
        prev->next = next;

    return next;
}

// find s in list
Link *Link::find(const string& s)
{
    Link *p = this; // start from this object

    while (p != nullptr)
    {
        if (p->value == s) // found value
            return p;
        p = p->next; // advance pointer to next Link
    }

    return nullptr;
}

// display contents of list
void print_all(Link *p)
{
    // walk Links starting from p and write each value to stdout
    cout << "{";
    while (p != nullptr)
    {
        cout << p->value;
        if ((p = p->get_next()) != nullptr)
            cout << ", ";
    }
    cout << "}";
}

int main()
{
    // create a Link
    Link *norse_gods = new Link("Thor");
    
    // use Link's insert() method to build a list of Links
    norse_gods = norse_gods->insert(new Link("Odin"));
    norse_gods = norse_gods->insert(new Link("Zeus"));
    norse_gods = norse_gods->insert(new Link("Freia"));

    // create a Link
    Link *greek_gods = new Link("Hera");
    
    // use Link's insert() method to build a list of Links
    norse_gods = norse_gods->insert(new Link("Odin"));
    greek_gods = greek_gods->insert(new Link("Athena"));
    greek_gods = greek_gods->insert(new Link("Mars"));
    greek_gods = greek_gods->insert(new Link("Poseidon"));

    // display both lists
    print_all(norse_gods);
    cout << endl << endl;
    print_all(greek_gods);
    cout << endl << endl;

    // the Greek god of war is Ares.. not Mars, so update the Link containing
    // the value of Mars to be Ares
    Link *p = greek_gods->find("Mars"); // find Link whose value is Mars
    if (p != nullptr)
        p->value = "Ares";

    // move Zeus into correct pantheon
    {
        // Zeus is not a Norse god, so remove that Link for the list of Norse
        // gods, and insert it into the list of Greek gods
        Link *p = norse_gods->find("Zeus"); // find Link whose value is Zeus
        if (p != nullptr)
        {
            if (p == norse_gods) // if found link is the starting Link
                // set starting Link to found Link's next pointer
                norse_gods = p->get_next();
            p->erase(); // remove Link
            greek_gods = greek_gods->insert(p); // insert Link into Greek gods
        }
    }

    // display updated lists
    print_all(norse_gods);
    cout << endl << endl;
    print_all(greek_gods);
    cout << endl << endl;

    return 0;
}
