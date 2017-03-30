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



    vector<complex<double >> root = allRoots(p2);
   vector< complex<double >> root2 = allRootsMP(p2,root.back());
    //vector<complex<double >> root3 = laguerre(p3);


    for (int i = 0; i <root.size(); ++i) {
        cout << setprecision(10)<<"p1 " << root[i] <<endl;
    }


    for (int i = 0; i <root2.size() ; ++i) {
        cout << setprecision(10)<<"p2 " << root2[i] <<endl;
    }

/*
    for (int i = 0; i <root3.size()-1 ; ++i) {
        cout << setprecision(10)<<"p1 " << root3[i] <<endl;
    }*/


    //cout << setprecision(10)<<"p2 " << root2 <<endl;
   // cout << setprecision(10)<<"p3 " << root3 <<endl;


    return 0;
}
