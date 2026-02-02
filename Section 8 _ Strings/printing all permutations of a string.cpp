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

void helper1(string s , vector<bool>& used , vector<string>& ans , string& ss)
{
    if(ss.size()==s.size())
    { 
        ans.push_back(ss) ;
        return ;
    }
    for(int i {0} ; i<s.size() ; i++)
    {
        if(used[i]) continue ;
        ss.push_back(s[i]) ;
        used[i] = 1 ;
        helper1(s,used,ans,ss) ;
        ss.pop_back() ; // backtracking
        used[i] = 0 ; // backtracking
    }
}

void helper2(string &s , int ind)
{
    if(ind == s.size())
    {
        cout << s << " ";
        return ;
    }
    for(int i {ind} ; i<s.size() ; i++)
    {
        swap(s[i],s[ind]) ;
        helper2(s,ind+1) ;
        swap(s[i],s[ind]) ; // backtracking to normal state for further swapping 
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
    string s ; cin >> s; 
    vector<string> ans ;
    vector<bool> used(s.size(),0) ;
    string t {""} ;
    helper1(s,used,ans,t) ;
    for(auto i : ans) cout << i << " " ; cout << endl;
    helper2(s,0) ;
    cout << endl;
}