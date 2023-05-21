// program illustrates the difference between a shallow and a deep copy

#include <iostream> // for cout

int main()
{
    using std::cout;

    // shallow copy
    {
        int *p = new int(77); // allocate memory for and initialize p
        int *q = p; // shallow copy... updating one updates the other
        
        cout << "*p: " << *p << " *q: " << *q << '\n'; // 77, 77
       
        *p = 88; // updating p also updates q
        
        cout << "*p: " << *p << " *q: " << *q << "\n\n"; // 88, 88

        *q = 66; // updaing q also updates p
        
        cout << "*p: " << *p << " *q: " << *q << "\n\n"; // 66, 66

        delete p; // only need to delete p since no memory was allocated for q
    }

    // deep copy
    {
        int *p = new int(77); // allocate memory for and initialize p
        
        // allocate memory for q and initialize it to the value of p
        int *q = new int(*p);

        cout << "*p: " << *p << " *q: " << *q << '\n'; //  77, 77

        *p = 88; // updating p does not update q
        
        cout << "*p: " << *p << " *q: " << *q << '\n'; // 88, 77
        
        *q = 66; // updating  does not update p
        
        cout << "*p: " << *p << " *q: " << *q << '\n'; // 88, 66
        
        // necessary to deallocate p and q since both were dynaically allocated
        delete p;
        delete q;
    }

    return 0;
}
