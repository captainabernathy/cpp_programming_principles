## Chapter 16 - Graphical User Interfaces

### Program Files
* ch\_16\_05\_drawing\_example.cpp
* ch\_16\_07\_drawing\_and\_menu.cpp 

### Lines Window Interface
* lines\_window.hpp

### Lines Window Implementation Files
* lines\_window.cpp 

NOTE: Throughout the interface and implementation of the Lines\_window class,
I use conditional preprocessing directives to support building working examples
of each version of the applications that use them as they are presented in the
textbook.

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
