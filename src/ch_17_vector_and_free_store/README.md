## Chapter 17 - Vector and Free Store
### Source Code and Utilities Directory

### Program Files
* ch\_17\_03\_00\_memory\_addresses\_pointers.cpp 
* ch\_17\_03\_01\_sizeof\_operator.cpp
* ch\_17\_04\_01\_free\_store\_allocation.cpp
* ch\_17\_04\_02\_access\_through\_pointers.cpp
* ch\_17\_04\_04\_initialization.cpp
* ch\_17\_04\_06\_free\_store\_deallocation.cpp
* ch\_17\_06\_access\_to\_elements.cpp
* ch\_17\_09\_00\_pointers\_and\_references.cpp
* ch\_17\_09\_01\_pointer\_and\_reference\_parameters.cpp
* ch\_17\_09\_05\_list\_use.cpp
* ch\_17\_10\_01\_the\_this\_pointer.cpp

### Linked List Interface
* link\_str.hpp

### Linked List Implementation Files
* link\_str\_insert.cpp
* link\_str\_add.cpp
* link\_str\_erase.cpp
* link\_str\_find.cpp
* link\_str\_advance.cpp

### Linked List Utilities Interface
* link\_str\_utils.hpp

### Linked List Utilities Implementation Files
* link\_str\_utils.cpp

NOTE: Throughout the interfaces and implementations of the Linked List files
listed above, I use conditional preprocessing directives to support building
working examples of each version of the applications that use them as they are
presented in the textbook.

These directives are used solely to avoid rewriting code that doesn't change
across successive implementations and to demarcate the inclusion of new
features that are added as the example applications that depend on them 
become more complex.

Personally, I find it easier to trace the evolution of the programming
examples by isolating what changes into sections of code that can be viewed
in terms of a single implementation at large, as opposed to multiple,
separate implementations that can only be viewed and compared side-by-side
in their entireties.

Ultimately, this approach is simply a technique that I found accommodating
to my learning style as I progressed through the textbook. Nonetheless,
it is NOT an approach that I'd recommend outside of a learning environment.
