// program uses a vector to illustrate the concepts of size and capacity and
// the type of discrepancies that can occur b/t the two when managing the
// vector's allocation directly with pointers as opposed to relying on its
// built-in features

#include <iostream> // I/O library header
#include <vector> // vector library header
#include <algorithm> // algorithm library header

using std::vector; // add name vector to file's scope
using std::cin; // add name cin to file's scope
using std::cout; // add name cout to file's scope
using std::endl; // add name endl to file's scope

// function fills a vector using push_back(), changes the size of vector
// using resize(), and displays the vector's size and capacity along the way
void foo();

// function fills a vector to an arbitray size via ad-hoc technique...
// problematic bc it doesn't differentiate b/t size (last valid value) and
// space (total memory allocated)
void without_push_back();

// function fills a vector to an arbitray size using push_back()
void with_push_back();

int main()
{
    without_push_back();
    cout << endl;
    with_push_back();
    cout << endl;
    foo();

    return 0;
}

void foo()
{
    vector<double> vd; // a vector of doubles

    // fill vector vd with 13 doubles using its push_back() method
    for (size_t n = 1; n < 14; n++)
        vd.push_back((n + (0.1 * n)));

    cout << "foo()" << endl;
    cout << "vd.size(): " << vd.size() << endl; // 13
    cout << "vd.capacity(): " << vd.capacity() << endl << endl; // 16

    vector<char> vc(100); // vector of 100 chars
    
    // NOTE: size and capacity are the same whenever a vector is constructed
    cout << "vc.size(): " << vc.size() << " before vc.resize()" << endl; // 100
    cout << "vc.capacity(): " << vc.capacity() << " before vc.resize()"
        << endl << endl; // 100

    // NOTE: resize() changes a vector's size, but when the vector new size is
    // less than or equal to it's original capacity, the vector's capacity is
    // not changed. the vector's capacity will only change when its new size
    // is greater than its previous size
    vc.resize(11);
    cout << "vc.size(): " << vc.size() << " after vc.resize()" << endl; // 11
    cout << "vc.capacity(): " << vc.capacity() << " after vc.resize()"
        << endl << endl; // 100
    
    // in this case, the vector's size and capacity will be equal
    vc.resize(110);
    cout << "vc.size(): " << vc.size() << " after vc.resize()" << endl; // 110
    cout << "vc.capacity(): " << vc.capacity() << " after vc.resize()"
        << endl; // 110

}

void without_push_back()
{
    // p is a pointer to a vector of 8 doubles
    // NOTE: whenever a vector is constructed, its size and capacity are equal
    vector<double> *p = new vector<double>(8);

    // fill vector with 13 doubles using assignment
    for (size_t n = 1; n < 14; n++)
    {
        if (n == p->size()) // need to add more room for more elements
        {
            // vector of doubles with twice as much space than p
            vector<double>* q = new vector<double>(p->size() * 2);
            // copy p's elements into q
            std::copy(p->begin(), p->end(), q->begin());
            delete p; // deallocate memory used by p
            p = q; // set p to q... creates an alias b/t pointers
        }

        (*p)[n - 1] = (n + (0.1 * n));
        cout << (*p)[n - 1] << endl;
    }
    
    cout << "without_push_back()" << endl;
    // size and capacity will be the same... but size should represent the
    // number of slots occupied by elements in the collection... while capacity
    // should represent the total number of slots in the collection
    cout << "p->size(): " << p->size() << endl; // 16
    cout << "p->capacity(): " << p->capacity() << endl; // 16
    delete p;
}

void with_push_back()
{
    vector<double> vd; // a vector doubles

    // fill vector vd with 13 doubles using its push_back() method
    for (size_t n = 1; n < 14; n++)
    {
        vd.push_back((n + (0.1 * n)));
        cout << vd[n - 1] << endl;
    }

    cout << "with_push_back()" << endl;
    // size and capactiy are different since we used push_back() to populate
    // the vector
    cout << "vd.size(): " << vd.size() << endl; // 13
    cout << "vd.capacity(): " << vd.capacity() << endl; // 16
}
