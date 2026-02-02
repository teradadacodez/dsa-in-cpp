#include <bits/stdc++.h>
using namespace std;

void bubblesort(int a[],int n)
{
    for(int i {0} ; i<n ; i++)
    {
        bool flag {true} ;
        for(int j {0} ; j<n-i-1 ; j++)
        {
            if(a[j]>a[j+1]) 
            {
                swap(a[j],a[j+1]) ;
                flag = false ;
            }
        }
        if(flag) break ; // if flag == true then no swaps happen in first iteration of the 
        // outer for loop, i.e. the array was already sorted !!
    }
}
// TC : O(n) to O(n^2)
// SC : O(1)  
// we made bubble sort adaptive by ourselves, it's not adaptive by nature !!
// it is stable, it does not change the order of duplicate elements
int main()
{
    int a[] = {9,8,7,6,5,4,3,2,1} ;
    bubblesort(a,9) ;
    for(int i {0} ; i<9 ; i++) cout << a[i] << " " ; cout << endl;
}