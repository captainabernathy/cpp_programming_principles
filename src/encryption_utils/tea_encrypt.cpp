#include <encryption_utils/tiny_encryption_algorithm.hpp>

namespace TEA {

// implementation of the Tiny Encryption Algorithm's encrypt() function
//
// v is an array of two unsigned ints representing eight characters to be
// enciphered (v[0], v[1])
// w is an array of two unsigned ints into which the enciphered output is
// written (w[0], w[1])
// k is an array of 4 ints that represents the key (k[0],...,k[3])
void encrypt(unsigned int const *const v, unsigned int *const w,
             unsigned int const *const k)
{
    static_assert(sizeof(int) == 4, "size of int wrong for TEA");

    unsigned int y = v[0];
    unsigned int z = v[1];
    unsigned int sum = 0;
    unsigned int delta = 0x9E3779B9;
    unsigned int n = 32;

    while (n-- > 0)
    {
        y += ((z << 4) ^ (z >> 5)) + z ^ sum + k[sum & 3];
        sum += delta;
        z += ((y << 4) ^ (y >> 5)) + y ^ sum + k[sum >> 11 & 3];
    }

    w[0] = y;
    w[1] = z;
}

}
