#include <bits/stdc++.h>
using namespace std;

// single source shortest path !!
// in this problem we try to find shortest path to all other vetices starting from the source vertex !
// what we have to do is, from a source we have to mark the distance (cost) if there is a direct edge
// otherwise infinity !!
// now select the nearest one and then update all the vertex distances connected to it !!
// dijkstra suggested a technique called relaxatation for the above task in which if we calculate
// we will take adjacency matrix for it !!

vector<int> Djikstra(vector<vector<int>> &cost, int start) // specify starting vertex
{   
    int n {(int)cost.size()-1} ;
    // we need a distance array for marking the initial distance and then updating inplace
    // also we need a visited array !!
    vector<bool> vis(n+1,0) ;
    vector<int> dist(n+1,INT_MAX) ;
    dist = cost[start] ;
    dist[start] = 0 ; // since distance of start from start is 0 !
    vis[start] = 1 ;
    for(int k {0} ; k<n-1 ; k++)
    {
        int mn {INT_MAX} , u {-1} ;
        for(int i {1} ; i<n+1 ; i++)
        {
            if(dist[i]<mn && vis[i]==0)
            {
                mn = dist[i] ;
                u = i ;
            }
        }
        vis[u] = 1 ;
        // uptill this we have just selected the minimum distance vertex, now we have to relax other vertices
        for(int v {1} ; v<n+1 ; v++)
        {
            if(vis[v]==0 && dist[u]+cost[u][v]<dist[v] && cost[u][v]<INT_MAX) dist[v]=dist[u]+cost[u][v] ;
        }
    }
    return dist ;
}
int main()
{
    int n = 6 ;
    vector<vector<int>> v(n+1,vector<int>(n+1)) ;
    
    int inf {INT_MAX} ;

    v = {{0,0,0,0,0,0,0},
        {0,inf,1,5,inf,inf,inf},
        {0,1,inf,3,10,8,inf},
        {0,5,3,inf,inf,2,inf},
        {0,inf,10,inf,inf,3,2},
        {0,inf,8,2,3,inf,7},
        {0,inf,inf,inf,2,7,inf}} ;

    vector<int> ans = Djikstra(v,1) ;
    for(auto i : ans) cout << i << " " ; cout << endl;
}