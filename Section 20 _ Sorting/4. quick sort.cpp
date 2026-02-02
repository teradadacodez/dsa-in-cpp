#include <bits/stdc++.h>
using namespace std;

// Quick Sort : an element is said to be in sorted position if elements before it (smaller indices) 
// are smaller than it and elements after it (greter indices) are greater than it !!
// here we select element first and find it's suitable position that's why it is aka
// Selection Exchange Sort / Partition Exchange Sort !

int partition(int a[] , int l , int h)
{
    int pivot {a[l]} ; // first element as pivot 
    // we can choose any element as pivot !!
    int i = l+1 , j = h ;
    while(true)
    {
        while(i<=j && a[i]<=pivot) i++ ;
        while(j>=i && a[j]>pivot) j-- ;
        if(j<i) break ;
        else swap(a[i],a[j]) ;
    }
    swap(a[l],a[j]) ; // element at j is in it's sorted position !!
    return j ;
}

void quicksort(int a[] , int l ,int h)
{
    if(l<h)
    {
        int p = partition(a,l,h) ;
        quicksort(a,l,p-1) ;
        quicksort(a,p+1,h) ;
    }
}

int main()
{
    int a[] = {6,5,4,3,2,1} ;
    quicksort(a,0,6) ;
    for(int i {0} ; i<6 ; i++) cout << a[i] << " " ; cout << endl;
}