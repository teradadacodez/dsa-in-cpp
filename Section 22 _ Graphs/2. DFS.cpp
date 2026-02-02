#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>> &g , int i , vector<int>& vis) // recurrsive DFS !!
{
    cout << i << " " ; 
    vis[i] = 1 ;
    int n = g.size() ;
    for(int j {0} ; j<n ; j++) if(g[i][j] == 1 && vis[j] == 0) dfs(g,j,vis) ;
}
void DFS(const vector<vector<int>> &g , int i) // wrapper function for dfs !!
{
    int n = g.size() ;
    vector<int> vis(n,0) ;
    dfs(g,i,vis) ;
    cout <<endl;
}

int main (){
 
    vector<vector<int>> v = {{0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    DFS(v,0) ;
 
}