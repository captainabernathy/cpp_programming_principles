#include <iostream> // I/O library header
#include <list> // list library header
#include <vector>  // vector library header
using namespace std;

int main()
{
    int initializer[7] = {1, 2, 3, 4, 5, 6, 7};
    int *first = initializer;
    int *last = initializer + 7;

    {
        vector<int> v(first, last);
        vector<int>::iterator p = v.begin();
        cout << *p << endl; // 1
        p++;
        p += 2;
        cout << *p << endl; // 4
        vector<int>::iterator q = p;
        q++;  // does not advance p
        cout << *p << " " << *q << endl; // 4 5

        // NOTE: the insert() method inserts a an element before the element
        // specified by its first argument which contains the value specified
        // by its second argument
        p = v.insert(p, 99);
        cout << *p << endl;  // 99
        
        // NOTE: the erase method removes an element at the position specified
        // by its argument and returns an iterator that points to the new
        // location of the element that followed the erased element
        p = v.erase(p);
        cout << *p << endl << endl; // 4
    }

    {
        list<int> l(first, last);
        list<int>::iterator p = l.begin();
        cout << *p << endl;  // 1

        // NOTE: the += operator is not defined for lists iterators
        p++;
        p++;
        p++;
        cout << *p << endl; // 4
        list<int>::iterator q = p;
        q++; // does not advance p
        cout << *p << " " << *q << endl; // 4 5
    }

    return 0;
}
