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

NOTE: Throughout the interface to and implementation of the Vector class,
conditional preprocessing directives are used to support building working
versions of the example applications that depend on the Vector class as they
are presented in the textbook.

These directives are used solely to avoid rewriting code that does not change
across successive example applications and to demarcate the inclusion of new
features that become necessary as the example applications that depend on the
Vector class become more complex.

Ultimately, this technique only serves as a means to adapt this project's build
system to one's learning environment.
