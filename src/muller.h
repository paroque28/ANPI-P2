#ifndef ANPI_P2_MULLER_H
#define ANPI_P2_MULLER_H
#include <complex>
#include "laguerre.h"

namespace anpi {
    namespace muller {


        template<typename T>
        std::complex<T>
        solve(vector<complex<T>> coefs, unsigned int grado, std::complex<T> lower, std::complex<T> middle,
              std::complex<T> upper) {
            // Busqueda de raices reales y complejas mediante el metodo de Muller.

            /* Se busca construir una parabola y = ax^2 + bx + c que pase por
             * los puntos lower, middle y upper, luego las intersecciones de dicha
             * parabola con el eje X seran nuestas raices aproximadas. */
            std::complex<T> a;
            std::complex<T> b;
            std::complex<T> c;

            // Las h y las gammas son las diferencias entre puntos.
            std::complex<T> h0;
            std::complex<T> h1;
            std::complex<T> gamma0;
            std::complex<T> gamma1;

            // Se deben realizar constantes evaluaciones de puntos en el polinomio.
            std::complex<T> lowerEval;
            std::complex<T> middleEval;
            std::complex<T> upperEval;

            //Se calculan dos raices siempre, pero solo se conserva uno.
            std::complex<T> firstRoot;
            std::complex<T> secondRoot;
            std::complex<T> actualRoot;

            std::complex<T> dos(2, 0);
            std::complex<T> cuatro(4, 0);

            for (int contador = 0; contador < 10; ++contador) {
                // Evaluamos los tres puntos que tenemos:
                lowerEval = horner(coefs, lower);
                middleEval = horner(coefs, middle);
                upperEval = horner(coefs, upper);

                /* Primer paso es obtener c mediante la evaluacion directa del
                 * upper en el polinomio */
                c = upperEval;

                // Luego se calculan las diferencias
                h0 = middle - lower;

                if (h0 == std::complex<T>(0, 0)) {
                    break;
                }

                gamma0 = (middleEval - lowerEval) / (middle - lower);
                h1 = upper - middle;

                if (h1 == std::complex<T>(0, 0)) {
                    break;
                }

                gamma1 = (upperEval - middleEval) / (upper - middle);

                // Luego se calculan los coeficientes de la nueva parabola.
                a = (gamma1 - gamma0) / (h1 - h0);
                b = (a * h1) + gamma1;

                // Calculamos las dos raices mediante la formula alternativa cuadratica:
                firstRoot = upper + ((-dos * c) / (b + std::sqrt(std::pow(b, dos) - cuatro * a * c)));
                secondRoot = upper + ((-dos * c) / (b + std::sqrt(std::pow(b, dos) + cuatro * a * c)));

                // Se escoge la raiz cuyo signo coincida con el de b.
                if (std::real(b) < 0) {
                    if (std::real(firstRoot) < 0) {
                        actualRoot = firstRoot;
                    } else {
                        actualRoot = secondRoot;
                    }
                } else {
                    if (std::real(firstRoot) >= 0) {
                        actualRoot = firstRoot;
                    } else {
                        actualRoot = secondRoot;
                    }
                }

                middle = upper;
                lower = middle;
                upper = actualRoot;
            }

            return upper;
        }

        template<typename T>
        vector<complex<T>> allRoots(const vector<complex<T>> &poly, complex<T> l, complex<T> m, complex<T> u) {
            vector<complex<T>> answer;
            vector<complex<T>> polyAux = poly;
            while (polyAux.size() > 2) {
                complex<T> comp = complex<T>(0);
                comp = anpi::muller::solve(polyAux, polyAux.size(), l, m, u);
                comp = anpi::muller::solve(poly, poly.size(), l, m, u);
                polyAux = deflation(polyAux, comp);

                answer.push_back(comp);
            }
            answer.push_back(-polyAux[0] / polyAux[1]);

            return answer;

        }
    }
}

#endif //ANPT_P2_MULLER_H
