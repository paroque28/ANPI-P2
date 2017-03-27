#ifndef ANPI_P2_MULLER_H
#define ANPI_P2_MULLER_H
#include <cmath>
#include <complex>

namespace anpi 
{
    namespace muller
    {
        template<typename T>
        std::complex<T> horner(std::complex<T> x, T *a,  unsigned int grado) 
        {
            //Evaluacion secuencial de un polinomio mediante el metodo de Horner.
            std::complex<T> result = a[grado];
            for(int i=grado-1; i >= 0 ; --i)
                result = result * x + a[i];
            return result;
        }
         
        template<typename T>
        std::complex<T> solve(T * coefs, int grado, T lower, T middle, T upper)
        {
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
            
            for (int contador = 0 ; contador < 10 ; ++contador)
            {
                // Evaluamos los tres puntos que tenemos:
                lowerEval = horner(lower, coefs, grado);
                middleEval = horner(middle, coefs, grado);
                upperEval = horner(upper, coefs, grado);

                /* Primer paso es obtener c mediante la evaluacion directa del
                 * upper en el polinomio */
                c = upperEval;

                // Luegos se calculan las diferencias
                h0 = middle - lower;
                gamma0 = (middleEval - lowerEval) / (middle - lower);
                h1 = upper - middle;
                gamma1 = (upperEval - middleEval) / (upper - middle);

                // Calculamos las dos raices mediante la formula alternativa cuadratica:
                firstRoot = upper + ((-2 * c) / (b + std::sqrt(std::pow(b, 2) - 4 * a * c)));
                secondRoot = upper + ((-2 * c) / (b + std::sqrt(std::pow(b, 2) + 4 * a * c)));

                // Se escoge la raiz cuyo signo coincida con el de b.
                if (b < 0)
                {
                    if (firstRoot < 0)
                    {
                        actualRoot = firstRoot;
                    } else
                    {
                        actualRoot = secondRoot;
                    }
                } else
                {
                    if (firstRoot >= 0)
                    {
                        actualRoot = firstRoot;
                    } else
                    {
                        actualRoot = secondRoot;
                    }
                }

                /* Finalmente debemos seleccionar los nuevos tres puntos. Se hace asi:
                 * a) Solo raices reales? Tomamos los dos valores mas cercanos a actualRoot.
                 * b) Reales + Complejas? middle, upper y actualRoot toman el lugar de
                 *    lower, middle y upper (manera secuencial). */
                if (std::imag(firstRoot) == 0 && std::imag(secondRoot) == 0)
                {
                    // Tengo que pensar bien esta seleccion, work in progress.
                    upper = actualRoot;
                    middle = upper;
                    lower = middle;

                } else 
                {
                    upper = actualRoot;
                    middle = upper;
                    lower = middle;
                }
            }
        }
    }
}

#endif //ANPT_P2_MULLER_H
