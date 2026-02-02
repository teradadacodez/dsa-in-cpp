#include <bits/stdc++.h>
using namespace std;

// there are two strings or array of char/int and we have to find longest common subsequence 
// we can have two pointers i and j and if values match increment both 
// other wise we have two options 1. increment only i and check or 2. increment only j and check
// we should start from end of a string since a recursion is advised to be decremented !!
// also we check by decrementing i and j 
int lcs1(int i, int j,const string& s1,const string& s2)
{
    if(i==0 || j==0) return 0 ;
    if(s1[i] == s2[j]) return 1+lcs1(i-1,j-1,s1,s2) ;
    return max(lcs1(i-1,j,s1,s2),lcs1(i,j-1,s1,s2)) ;
}
// using memoization 
int lcs2(int i, int j, const string& s1, const string& s2,vector<vector<int>>& dp)
{
    if(i==0 || j==0) return dp[i][j] = 0 ;
    if(dp[i][j] != -1) return dp[i][j] ;
    if(s1[i] == s2[j]) return dp[i][j] = 1+lcs2(i-1,j-1,s1,s2,dp) ;
    return dp[i][j] = max(lcs2(i-1,j,s1,s2,dp),lcs2(i,j-1,s1,s2,dp)) ;
}
// tabulation, 2D dp formula : 
int lcs3(const string& s1, const string& s2,vector<vector<int>>& dp)
{
    int n = (int)s1.size() ;
    int m = (int)s2.size() ;
    for(int i {0} ; i<n ; i++) dp[i][0] = 0 ;
    for(int i {0} ; i<m ; i++) dp[0][i] = 0 ;
    for(int i {1} ; i<=n ; i++)
    {
        for(int j {1} ; j<=m ; j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1] ;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
        }
    }
    return dp[n][m] ;
}
int main()
{
    string s1 {"abcde"} , s2 {"ace"} ;
    int n {(int)s1.size()} , m {(int)s2.size()} ;
    cout << lcs1(n,m,s1,s2) << endl;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1)) ;
    cout << lcs2(n,m,s1,s2,dp) << endl;
    cout << lcs3(s1,s2,dp) << endl;
}