#include <iostream>
#include <boost/math/tools/polynomial.hpp>
#include "src/divide-pol.h"
#include "src/formulaformat.h"

using namespace boost::math::tools; // for polynomial
using boost::lexical_cast;
using namespace boost::math;
using namespace std;
#include "src/laguerre.h"

int main()
{

    vector<complex<double>> p;
// x^3 - 8x^2 - 13x + 140 = (x+4)(x-5)(x-7)
    p.push_back(-1);
    p.push_back(-1);
    p.push_back(-1);
    //p.push_back(1);

    vector<complex<double>> roots = laguerre(p);

    for(size_t i = 0; i < roots.size(); i++) {
        cout << setprecision(10) << roots[i] << endl;
    }

    polynomial<double> const a{{-8.0, 1.0,0.0,2.0,0,1.0}};
// With C++11 and later, you can also use initializer_list construction.
    polynomial<double> const b{{1.0, -2.0,1.0}};
    polynomial<double> r;
// formula_format() converts from Boost storage to human notation.
    std::cout << "a = " << formula_format(a)
         << "\nb = " << formula_format(b) << std::endl;
    const polynomial<double> &q = divide(a, b, r);
    std::cout << "a/b = " << formula_format(q) << std::endl;
    std::cout << "a/b = " << formula_format(a/b) << std::endl;
    std::cout << "a%b = " << formula_format(r) << std::endl;
    std::cout << "a%b = " << formula_format(a%b) << std::endl;
    std::cout << "end" << std::endl;
    return 0;
}
