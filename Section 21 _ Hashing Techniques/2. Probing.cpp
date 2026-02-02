#include <bits/stdc++.h>
using namespace std;
#define sz 10
// if loading factor in <lambda> = l then for
// linear probing 
// TC : 1. avg. successful search = (1/l)*ln(1/(1-l)) ;
//      2. avg. unsuccessful search = 1/(1-l) ;
// quadratic probing
// TC : 1. avg. successful search = ln(1-l)/l
//      2. avg. unsuccessful search = 1/l
// l <= 0.5 to achieve these TC !!!!
int hf(int x) {return x%sz ;}
int probe(int hash[],int key)
{
    int ind = hf(key) ;
    int i {0} ;
    while(hash[(ind+i)%sz]) i++ ; // change ind+i to ind+i*i for quadratic probing !!
    return (ind+i)%sz ; // change here
}
void insert(int hash[] , int key)
{
    int ind = hf(key) ;
    if(hash[ind]) ind=probe(hash,key) ;
    hash[ind] = key ;
}
int search(int hash[] , int key)
{
    int ind = hf(key) ;
    int i = 0 ;
    while(hash[(ind+i)%sz]!=key) i++ ; // change here
    return (ind+i)%sz ; // change here
}
int main()
{
    int hash[sz] = {0} ;
    insert(hash,12) ; // inserted at 12 
    insert(hash,13) ; // inserted at 13
    insert(hash,22) ; // inserted at 14 !! (checks 12, then 13, then 14)
    for(int i {0} ; i<sz ; i++) cout << hash[i] << " " ; cout << endl;
    cout << "at : " << search(hash,22) << endl;
}