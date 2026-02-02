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
    samsooong() ;
    auto stop = chrono::high_resolution_clock::now() ;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop-start) ;
    cerr << "Time elapsed : " << time.count() << " μs " << endl;
}
void samsooong()
{
    string s , t ;
    getline(cin,s) ;
    getline(cin,t) ;
    for(auto &i : s) tolower(i) ;
    for(auto &i : t) tolower(i) ;
    int x {0} ;
    for(auto i : s)
    {
        if(s[i]==32) continue ;
        x|=(1<<(i-97)) ;
    }
    for(auto i : t) 
    {
        if(t[i]==32) continue ;
        if(!(x&(1<<(i-97))))
        {
            cout << "No \"" << s << "\" and \"" << t << "\" are not Anagrams" << endl;
            return ;
        }
    }
    cout << "Yes \"" << s << "\" and \"" << t << "\" are Anagrams" << endl;
}