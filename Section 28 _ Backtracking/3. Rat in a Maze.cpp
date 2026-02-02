#include <bits/stdc++.h>
using namespace std;

// rat in a maze problem, maze is a 2d array with -1 as solid and 0 as walkable cell
// we have to decide the priority order of directions the rat can move in
// like right-1 , down-2 , left-3 , up-4
// we can choose any order, backtracking algo will work no matter the order !!
// rim : rat in a maze
void rim(vector<vector<vector<char>>>& solution, vector<vector<char>>& maze, int r, int c)
{
    int n = (int)maze.size() ;
    int m = (int)maze[0].size() ;
    if(r==maze.size()-1 && c==maze[0].size()-1)
    {
        maze[r][c] = '*' ;
        solution.push_back(maze) ;
        maze[r][c] = '.' ;
        return ;
    }
    maze[r][c] = '*' ;
    if(c<m-1 && maze[r][c+1]=='.') rim(solution,maze,r,c+1) ;
    if(r<n-1 && maze[r+1][c]=='.') rim(solution,maze,r+1,c) ;
    if(c>0 && maze[r][c-1]=='.') rim(solution,maze,r,c-1) ;
    if(r>0 && maze[r-1][c]=='.') rim(solution,maze,r-1,c) ;
    maze[r][c] = '.' ;
}

int main()
{
    vector<vector<vector<char>>> sol ;
    vector<vector<char>> maze {
    {'.', '.', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'.', '.', '#', '.', '.', '.', '#', '#', '.', '#'},
    {'.', '#', '#', '#', '#', '#', '#', '.', '.', '#'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '#', '#'},
    {'.', '#', '.', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '.', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '#', '.', '.', '.'}
    };
    rim(sol,maze,0,0) ;
    for(auto i : sol)
    {
        for(auto j : i)
        {
            for(auto k : j) cout << k << " " ; 
            cout << endl;
        }
        cout << string(10,'-') << endl;
    }
}

