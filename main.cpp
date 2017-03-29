#include <iostream>

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

    return 0;
}
