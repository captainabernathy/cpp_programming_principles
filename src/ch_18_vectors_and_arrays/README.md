## Chapter 18 - Vectors and Arrays
### Source Code and Utilities Directory

### Program Files
* ch\_18\_02\_00\_initialization.cpp
* ch\_18\_02\_01\_initializer\_list.cpp
* ch\_18\_03\_01\_copy\_constructors.cpp
* ch\_18\_03\_02\_copy\_assignments.cpp
* ch\_18\_03\_03\_copy\_terminology.cpp
* ch\_18\_04\_00\_essential\_operations.cpp
* ch\_18\_04\_02\_debugging\_constructors\_and\_destructors.cpp
* ch\_18\_05\_00\_access\_to\_vector\_elements\_v1.cpp
* ch\_18\_05\_00\_access\_to\_vector\_elements\_v2.cpp
* ch\_18\_05\_00\_access\_to\_vector\_elements\_v3.cpp
* ch\_18\_05\_01\_overloading\_on\_const.cpp
* ch\_18\_05\_02\_move\_semantics.cpp
* ch\_18\_06\_03\_array\_initialization.cpp
* ch\_18\_07\_01\_palindromes\_using\_string.cpp
* ch\_18\_07\_02\_palindromes\_using\_arrays.cpp
* ch\_18\_07\_03\_palindromes\_using\_pointers.cpp
* ch\_18\_07\_04\_palindromes\_using\_pointers\_recursive.cpp 

### Vector Interface
* vector\_dbl.hpp

### Vector Implementation Files
* vector\_dbl\_copy\_assign.cpp
* vector\_dbl\_move\_assign.cpp

### Vector Utilities Interface
* vector\_dbl\_utils.hpp

### Vector Utilities Implementation Files
* vector\_dbl\_utils.cpp

NOTE: Throughout the interfaces and implementations of the Vector files
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
