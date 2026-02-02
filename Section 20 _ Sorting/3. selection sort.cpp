#include <bits/stdc++.h>
using namespace std;

// SELECTION SORT : we will first choose a position and then find the element less than that 
// in the whole array and swap that !!

void selectionsort(int a[] ,int n)
{
    for(int i {0} ; i<n-1 ; i++)
    {
        int k {i} ;
        for(int j {i} ; j<n ; j++)
        {
            if(a[j]<a[k]) k = j ;
        }
        swap(a[i],a[k]) ;
    }
}
// TC : O(n) to O(n^2) 
// SC : O(1) i.e. inplace !
// NOT Adaptive 
// NOT Stable
int main()
{
    int a[] = {6,5,4,3,2,1} ;
    selectionsort(a,6) ;
    for(int i {0} ; i<6 ; i++) cout << a[i] << " " ; cout << endl;
}