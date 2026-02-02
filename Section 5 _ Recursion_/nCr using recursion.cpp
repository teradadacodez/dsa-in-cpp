#include <bits/stdc++.h>
using namespace std;
// by pascals triangle we can see the recursice calls 
//each node is making and make the base cases 

int ncr(int n , int r)
{
    if(n==r || r==0) return 1 ;
    else return ncr(n-1,r-1)+ ncr(n-1,r) ;
}

signed main()
{
    cout << ncr(5,2) << " " << ncr(5,3) << endl;
}
