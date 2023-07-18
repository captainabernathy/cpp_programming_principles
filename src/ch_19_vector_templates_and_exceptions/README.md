## Chapter 19 - Vector, Templates, and Exception
### Source Code and Utilities Directory

### Program Files
* ch\_19\_01\_the\_problems.cpp
* ch\_19\_02\_00\_changing\_size.cpp
* ch\_19\_02\_01\_representation.cpp
* ch\_19\_02\_02\_reserve\_and\_capacity.cpp
* ch\_19\_02\_03\_resize.cpp
* ch\_19\_02\_04\_push\_back.cpp
* ch\_19\_02\_05\_assignment.cpp
* ch\_19\_02\_06\_vector\_so\_far.cpp
* ch\_19\_03\_01\_types\_as\_template\_parameters.cpp
* ch\_19\_03\_05\_template\_parameters.cpp
* ch\_19\_03\_06\_template\_argument\_deduction.cpp
* ch\_19\_03\_07\_generalizing\_vector.cpp
* ch\_19\_04\_02\_range\_checking\_and\_exceptions.cpp 

### Vector Interface
* vector\_dbl.hpp

### Vector Implementation Files
* vector\_dbl\_copy\_assign.cpp
* vector\_dbl\_move\_assign.cpp
* vector\_dbl\_push\_back.cpp
* vector\_dbl\_reserve.cpp
* vector\_dbl\_resize.cpp

### Vector Utilities Interface
* vector\_dbl\_utils.hpp

### Vector Utilities Implementation Files
* vector\_dbl\_utils.cpp

### Collection Utilities Interface
* collection\_utils.hpp

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
