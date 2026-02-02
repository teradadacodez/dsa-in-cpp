#include <bits/stdc++.h>
using namespace std;
// uses idea of insertion sort 
// TC : O(nlogn) or if gap is prime numbers then O(n^(3/2)) or sometimes O(n^(5/3))
// SC : O(1) i.e. inplace !!
void shellsort(int a[] ,int n)
{
    int gap , i , j , temp ;
    for(gap = n/2 ; gap>0 ; gap/=2)
    {
        for(i = gap ; i<n ; i++)
        {
            temp = a[i] ;
            j = i-gap ;
            while(j>=0 && a[j]>temp)
            {
                a[j+gap] = a[j] ;
                j-=gap ;
            }
            a[j+gap] =  temp ;
        }
    }
}

int main()
{
    int a[] = {9,8,7,6,5,4,3,2,1} ;
    shellsort(a,9) ; 
    for(int i {0} ; i<9 ; i++) cout << a[i] << " " ; cout << endl;
}