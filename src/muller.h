#ifndef ANPI_P2_MULLER_H
#define ANPI_P2_MULLER_H
#include <complex>
#include "laguerre.h"
using namespace std;
const double tolerate2 = 1e-50;
namespace anpi {
    namespace muller {
        d
        template<typename T>
        std::complex<T> muller(vector<complex<T>> coefs, std::complex<T> l, std::complex<T> m,std::complex<T> u) {
            complex<T> f2;
            complex<T> f0 ;
            complex<T> f1 ;
            complex<T>h1 ;
            complex<T>h2 ;
            complex<T> ga ;
            complex<T>c ;
            complex<T>a ;
            complex<T>b ;
            complex<T>root1 ;
            complex<T> root2;

            complex<T> xr;
            for (int step = 0; step < 10000; step++) {
                f2 =horner(coefs,l);
                f0 =horner(coefs,m);
                f1 =horner(coefs,u);
                h1 = u - m;
                h2 = m - l;
                ga = l / h1;
                c = f0;
                a = (ga + f1 - f0 * (complex<T>(1) + ga) + f2) / (ga * pow(h1,2) * (complex<T>(1) + ga));
                b = (f1 - f0 - a * pow(h1,2)) / (h1);
                root1 = m - ((complex<T>(2) * c) / (b + sqrt(pow(b,2) - complex<T>(4) * a * c)));
                root2 = m - ((complex<T>(2) * c) / (b - sqrt(pow(b,2) - complex<T>(4) * a * c)));

                if (abs( m- root1) < abs(m - root2))
                    xr = root1;
                else if (abs(m - root1) > abs(m - root2))
                    xr = (root2);


                if (abs(xr) > abs(m)) {
                    l = m;
                    m = xr;
                } else {
                    u = m;
                    m = xr;}

                if (abs(horner(coefs,xr)) < tolerate2) break;
            }
            return xr;
        }

        template<typename T>
        vector<complex<T>> allRoots(const vector<complex<T>> &poly, complex<T> l, complex<T> m, complex<T> u) {
            vector<complex<T>> answer;
            vector<complex<T>> polyAux = poly;
            complex<T> comp ;
            while (polyAux.size() > 2) {
                comp = anpi::muller::muller(polyAux, l, m, u);
                polyAux = deflation(polyAux, comp);
                answer.push_back(comp);
            }
            answer.push_back(-polyAux[0] / polyAux[1]);

            return answer;

        }

    }
}

#endif //ANPT_P2_MULLER_H
