#include <bits/stdc++.h>
using namespace std;

// COUNT SORT : index bases sorting , consumes large memory !
// aka HASH SORT, because we make a hash array and increment the value at that index !

void countsort(int a[] , int n)
{
    int mx {-1} ;
    for(int i {0} ; i<9 ; i++) mx = max(mx,a[i]) ;
    int *c = new int[mx+1] ;
    for(int i {0} ; i<mx+1 ; i++) c[i] = 0 ;
    for(int i {0} ; i<9 ; i++) c[a[i]]++ ;
    int k {0} , l {0} ;
    while(k<mx+1)
    {
        if(c[k])
        {
            a[l++] = k ;
            c[k]-- ;
        }
        else k++ ;
    }
    delete[] c ;
}
int main()
{
    int a[] = {2,3,4,5,6,7,8,9,1} ;
    countsort(a,9) ;
    for(int i {0} ; i<9 ; i++) cout << a[i] << " " ; cout << endl;
}