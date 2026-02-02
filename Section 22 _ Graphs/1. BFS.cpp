#include <bits/stdc++.h>
using namespace std;
 
void BFS(const vector<vector<int>> &g , int i) // generally iterative !!
{
    int n {g.size()} ;
    vector<int> vis(n,0) ;
    queue<int> q ;
    cout << i << " " ;
    vis[i] = 1 ;
    q.push(i) ;
    while(!q.empty())
    {
        int u = q.front() ; q.pop() ;
        for(int j {1} ; j<n ; j++)
        {
            if(g[u][j] == 1 && vis[j] == 0)
            {
                cout << j << " " ;
                vis[j] = 1 ; 
                q.push(j) ;
            }
        }
    }
    cout << endl;
}

int main (){
 
    vector<vector<int>> v(7,vector<int>(7)) ; 
    v = {{0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    BFS(v,0) ;
 
}