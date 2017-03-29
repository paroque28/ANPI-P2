#include <iostream>
#include "src/muller.h"
#include <complex>

int main()
{
    double coefs[] = {2.0, 1.0};
    std::complex<double> lower (0.0, 0.0);
    std::complex<double> middle (1.0, 0.0);
    std::complex<double> upper (2.0, 0.0);
    
    std::complex<double> resultado = anpi::muller::solve(coefs, 1, lower, middle, upper);

    std::cout << resultado << std::endl;
    return 0;
}
