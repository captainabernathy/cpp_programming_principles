#ifndef TINY_ENCRYPTION_ALGORITHM_HPP
#define TINY_ENCRYPTION_ALGORITHM_HPP

namespace TEA {

void encrypt(unsigned int const *const v, unsigned int *const w,
             unsigned int const *const k);

void decrypt(unsigned int const *const v, unsigned int *const w,
             unsigned int const *const k);
}

#endif
