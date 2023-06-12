// program demonstrates the difference between the insert() and erase() methods
// of a list and a vector

#include <vector>  // for vector
#include <iostream> // for cout
#include <list> // for list

int main()
{
    using std::vector;
    using std::cout;
    using std::list;

    int initializer[7] = {1, 2, 3, 4, 5, 6, 7};
    int *first = initializer;
    int *last = initializer + 7;

    {
        // construct vector v to the range of elements between first and last
        vector<int> v(first, last);
        for (auto it : v)
            cout << it << ' ';
        cout << "\n\n";

        vector<int>::iterator p = v.begin(); // iterator to start of v
        cout << *p << '\n'; // 1
        p++; // increment iterator
        p += 2; // advance iterator by 2 (more) positions
        cout << *p << '\n'; // 4
        
        vector<int>::iterator q = p; // copy assignment
        q++; // does not advance p
        cout << *p << ' ' << *q << "\n\n"; // 4 5

        for (size_t i = 0; i < v.size(); i++)
        {
            cout << "v[" << i << "] " << v[i] << '\t'
                << "&v[i] " << &v[i] << '\t'
                << "*p " << *p << '\t'
                << "&*p " << &*p << '\t'
                << "&v[i] == &*p " << (&v[i] == &*p) << '\t'
                << "*q " << *q << '\t'
                << "&*q " << &*q << '\t'
                << "&v[i] == &*q " << (&v[i] == &*q) << '\n';
        }
        cout << '\n';

        // NOTE: the insert() method inserts an element with the value
        // specified by its second argument before the element specified by
        // its first argument and returns an iterator to the new element
        p = v.insert(p, 9); // internally v's insert() method will grow v...
                             // either by reallocation or in place
                             // (based on capacity)
                             // here, p points to the fourth element in v,
                             // and we will insert a new element whose value
                             // is 9 into v before p so that the fourth
                             // element in v will now contain 9
                             // now, since insert() returns an iterator to the
                             // inserted element, which we assign to p, p once
                             // again points to the fourth element in v

        // NOTE: we should consider q invalid at this point...
        // since we cannot be sure if the vector q was pointing (v) to was
        // reallocated or resized in place, we cannot be sure of the contents
        // of q
        for (size_t i = 0; i < v.size(); i++)
        {
            cout << "v[" << i << "] " << v[i] << '\t'
                << "&v[i] " << &v[i] << '\t'
                << "*p " << *p << '\t'
                << "&*p " << &*p << '\t'
                << "&v[i] == &*p " << (&v[i] == &*p) << '\t'
                << "*q " << *q << '\t' // UNSAFE: can't be sure what's in here
                << "&*q " << &*q << '\t'
                << "&v[i] == &*q " << (&v[i] == &*q) << '\n';
        }
        cout << '\n';

                
        
        // NOTE: the erase method removes an element at the position specified
        // by its argument and returns an iterator that points to the new
        // location of the element that followed the erased element
        p = v.erase(p); // internally v's erase() method will reduce the number
                        // of elements in v, but it will NOTE reduce v's
                        // capacity
                        // here, p points to the fourth element in v, and we
                        // will erase that element from v, and return an
                        // iterator to the element after p in v... which now
                        // points to the fourth element in v
                        // now, since we assign that iterator to p, p once
                        // again points to the fourth element in v

        for (size_t i = 0; i < v.size(); i++)
        {
            cout << "v[" << i << "] " << v[i] << '\t'
                << "&v[i] " << &v[i] << '\t'
                << "*p " << *p << '\t'
                << "&*p " << &*p << '\t'
                << "&v[i] == &*p " << (&v[i] == &*p) << '\t'
                << "*q " << *q << '\t' // UNSAFE: can't be sure what's in here
                << "&*q " << &*q << '\t'
                << "&v[i] == &*q " << (&v[i] == &*q) << '\n';
        }
        cout << '\n';
    }

    {
        // construct list l to the range of elements between first and last
        list<int> l(first, last);
        // NOTE: the [] operator is not defined for lists
        for (auto it : l)
            cout << it << ' ';
        cout << "\n\n";

        list<int>::iterator p = l.begin(); // iterator to the start of l

        cout << *p << '\n';  // 1

        // NOTE: the += operator is not defined for lists iterators
        p++;
        p++;
        p++;
        cout << *p << '\n'; // 4
        list<int>::iterator q = p;
        q++; // does not advance p
        cout << *p << " " << *q << "\n\n"; // 4 5

        for (auto it = l.begin(); it != l.end(); ++it)
        {
            cout << "*it " << *it << '\t'
                << "&*it " << &*it << '\t'
                << "*p " << *p << '\t'
                << "&*p " << &*p << '\t'
                << "&*it == &*p " << (&*it == &*p) << '\t'
                << "*q " << *q << '\t'
                << "&*q " << &*q << '\t'
                << "(&*it == &*q) " << (&*it == &*q) << '\n';
        }
        cout << '\n';

        // NOTE: inserting and erasing will not invalidate q because a list
        // will not be reallocated... so q will always point to the same place
        p = l.insert(p, 9);
        for (auto it = l.begin(); it != l.end(); ++it)
        {
            cout << "*it " << *it << '\t'
                << "&*it " << &*it << '\t'
                << "*p " << *p << '\t'
                << "&*p " << &*p << '\t'
                << "&*it == &*p " << (&*it == &*p) << '\t'
                << "*q " << *q << '\t'
                << "&*q " << &*q << '\t'
                << "(&*it == &*q) " << (&*it == &*q) << '\n';
        }
        cout << '\n';

        p = l.erase(p);

        for (auto it = l.begin(); it != l.end(); ++it)
        {
            cout << "*it " << *it << '\t'
                << "&*it " << &*it << '\t'
                << "*p " << *p << '\t'
                << "&*p " << &*p << '\t'
                << "&*it == &*p " << (&*it == &*p) << '\t'
                << "*q " << *q << '\t'
                << "&*q " << &*q << '\t'
                << "(&*it == &*q) " << (&*it == &*q) << '\n';
        }
    }

    return 0;
}
