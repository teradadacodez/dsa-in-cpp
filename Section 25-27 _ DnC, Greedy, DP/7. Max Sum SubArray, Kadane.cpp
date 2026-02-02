#include <bits/stdc++.h>
using namespace std;

// mssa/MSSA : max sum sub array
pair<vector<int>,int> MSSA(vector<int>& a)
{
    int n {(int)a.size()} ;
    vector<int> dp(n,0) ;
    dp[0] = a[0] ;
    int mx {dp[0]} ;
    for(int i {1} ; i<n ; i++)
    {
        if(dp[i-1]<0) dp[i] = a[i] ;
        else dp[i] = dp[i-1]+a[i] ;
        mx = max(mx,dp[i]) ;
    } 
    return {dp,mx} ;
}
// TC : O(n) and SC : O(n) 
// aka kadane's algo if we do it in SC : O(1) i.e. inplace !!
pair<int,pair<int,int>> kadane(vector<int> a)
{
    int n {(int)a.size()} ;
    int s, mx ;
    s = mx = a[0] ;
    int start, end ;
    for(int i {1} ; i<n ; i++)
    {
        if(s<0)
        {
            s = a[i] ; start = i ;
        }
        else s+=a[i] ;
        if(s>mx)
        {
            mx = s ;
            end = i ;
        }
    }
    return {mx,{start,end}} ;
}
int main()
{
    vector<int> arr = {4,-5,8,-2,-1,7,-6} ;
    auto ans = MSSA(arr) ;
    for(auto i : ans.first) cout << i << " " ; cout << endl;
    cout << ans.second << endl;
    auto ans1 = kadane(arr) ;
    cout << "mx : " << ans1.first ;
    cout << " start,end : " << ans1.second.first << " " << ans1.second.second << endl;
}