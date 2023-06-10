#ifndef AS_BYTES_HPP
#define AS_BYTES_HPP

// function template that gets the address of the first byte of an object's
// representation
template<typename T>
char *as_bytes(T& i) // treat T as a sequence of bytes
{
    // get the address of the first byte of memory used to store object
    void *addr = &i;

    return static_cast<char *>(addr); // treat that memory as bytes
}

#endif
