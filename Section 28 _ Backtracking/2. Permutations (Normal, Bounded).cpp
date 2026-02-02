#include <bits/stdc++.h>
using namespace std;

// generates all permulations with repetitions !!
void permutations(string& s, string& p, vector<string>& ans, vector<bool>& vis)
{
    if(p.size() == s.size())
    {
        ans.push_back(p) ;
        return ;
    }
    for(int i {0} ; i<s.size() ; i++)
    {
        if(vis[i]) continue ;
        vis[i] = 1 ;
        p.push_back(s[i]) ;
        permutations(s,p,ans,vis) ;
        p.pop_back() ;
        vis[i] = 0 ;
    }
}
// we can introduce a bounding function which can impose a condition 
// on answers that we want these answers only
// ex : no consecutive letters in alphabetical order like ABC or CAB (not allowed), ACB or CBA (allowed)
void bounded_permutations(string& s, string& p, vector<string>& ans, vector<bool>& vis)
{
    if(p.size() == s.size())
    {
        ans.push_back(p) ;
        return ;
    }
    for(int i {0} ; i<s.size() ; i++)
    {
        if(vis[i]) continue ;
        if(!p.empty() && s[i]-p.back() == 1) continue; // bounding condition
        vis[i] = 1 ;
        p.push_back(s[i]) ;
        bounded_permutations(s,p,ans,vis) ;
        p.pop_back() ;
        vis[i] = 0 ;
    }
}
int main()
{
    vector<string> ans ;
    string s {"abc"} ;
    vector<bool> vis(s.size(),0) ;
    string p,pp ;
    permutations(s,p,ans,vis) ;
    vector<string> anss ;
    vector<bool> viss(s.size(),0) ;
    bounded_permutations(s,pp,anss,viss) ;
    for(auto i : ans) cout << i << " " ; cout << endl;
    for(auto i : anss) cout << i << " " ; cout << endl;
}