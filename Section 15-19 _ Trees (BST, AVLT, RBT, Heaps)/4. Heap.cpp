#include <bits/stdc++.h>
using namespace std;

void insert(int h[],int n)
{
    int i = n , temp = h[i] ;
    while(i>1 && temp>h[i/2])
    {
        h[i] = h[i/2] ;
        i = i/2 ;
    }
    h[i] = temp ;
}
int del(int h[],int n) // n is the currect size of heap !!
{
    int x = h[n] ;
    int val = h[1] ;
    h[1] = h[n] ;
    h[n] = val ;
    int i {1} , j {i*2} ;
    while(j<n-1)
    {
        if(h[j+1]>h[j]) j++ ;
        if(h[i]<h[j])
        {
            swap(h[i],h[j]) ;
            // use temp variable, this is just for ease 
            i = j ;
            j = 2*j ;
        }
        else break ;
    }
    return val ;
}
int main()
{
    int h[] = {0,10,20,30,25,5,40,35} ;
    // 40,25,35,10,5,20,30
    for(int i {0} ; i<8 ; i++) insert(h,i) ; // we are changing elements inside h only
    // no extra array is required, so this is called inplace heap !!
    for(int i {0} ; i<8 ; i++) cout << h[i] << " " ; cout << endl;
    // cout << "del : " << del(h,7) << endl;
    // cout << "del : " << del(h,6) << endl;
    // for(int i {0} ; i<8 ; i++) cout << h[i] << " " ; cout << endl;

    // if we call delete function in a loop then the finar array we would get will be sorted in 
    // O(nlog(n)) time !!!
    // this is called HEAP SORT !!
    for(int i {7} ; i>0 ; i--) del(h,i) ;
    for(int i {0} ; i<8 ; i++) cout << h[i] << " " ; cout << endl;
}