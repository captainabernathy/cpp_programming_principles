#ifndef APPLY_OPERATIONS_HPP
#define APPLY_OPERATIONS_HPP

namespace Numeric_lib {

// template for a function object that assigns rhs to lhs
template<typename T>
struct Assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs = rhs;
    }
};

// template for a function object that stores the sum of lhs and rhs in lhs
template<typename T>
struct Add_assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs += rhs;
    }
};

// template for a function object that stores the product of lhs and rhs in lhs
template<typename T>
struct Mul_assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs *= rhs;
    }
};

// template for a function object that stores the difference of lhs and rhs in
// lhs
template<typename T>
struct Minus_assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs -= rhs;
    }
};

// template for a function object that stores the quotient of lhs and rhs in
// lhs
template<typename T>
struct Div_assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs /= rhs;
    }
};

// template for a function object that stores the remainder of lhs / rhs in lhs
template<typename T>
struct Mod_assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs %= rhs;
    }
};

// template for a function object that stores the result of performing the
// bitwise OR operation on lhs and rhs in lhs
template<typename T>
struct Or_assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs |= rhs;
    }
};

// template for a function object that stores the result of performing the
// XOR operation on lhs and rhs in lhs
template<typename T>
struct Xor_assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs ^= rhs;
    }
};

// template for a function object that stores the result of performing the
// bitwise AND operation on lhs and rhs in lhs
template<typename T>
struct And_assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs &= rhs;
    }
};

// template for a function object that stores the result of performing the
// logical NOT operation on rhs in lhs
template<typename T>
struct Not_assign {
    void operator()(T& lhs, const T& rhs)
    {
        lhs = !rhs;
    }
};

// template for a function object that returns the result of performing the
// logical NOT operation on a
template<typename T>
struct Not {
    T operator()(T& a)
    {
        return !a;
    }
};

// template for a function object that returns the opposite of a
template<typename T>
struct Unary_minus {
    T operator()(T& a)
    {
        return -a;
    }
};

// template for a function object that returns the result of applying the
// bitwise NOT (complement) operation to a
template<typename T>
struct Complement {
    T operator()(T& a)
    {
        return ~a;
    }
};

}

#endif
