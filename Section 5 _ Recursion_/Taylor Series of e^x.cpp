#include <bits/stdc++.h>
using namespace std;

double e(int x , int n)
{
    static double p {1} ; 
    static double f {1} ;
    double r ;
    if(n==0) return 1 ;
    r = e(x,n-1) ;
    p*=x ;
    f*=n ;
    return r+(p/f) ;
}

int main()
{
    cout << setprecision(10) << e(1,100) << endl;
}