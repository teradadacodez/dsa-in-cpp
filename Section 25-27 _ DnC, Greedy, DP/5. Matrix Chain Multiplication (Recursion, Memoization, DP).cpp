#include <bits/stdc++.h>
using namespace std;

// matrix chain multiplication 
//   A  x  B  x  C  x  D 
// (3x2)x(2x4)x(4x2)x(2x5) ; these are dimensions of matrices above !!
// there can be multiple orders for multiplication of these like 
// 1. (AxB)x(CxD), 2. (Ax(BxC))xD etc...
// but the cost of only one process is minimum !!
// here cost refers how many individual elements multiplications are performed ! 

// we can form a tree for generating multiplication patterns by recursion 
// we will take a function m(int i, int j) i and j are first and last index !
// and we have a make an array for dimensions like d = [3,2,4,2,5] ;
int mcm1(int i, int j, vector<int> &d)
{
    if(i==j) return 0 ;
    int mn {INT_MAX} ;
    for(int k {i} ; k<j ; k++)
    {
        int cost = mcm1(i,k,d)+mcm1(k+1,j,d)+d[i-1]*d[k]*d[j] ;
        mn = min(mn,cost) ;
    }
    return mn ;
}
int mcm2(int i, int j, vector<int> &d, vector<vector<int>> &dp)
{
    if(i==j) return dp[i][j] = 0 ;
    if(dp[i][j]!=-1) return dp[i][j] ;
    dp[i][j] = INT_MAX ;
    for(int k {i} ; k<j ; k++)
    {
        dp[i][k] = mcm2(i,k,d,dp) ;
        dp[k+1][j] = mcm2(k+1,j,d,dp) ;
        int cost = dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j] ;
        dp[i][j] = min(cost,dp[i][j]) ;
    }
    return dp[i][j] ;
}
// 2D dp formula : dp[i][j] = (for all i<=k<j)min{dp[i][k]+dp[k+1][j]+d[i-1]*d[k]*d[j]} ;
int mcm3(vector<int> &d, vector<vector<int>> &dp)
{
    int n = dp.size()-1 ;
    for(int i {1} ; i<=n ; i++) dp[i][i] = 0 ;

    for(int diff {1} ; diff<n ; diff++)
    {
        for(int i {1} ; i<=n-diff ; i++)
        {
            int j = i + diff ;
            dp[i][j] = INT_MAX ;
            for(int k {i} ; k<j ; k++)
            {
                int cost = dp[i][k]+dp[k+1][j]+d[i-1]*d[k]*d[j] ;
                dp[i][j] = min(cost,dp[i][j]) ;
            }
        }
    }
    return dp[1][n-1] ;
}
int main()
{
    vector<int> d {3,2,4,2,5} ;
    int n = d.size() ;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1)) ;
    cout << mcm1(1,4,d) << endl;
    cout << mcm2(1,4,d,dp) << endl;
    cout << mcm3(d,dp) << endl;
}