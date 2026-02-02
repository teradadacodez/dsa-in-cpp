#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent ;
    public : 
    DSU(int n = 10) : parent(n+1,-1) {} // 1 based indexing 
    int root(int u)
    {
        if(parent[u]<0) return u ;
        return parent[u] = root(parent[u]) ; // aka path compression
    }
    void unite(int u, int v)
    {
        u = root(u) ;
        v = root(v) ;
        if(u==v) return ;
        if(parent[u]<parent[v])
        {
            parent[u] += parent[v] ;
            parent[v] = u ;
        }
        else
        {
            parent[v] += parent[u] ;
            parent[u] = v ;
        }
    }
    void display()
    {
        for(auto i : parent) cout << i << " " ; cout << endl;
    }
};

int main()
{
    DSU dsu ;
    dsu.unite(4,5) ;
    dsu.display() ;
    dsu.unite(4,4) ;
    dsu.display() ;
    dsu.unite(4,3) ;
    dsu.display() ;
    dsu.unite(2,4) ;
    dsu.display() ;
}