//
// Created by pablorod on 3/29/2017.
//

#ifndef ANPI_POL_DIVIDE_POL_H
#define ANPI_POL_DIVIDE_POL_H
#include <boost/math/tools/polynomial.hpp>
using namespace boost::math::tools;
template <typename  T>
const polynomial<T> divide(const polynomial<T>& u, const polynomial<T>& v, polynomial<T>& r)
{
    BOOST_ASSERT(v.size() <= u.size());
    BOOST_ASSERT(v);
    BOOST_ASSERT(u);
    const unsigned long nv = v.degree();
    const unsigned long n = u.degree();


    r = polynomial<T>(u);
    std::vector<T> qs(n-nv+1,r[n]/v[nv]);
    polynomial<T> q = polynomial<T>(qs.begin(),qs.end());
    long k,j;
    for (k=n-nv;k>=0;k--) {
        q[k] = r[nv+k]/v[nv];
        for (j=nv+k-1;j>=k;j--) {
            if(k<q.size()) r[j] -= q[k] * v[j - k];
        }
    }
    for (j=nv;j<=n;j++) r[j]=0.0;
    r.normalize();
    q.normalize();
    return q;
    
}

#endif //ANPI_POL_DIVIDE_POL_H
