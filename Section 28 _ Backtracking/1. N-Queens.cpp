#include <bits/stdc++.h>
using namespace std;

// N-Queens using BACKTRACKING 
bool helper(int r, int c, vector<string> board, int n)
{
    for(int i {r} ; i>=0 ; i--) if(board[i][c] == 'Q') return false ;
    for(int i {r} , j {c} ; i>=0 && j>=0 ; i--,j--) if(board[i][j] == 'Q') return false ;
    for(int i {r} , j {c} ; i>=0 && j<n ; i--,j++) if(board[i][j] == 'Q') return false ;
    return true ;
}
// r is the row number 
void nqueens(int r, int n, vector<vector<string>>& ans, vector<string>& board)
{
    if(r==n)
    {
        ans.push_back(board) ;
        return ;
    }
    for(int i {0} ; i<n ; i++)
    {
        if(helper(r,i,board,n)==false) continue ;
        board[r][i] = 'Q' ;
        nqueens(r+1,n,ans,board) ;
        board[r][i] = '.' ;
    }
}
int main()
{
    int n {4} ;
    vector<vector<string>> ans ;
    vector<string> board(n,string(n,'.')) ;
    nqueens(0,n,ans,board) ;
    for(auto i : ans)
    {
        for(auto j : i) cout << j << endl ;
        cout << endl << string(n,'=') << endl;
    }
}