#include <bits/stdc++.h>
using namespace std;
// minimum cost spanning tree
// Definition of SPANNING TREE : it's a subgraph of a connected graph
// such that it has all vertices, one less adjusts than the parent graph
// and all the nodes conneted with no cycle formation !!!

// there are two standard algos for this 
// 1. KRUSKAL'S ALGO
// 2. PRIM'S ALGO   


// 1. Kruskal's algo says that always select a minimum cost edge such that
// it does form a cycle !!
// if we try to apply this on a non connected graph with two or more components 
// then we would get the MST for each component !!
// here we can use minheap to get the minimum element always (priority queue)
// and DSU to detect cycle formation !!
// here, the data structure used to store the graph is edge list
// i.e. list of (u,v,cost) !! u,v are vertices and cost is the weight
// of the edge connecting nodes u and v !!
class DSU
{
    vector<int> parent ;
    public : 
    DSU(int n = 10) : parent(n+1,-1) {} 
    int root(int u)
    {
        if(parent[u]<0) return u ;
        return parent[u] = root(parent[u]) ; 
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
    vector<tuple<int,int,int>> edges {{1,2,28},
                                      {1,6,10},
                                      {2,3,16},
                                      {2,7,14},
                                      {3,4,12},
                                      {4,5,22},
                                      {4,7,18},
                                      {5,6,25},
                                      {5,7,24}} ;

    int n {7} ; // number of vertices !!

    sort(edges.begin(),edges.end(),[](auto &e1 , auto &e2){return get<2>(e1)<get<2>(e2) ;}) ;
    // sorted acending wrt weights
    // this does not select the initial vertex as 1 it selects the initial vertex which has minimum
    // cost 

    DSU dsu(n) ;

    vector<tuple<int,int,int>> mst ;
    for(auto &e : edges)
    {
        int u,v,w ;
        tie(u,v,w) = e ;
        if(dsu.root(u) != dsu.root(v))
        {
            dsu.unite(u,v) ;
            mst.push_back(e) ;
            if(mst.size() == (size_t)n-1) break ;
        }
    }
    int cost {0} ;
    for(auto i : mst)
    {
        int u,v,w ;
        tie(u,v,w) = i ;
        cout << u << " " << v << " " << w << endl;
        cost += w ;
    }
    cout << "min cost : " << cost << endl;
}   

// here the sorting takes nlogn time and the further loop are all n so TC : O(nlogn) 