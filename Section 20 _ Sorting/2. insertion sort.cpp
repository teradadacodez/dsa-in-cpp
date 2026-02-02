#include <bits/stdc++.h>
using namespace std;

void insertionsort(int a[],int n)
{
    for(int i {1} ; i<n ; i++)
    {
        int x {a[i]} ;
        int j {i-1} ;
        while(j>-1 && a[j]>x)
        {
            a[j+1] = a[j] ; 
            j-- ;
        }
        a[j+1] = x ;
    }
}
// TC : O(n) to O(n^2)
// SC : O(1)
// it's adaptive by nature 
// it's stable also
// it's best use is with linked list !!
int main()
{
    int a[] = {9,8,7,6,5,4,3,2,1} ;
    insertionsort(a,9) ;
    for(int i {0} ; i<9 ; i++) cout << a[i] << " " ; cout << endl;
}