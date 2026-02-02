#include <bits/stdc++.h>
using namespace std;

// this technique is called MEMOIZATION of storing the 
// value of function calls so that they are not called 
// unnecessarily and repeatedily 

// i just realized it's just precomputation ;) !!
vector<long long> f(1e5,-1) ;
long long fib(int n)
{
    if(n<=1)
    {
        f[n] = n ;
        return n ;
    }
    if(f[n-1] == -1) f[n-1] = fib(n-1) ;
    if(f[n-1] == -1) f[n-2] = fib(n-2) ;
    f[n] = f[n-1] + f[n-2] ;
    return f[n-2]+f[n-1] ;
}

int main()
{
    int n ; cin >> n ;
    cout << fib(n+2) << endl;

}