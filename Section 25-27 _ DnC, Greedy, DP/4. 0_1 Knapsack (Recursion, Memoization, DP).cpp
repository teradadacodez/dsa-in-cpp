#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming !!
// used for optimization problems (minimization or maximization)
// it says, you have to solve problem in stages and in each stage you have to take decisions
// and these decisions will carry you the most optimal solution (aka primcipal of optimality) !!
// generates tabular data, uses memoization (to reduce excessive calls) !!
// it's a method to convert recurrsion into iteration 
// where greedy is not possible, dp gives the solution
// after using dp, people realized that we can directly fill up the table 


// Problem : 0/1 Knapsack !!
// here either we take the full object or totally discard it (no fractional like greedy) !!

// n is number of items , m is capacity of bag , p and w are arrays of profit and weights
int knapsack1(int n, int m, vector<int> &p, vector<int> &w)
{
    if(n==0 || m==0) return 0 ;
    if(w[n-1]>m) return knapsack1(n-1,m,p,w) ; // skip this object 
    int take = knapsack1(n-1,m-w[n-1],p,w)+p[n-1] ;
    int skip = knapsack1(n-1,m,p,w) ;
    return max(take,skip) ;
}
int knapsack2(int n , int m , vector<int> &p , vector<int> &w, vector<vector<int>> &dp)
{
    if(n==0 || m==0) return dp[n][m] = 0 ; 
    if(dp[n][m] != -1) return dp[n][m] ;
    int temp = knapsack2(n-1,m,p,w,dp) ;
    if(w[n-1]<=m) temp = max(temp,knapsack2(n-1,m-w[n-1],p,w,dp)+p[n-1]) ;
    return dp[n][m] = temp ;
}
// memoization is used to reduce same recurrsive calls 
// 2D dp formula is given as dp[n][m] = max(dp[n-1][m],dp[n-1][m-w[n]]+p[n]) !
int knapsack3(int n, int m, vector<int>& p, vector<int> &w) 
{
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;
    for(int i {1} ; i<=n ; i++)
    {
        for(int j {1} ; j<=m ; j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+p[i-1]) ;
        }
    }
    return dp[n][m] ;
}
int main()
{
    vector<int> p {6,5,3,8} ;
    vector<int> w {1,2,1,2} ;
    int n {(int)w.size()} , m {5} ;
    vector<vector<int>> dp (n+1,vector<int>(m+1,-1)) ;
    cout << knapsack1(n,m,p,w) << endl;
    cout << knapsack2(n,m,p,w,dp) << endl;
    cout << knapsack3(n,m,p,w) << endl;
}