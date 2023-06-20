// program demonstrates how use the standard library's complex number type

#include <ostream> // for ostream
#include <complex> // for complex
#include <vector> // for vector
#include <iostream> // for cout
#include <numeric> // for accumulate<>()

namespace my {
// ad-hoc class template that represents a complex number in terms of two
// Scalar types... one for its real part, and the other for its imaginary part
template<typename Scalar>
class complex {
    Scalar re; // real part
    Scalar im; // imaginary pary

public:
    // default constructor
    complex()
        : re {Scalar { }},
          im {Scalar { }} { }

    // converts an object of a Scalar type to a complex number
    complex(Scalar const& r)
        : re {r},
          im {Scalar { }} { }

    // creates a complex number with r as its real part and i as its imaginary
    // part
    complex(Scalar const& r, Scalar const& i)
        : re {r},
          im {i} { }

    // returns the real part of this complex number
    Scalar real()
    {
        return re;
    }

    // returns the imaginary part of this complex number
    Scalar imag()
    {
        return im;
    }

    // output operator for a complex number
    friend std::ostream& operator<<(std::ostream& os, complex<Scalar> const& c)
    {
        os << '(' << c.re << ',' << c.im << ')';
        return os;
    }
};

}

// type alias to short the declaration of complex<double>
// typedef std::complex<double> dcmplx;
using dcmplx = std::complex<double>; // same as ^^^

// function that performs various mathematical operations on z and vc
void f(dcmplx z, std::vector<std::complex<double>>& vc);

int main()
{
    using std::cout;

    my::complex<double> s1; // default initialized
    my::complex<double> s2 {1}; // one-argument constructor
    my::complex<double> s3 {2, 3}; // two-argument constructor

    cout << s1 << '\n'; // (0,0)
    cout << s2 << '\n'; // (1,0)
    cout << s3 << "\n\n"; // (2,3)

    // array of complex numbers
    dcmplx d[10] = { dcmplx {1, 2}, dcmplx {2, 3}, dcmplx {3, 4},
                     dcmplx {4, 5}, dcmplx {5, 6}, dcmplx {6, 7},
                     dcmplx {7, 8}, dcmplx {8, 9}, dcmplx {9, 0},
                     dcmplx {0, 1} };

    // initialize vector using ^^^
    std::vector<dcmplx> v {d, d + 10};

    f(d[0], v); // do some things with complex numbers

    return 0;
}

// function that performs various mathematical operations on z and vc
void f(dcmplx z, std::vector<std::complex<double>>& vc)
{
    dcmplx z2 = pow(z, 2);
    std::cout << z2 << '\n';
    
    dcmplx z3 = z2 * 9.0 + vc[3];
    std::cout << z3 << '\n';

    dcmplx sum = std::accumulate(vc.begin(), vc.end(), dcmplx());
    std::cout << sum << '\n';
}

