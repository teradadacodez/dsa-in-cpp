#include <bits/stdc++.h>
using namespace std;

// recurrsive binary search (divide and conquer) !!
int binsearch(vector<int> &a, int l, int h, int x)
{
    if(l>h) return -1 ;
    int mid = (l+h)/2 ;
    if(x==a[mid]) return mid ;
    if(x<a[mid]) return binsearch(a,l,mid-1,x) ;
    else return binsearch(a,mid+1,h,x) ;
}

// recurrsive merge sort
void helper(vector<int> &a, int l, int h)
{
    vector<int> b(a.size(),0) ;
    int mid {(l+h)/2} ;
    int i {l}, j{mid+1}, k {0} ;
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j]) b[k++] = a[i++] ;
        else b[k++] = a[j++] ;
    }
    for(;i<=mid ; i++) b[k++] = a[i] ;
    for(;j<=h ; j++) b[k++] = a[j] ;
    for(int i {l} ; i<=h ; i++) a[i] = b[i-l] ;
}
void recmerge(vector<int> &a, int l, int h)
{
    if(l>=h) return ;
    int mid {(l+h)/2} ;
    recmerge(a,l,mid) ;
    recmerge(a,mid+1,h) ;
    helper(a,l,h) ;
}
int main()
{
    vector<int> a {1,2,3,4,5,6,7,8} ;
    cout << binsearch(a,0,a.size(),4) << endl;
    vector<int> b {3,5,4,7,1,2,8} ;
    recmerge(b,0,b.size()-1) ;
    for(auto i : b) cout << i << " " ; cout << endl;
}