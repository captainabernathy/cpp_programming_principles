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

NOTE: Throughout the interface to and implementation of the link class,
conditional preprocessing directives are used to support building working
versions of the example applications that depend on the link class as they are
presented in the textbook.

These directives are used solely to avoid rewriting code that does not change
across successive example applications and to demarcate the inclusion of new
features that become necessary as the example applications that depend on the
link class become more complex.

Ultimately, this technique only serves as a means to adapt this project's build
system to one's learning environment.
