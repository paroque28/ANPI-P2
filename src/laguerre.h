//
// Created by ferllini13 on 25/03/17.
//impired by https://sites.google.com/site/indy256/algo_cpp/polynom_laguerres
//

#ifndef ANPI_P2_LAGUERRE_H
#define ANPI_P2_LAGUERRE_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;
const double tolerate = 1e-15;

template <typename T>
complex<T> horner(const vector<complex<T>> &a, complex<T> x0){
    int n = a.size();
    vector<complex<T>> b = vector<complex<T>>(max(1, n - 1));

    for(int i = n - 1; i > 0; i--)
        b[i - 1] = a[i] + (i < n - 1 ? b[i] * x0 : 0);
    return ( a[0] + b[0] * x0);
}


template <typename T>
vector<complex<T>> div(const vector<complex<T>> &a, complex<T> x0){
    int n = a.size();
    vector<complex<T>> b = vector<complex<T>>(max(1, n - 1));

    for(int i = n - 1; i > 0; i--)
        b[i - 1] = a[i] + (i < n - 1 ? b[i] * x0 : 0);
    return b;
}


template <typename T>
vector<complex<T>> derivate(const vector<complex<T>> &poly) {
    int n = poly.size();
    vector<complex<T>> r = vector<complex<T>>(max(1, n - 1));
    for(int i = 1; i < n; i++)
        r[i - 1] = poly[i] * complex<T>(i);
    return r;
}

template <typename T>
int compare(complex<T> x, complex<T> y) {
    double diff = abs(x) - abs(y);
    return diff < -tolerate ? -1 : (diff > tolerate ? 1 : 0);
}
template <typename T>
complex<T> laguerre(const vector<complex<T>> &p0, complex<T> x) {
    int n = p0.size() - 1;
    vector<complex<T>> p1 = derivate(p0);
    vector<complex<T>> p2 = derivate(p1);
    for (int step = 0; step < 10000; step++) {
        complex<T> y0 = horner(p0, x);
        if (compare(y0, complex<T>(0)) == 0) break;
        complex<T> G = horner(p1, x) / y0;
        complex<T> H = G * G - horner(p2, x) - y0;
        complex<T> R = sqrt(complex<T>(n - 1) * (H * complex<T>(n) - G * G));
        complex<T> D1 = G + R;
        complex<T> D2 = G - R;
        complex<T> a = complex<T>(n) / (compare(D1, D2) > 0 ? D1 : D2);
        x -= a;
        if (compare(a, complex<T>(0)) == 0) break;
    }
    if (abs(x.real()) < tolerate) x = complex<T>(0, x.imag());
    if (abs(x.imag()) < tolerate) x = complex<T>(x.real(), 0);

    return x;
}

template <typename T>
vector<complex<T>> allRoots(const vector<complex<T>> &poly) {
    vector<complex<T>> answer;
    vector<complex<T>> polyAux = poly;
    while (polyAux.size() > 2) {
        complex<T> comp =complex<T>(0);
        comp = laguerre(polyAux, comp);
        comp = laguerre(poly, comp);
        polyAux = div(polyAux, comp);
        answer.push_back(comp);
    }
    answer.push_back(-polyAux[0] / polyAux[1]);

    return answer;
}

#endif //ANPI_P2_LAGUERRE_H