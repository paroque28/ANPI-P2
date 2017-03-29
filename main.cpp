#include <iostream>

#include "src/laguerre.h"

using namespace std;

int main()
{

    vector<complex<double>> p;
    vector<complex<double>> p2;
    vector<complex<double>> p3;



    p.push_back(140);
    p.push_back(-13);
    p.push_back(-8);
    p.push_back(1);

    p2.push_back(1);
    p2.push_back(1);
    p2.push_back(1);
    p2.push_back(1);

    p3.push_back(-8);
    p3.push_back(-4);
    p3.push_back(2);
    p3.push_back(-1);
    p3.push_back(1);



    complex<double > root = laguerre(p,complex<double>(0.0));
    complex<double > root2 = laguerre(p2,complex<double>(0.0));
    complex<double > root3 = laguerre(p3,complex<double>(0.0));


    cout << setprecision(10)<<"p1 " << root <<endl;
    cout << setprecision(10)<<"p2 " << root2 <<endl;
    cout << setprecision(10)<<"p3 " << root3 <<endl;

    return 0;
}
