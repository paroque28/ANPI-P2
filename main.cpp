#include <iostream>
#include <boost/math/tools/polynomial.hpp>

using namespace boost::math::tools; // for polynomial

int main()
{
    polynomial<double> const a{{-2.0, 1.0}};
// With C++11 and later, you can also use initializer_list construction.
    polynomial<double> const b{{-2.0, 1.0}};

// formula_format() converts from Boost storage to human notation.
    std::cout << "a = " << boost::formula_format(a)
         << "\nb = " << boost::formula_format(b) << "\n\n";
    return 0;
}
