// program implements a Link class that can be used to build up a doubly
// linked list of strings.
// the Link class also provides several methods for manipulating such a list.
//
// NOTE: implementation does not deallocate dynamically allocated Links

#include <iostream> // for cout
#include <string> // for string

// class used to build an ad-hoc doubly linked list of strings
class Link {
public:
    std::string value;

    // constructor
    Link(std::string const& v, Link *p = nullptr, Link *n = nullptr)
        : value {v}, prev {p}, next {n} {  }

    // inserts Link n before this Link and returns a pointer to it
    Link *insert(Link *n);
    
    // removes this Link from a list and returns the Link that follows it
    Link *erase();
    
    // finds the string s in a list starting from this Link and returns a
    // pointer to it if found... or nullptr if not
    Link *find(std::string const& s);
   
    // NOT IMPLEMENTED:
    // finds the string s in a list starting from this Link and returns a
    // pointer to it if found... or nullptr if not
    // const Link *find(std::string const& s) const;
   
    // NOT IMPLEMENTED:
    // moves this Link n positions in list... +n moves, -n moves backwards
    // Link *advance(int n) const;

    // returns a pointer to the Link after this Link
    Link *get_next() const { return next; }

    // returns a pointer to Link before this Link
    Link *get_prev() const { return prev; }

private:
    Link *prev; // pointer to Link before this Link
    Link *next; // pointer to Link after this Link
};

// inserts Link n before this Link and returns a pointer to it
Link *Link::insert(Link *n)
{
    if (n == nullptr) // return this pointer if n is NULL
        return this;

    if (this == nullptr) // return n if this pointer is NULL
        return n;

    n->next = this; // set Link n's next pointer to this Link

    if (prev != nullptr)
        // set the next pointer of this Link's prev pointer to Link n
        prev->next = n;

    // set Link n's prev pointer to this Link's prev pointer
    n->prev = prev;
    
    // set this Link's prev pointer to Link n
    prev = n;

    return n;
}

// removes this Link from a list and returns the Link that follows it
Link *Link::erase()
{
    if (this == nullptr)
        return nullptr;

    if (next != nullptr) // this Link has Link after it
        // set the prev pointer of this Link's next pointer to this Link's
        // prev pointer
        next->prev = prev;

    if (prev != nullptr) // this Link has a Link before it
        // set the next pointer of this Link's prev pointer to this Link's
        // next pointer
        prev->next = next;

    return next;
}

// finds the string s in a list starting from this Link and returns a
// pointer to it if found... or nullptr if not
Link *Link::find(std::string const& s)
{
    Link *p = this; // start from this Link

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
    std::cout << "{";
    while (p != nullptr)
    {
        std::cout << p->value;
        if ((p = p->get_next()) != nullptr)
            std::cout << ", ";
    }
    std::cout << "}";
}

int main()
{
    using std::cout;

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
    cout << "\n\n";

    print_all(greek_gods);
    cout << "\n\n";

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
    cout << "\n\n";

    print_all(greek_gods);
    cout << "\n\n";

    return 0;
}
