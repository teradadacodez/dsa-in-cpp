#include <bits/stdc++.h>
using namespace std;

bool check(int num, vector<vector<int>>& sudoku, int r, int c)
{
    for(int i {0} ; i<9 ; i++) if(sudoku[r][i] == num || sudoku[i][c] == num) return false ;
    int br = r-r%3 ;
    int bc = c-c%3 ;
    for(int i {0} ; i<3 ; i++) for(int j {0} ; j<3 ; j++) if(sudoku[br+i][bc+j]==num) return false ;
    return true ;

}
void sudokusolver(vector<vector<vector<int>>>& solution, vector<vector<int>>& sudoku,int r, int c)
{
    if(r==9)
    {
        solution.push_back(sudoku) ;
        return ;
    }
    if(sudoku[r][c]!=0) return sudokusolver(solution,sudoku,c==9?r+1:r,c==9?1:c+1) ;
    for(int i {1} ; i<=9 ; i++)
    {
        if(check(i,sudoku,r,c)==false) continue ;
        sudoku[r][c] = i ;
        sudokusolver(solution,sudoku,c==9?r+1:r,c==9?1:c+1) ;
        sudoku[r][c] = 0 ;
    }
}

int main()
{
    vector<vector<vector<int>>> solutions ;
    vector<vector<int>> sudoku {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    sudokusolver(solutions,sudoku,0,0) ;
    for(auto i : solutions)
    {
        for(auto j : i)
        {
            for(auto k : j) cout << k << " " ; 
            cout << endl;
        }
        cout << string(10,'=') << endl;
    }
}