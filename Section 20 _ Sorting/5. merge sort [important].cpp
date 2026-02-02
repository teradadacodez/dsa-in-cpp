#include <bits/stdc++.h>
using namespace std;

// MERGING TWO SORTED LIST INTO ONE SORTED LIST USING TWO POINTERS !!

void mergesort(int a[] , int b[] , int n , int m, int ans[]) // with two different sorted arrays
{
    int i {0} , j {0} , k {0} ;
    while(i<n && j<m)
    {
        if(a[i]<b[j]) ans[k++] = a[i++] ;
        else ans[k++] = b[j++] ;
    }
    for(;i<n;i++) ans[k++] = a[i] ;
    for(;j<m;j++) ans[k++] = b[j] ;
}
// merge sort with one single array
// the array must be like a sorted array concatenated with another sorted array
// like 2,4,6,8,1,3,5,7,9 ; mid = 4 (index at which another array starts
void mergesort1(int a[],int n)
{
    int mid {-1} ;
    int b[n] ;
    for(int i {1} ; i<n ; i++)
    {
        if(a[i-1] > a[i])
        {
            mid = i ; break ;
        }
    }
    if(mid == -1) return ;

    int i {0} , j {mid} , k {0} ;
    while(i<mid && j<n)
    {
        if(a[i]<a[j]) b[k++] = a[i++] ;
        else b[k++] = a[j++] ;
    }
    for(;i<mid;i++) b[k++] = a[i] ;
    for(;j<n;j++) b[k++] = a[j] ;
    for(int i {0} ; i<n ; i++) a[i] = b[i] ;
}

// iterative merge sort !
void merge(int a[] , int l , int mid , int h) // helper for iterative and recursive merge sort !!
{
    int b[h-l+1] ;
    int i {l} , j {mid+1} , k {0} ;
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j]) b[k++] = a[i++] ;
        else b[k++] = a[j++] ;
    }
    for(;i<=mid;i++) b[k++] = a[i] ;
    for(;j<=h;j++) b[k++] = a[j] ;
    for(int i {l} ; i<=h ; i++) a[i] = b[i-l] ;
}
void iterative_merge_sort(int a[] ,int n)
{
    int l , mid , h , p ;
    for(p=2 ; p<=n ; p*=2)
    {
        for(int i {0} ; i+p-1<n ; i+=p)
        {
            l = i ; h = i+p-1 ;
            mid = (l+h)/2 ;
            merge(a,l,mid,h) ;
        }
    }
    if(p/2 < n) merge(a,0,p/2-1,n-1) ; // for odd number of elements
}
// recursive merge sort !!

void recursive_merge_sort(int a[], int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2 ;
        recursive_merge_sort(a,l,mid) ;
        recursive_merge_sort(a,mid+1,h) ;
        merge(a,l,mid,h) ;
    }
}
signed main()
{
    int a[] = {2,4,6,8} ;
    int n {4} ;
    int m {5} ;
    int b[] = {1,3,5,7,9} ;
    int ans[n+m] ;
    mergesort(a,b,n,m,ans) ;
    for(int i {0} ; i<9 ; i++) cout << ans[i] << " " ; cout << endl;

    int c[] = {2,4,6,8,1,3,5,7,9} ;
    mergesort1(c,9) ;
    for(int i {0} ; i<9 ; i++) cout << c[i] << " " ; cout << endl;

    int d[] = {2,1,4,3,6,5,8,7,9} ;
    iterative_merge_sort(d,9) ;
    for(int i {0} ; i<9 ; i++) cout << d[i] << " " ; cout << endl;

    int e[] = {2,1,4,3,6,5,8,7,9} ;
    recursive_merge_sort(e,0,8) ;
    for(int i {0} ; i<9 ; i++) cout << e[i] << " " ; cout << endl;
}