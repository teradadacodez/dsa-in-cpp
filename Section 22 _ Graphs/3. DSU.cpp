#include <bits/stdc++.h>
using namespace std;
vector<int> superset(11,-1) ; // 1 based !!
void unionw(int u,int v)
{
    if(superset[u]<superset[v])
    {
        superset[u]+=superset[v] ;
        superset[v] = u ;
    }
    else
    {
        superset[v] += superset[u] ;
        superset[u] = v ;
    }
}
int root(int u) // find main root !! 
{
    while(superset[u]>0) u = superset[u] ;
    return u ;
}
int find(int u) // this also is the same as above !!
{
    return root(u) ;
}
int main()
{
    vector<int> a = {3,5,9} ;
    vector<int> b = {4,7,8,10} ;
    // a and b are disjoint subsets of the set 1,2...10
    // now how do we represent these sets is :
    // we can select any element as head, for now
    // we select first element as head, then
    superset[a[0]] = -(int)a.size() ; // - sign indicates that it's the the parent or head node !!
    superset[b[0]] = -(int)b.size() ;
    // to show rest elements as children of a[0] and b[0]
    for(int i{1} ; i<a.size() ; i++) superset[a[i]] = a[0] ;
    for(int i {1} ; i<b.size() ; i++) superset[b[i]] = b[0] ;

    for(auto i : superset) cout << i << " " ; cout << endl;
    // let rest elements remain -1 !!
    // now we can perform two operations 1. Union (aka weighted union) and 2. Find (aka collapsing find)
    // a U b = {3,4,5,7,8,9,10} ;
    // now how to represent aUb in superset ?
    // select the head/parent node among previous parent nodes who has more elements in the subset
    // here b[0] = 4 is the new head node !
    unionw(a[0],b[0]) ;
    for(auto i : superset) cout << i << " " ; cout << endl;
    cout << root(5) << endl;
    cout << find(2) << endl;   
}