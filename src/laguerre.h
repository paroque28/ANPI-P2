//
// Created by ferllini13 on 25/03/17.
//impired by https://sites.google.com/site/indy256/algo_cpp/polynom_roots
//

#ifndef ANPI_P2_LAGUERRE_H
#define ANPI_P2_LAGUERRE_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <complex>

using namespace std;
const double tolerate = 1e-9;

template <typename T>
pair<vector<complex<T>>, complex<T>> hornerPair(const vector<complex<T>> &a, complex<T> x0) {
    int n = a.size();
    vector<complex<T>> b = vector<complex<T>>(max(1, n - 1));

    for(int i = n - 1; i > 0; i--)
        b[i - 1] = a[i] + (i < n - 1 ? b[i] * x0 : 0);
    return make_pair(b, a[0] + b[0] * x0);
}

template <typename T>
vector<complex<T>> derivative(const vector<complex<T>> &poly) {
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
complex<T> root(const vector<complex<T>> &p0, complex<T> x) {
    complex<T> cero=0;
    int n = p0.size() - 1;
    vector<complex<T>> p1 = derivative(p0);
    vector<complex<T>> p2 = derivative(p1);
    for (int step = 0; step < 10000; step++) {
        complex<T> y0 = hornerPair(p0, x).second;
        if (compare(y0, cero) == 0) break;
        complex<T> G = hornerPair(p1, x).second / y0;
        complex<T> H = G * G - hornerPair(p2, x).second - y0;
        complex<T> R = sqrt(complex<T>(n - 1) * (H * complex<T>(n) - G * G));
        complex<T> D1 = G + R;
        complex<T> D2 = G - R;
        complex<T> a = complex<T>(n) / (compare(D1, D2) > 0 ? D1 : D2);
        x -= a;
        if (compare(a, cero) == 0) break;
    }
    return x;
}

template <typename T>
vector<complex<T>> laguerre(const vector<complex<T>> &poly) {
    vector<complex<T>> answer;
    vector<complex<T>> polyAux = poly;
    while (polyAux.size() > 2) {
        complex<T> comp(rand() / double(RAND_MAX), rand() / double(RAND_MAX));
        comp = root(polyAux, comp);
        comp = root(poly, comp);
        polyAux = hornerPair(polyAux, comp).first;
        answer.push_back(comp);
    }
    answer.push_back(-polyAux[0] / polyAux[1]);

    for(size_t i = 0; i < answer.size(); i++) {
        if (abs(answer[i].real()) < tolerate) answer[i] -= complex<T>(answer[i].real(), 0);
        if (abs(answer[i].imag()) < tolerate) answer[i] -= complex<T>(0, answer[i].imag());
    }
    return answer;
}

#endif //ANPI_P2_LAGUERRE_H
