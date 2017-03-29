//
// Created by pablorod on 3/29/2017.
//

#ifndef ANPI_POL_FORMULAFORMAT_H
#define ANPI_POL_FORMULAFORMAT_H

#include <iostream>
#include <boost/math/tools/polynomial.hpp>

using namespace boost::math::tools; // for polynomial
using boost::lexical_cast;
using namespace boost::math;
using namespace std;
template <typename T>
string sign_str(T const &x)
{
    return x < 0 ? "-" : "+";
}

template <typename T>
string inner_coefficient(T const &x)
{
    string result(" " + sign_str(x) + " ");
    if (abs(x) != T(1))
        result += lexical_cast<string>(abs(x));
    return result;
}
/*! Output in formula format.
For example: from a polynomial in Boost container storage  [ 10, -6, -4, 3 ]
show as human-friendly formula notation: 3x^3 - 4x^2 - 6x + 10.
*/
template <typename T>
string formula_format(polynomial<T> const &a)
{
    string result;
    if (a.size() == 0)
        result += lexical_cast<string>(T(0));
    else
    {
        // First one is a special case as it may need unary negate.
        unsigned i = a.size() - 1;
        if (a[i] < 0)
            result += "-";
        if (abs(a[i]) != T(1))
            result += lexical_cast<string>(abs(a[i]));

        if (i > 0)
        {
            result += "x";
            if (i > 1)
            {
                result += "^" + lexical_cast<string>(i);
                i--;
                for (; i != 1; i--)
                    result += inner_coefficient(a[i]) + "x^" + lexical_cast<string>(i);

                result += inner_coefficient(a[i]) + "x";
            }
            i--;

            result += " " + sign_str(a[i]) + " " + lexical_cast<string>(abs(a[i]));
        }
    }
    return result;
} // string formula_format(polynomial<T> const &a)
#endif //ANPI_POL_FORMULAFORMAT_H
