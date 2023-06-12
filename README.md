This repository contains the programming examples I made when working through
the book ***Programming: Principles and Practice Using C++, 2nd Edition*** by
Bjarne Stroustrup.

It exists as part of my own, personal code preservation project and to serve
as a general programming reference.

The extent to which the examples here differ from those in the book vary 
throughout the project.

In addition to refactoring many examples, I have reorganized the project's
structure in its entirety and reimplemented its build system completely. I have
also added various libraries, utilities, and interfaces to this project that
are not present in the version provided by the book.

Those seeking the original project and code examples as provided by the book,
should visit:
<https://www.stroustrup.com/>

### Build Instructions
    cpp_programming_principles> cd build
    build> cmake ..
    build> cd ..
    cpp_programming_principles> cmake --build build

### Dependencies
* CMake
* X11
* FLTK

NOTE: Project only tested on Debian Linux
