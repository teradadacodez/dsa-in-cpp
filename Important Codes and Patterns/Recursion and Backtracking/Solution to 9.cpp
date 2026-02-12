/*
    ******        **        ***      ***  ******     **        **        **     ***      **  *********
    **           ****       ** *    * **  **        *  *      *  *      *  *    ** *     **  **        
    **          **  **      **  *  *  **  **       *    *    *    *    *    *   **  *    **  **        
    ******     ********     **   **   **  ******  *      *  *      *  *      *  **   *   **  **  ******
        **    **      **    **        **      **   *    *    *    *    *    *   **    *  **  **      **
        **   **        **   **        **      **    *  *      *  *      *  *    **     * **  ********* 
    ******  **          **  **        **  ******     **        **        **     **      ***  *******  
*/
#include <bits/stdc++.h>
#define ll long long
#define inf 200005
#define INF 1000000007
#define sep cout << string(10,'=') << endl

using namespace std;

void samsooong();

void helper(int ind , string s , vector<string>& ans , string& num)
{
    int n = num.size() ;
    if(ind == n)
    {
        ans.push_back(s) ; return ;
    }
    if(num[ind] == '0') return ;
    if(ind == n-1)
    {
        int temp = num[ind]-'0' ;
        s.push_back(temp +'a'-1) ;
        helper(ind+1,s,ans,num) ;
        return ;
    }
    if(num[ind+1] == '0')
    {
        int temp = (num[ind]-'0')*10 + (num[ind+1]-'0') ;
        s.push_back(temp + 'a' - 1) ;
        helper(ind+2,s,ans,num) ;
        return ;
    }
    int temp {(num[ind] - '0')*10 + (num[ind+1]-'0') } ;
    if(temp>26)
    {
        int g = num[ind]-'0' ;
        s.push_back(g+'a'-1) ;
        helper(ind+1,s,ans,num) ;
        return ;  
    }
    else
    {
        int g = num[ind]-'0' ;
        s.push_back(g+'a'-1) ;
        helper(ind+1,s,ans,num) ;
        s.pop_back() ;
        s.push_back(temp+'a'-1) ;
        helper(ind+2,s,ans,num) ;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    auto start = chrono::high_resolution_clock::now() ;
    int T ; cin >> T ;
    while(T--) samsooong() ;
    auto stop = chrono::high_resolution_clock::now() ;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop-start) ;
    cerr << "Time elapsed : " << time.count() << " μs " << endl;
}
void samsooong()
{
    string s ; cin >> s ;
    vector<string> ans ;
    helper(0,"",ans,s) ;
    for(auto i : ans) cout << i << " " ; cout << endl;

}