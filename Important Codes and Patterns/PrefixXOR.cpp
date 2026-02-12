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
    int T ; cin >> T ;
    while(T--) samsooong() ;
    auto stop = chrono::high_resolution_clock::now() ;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop-start) ;
    cerr << "Time elapsed : " << time.count() << " μs " << endl;
}
void samsooong()
{
    int n ; cin >> n ;
    vector<int> arr(n) , pf(n) ;
    for(auto &i : arr) cin >> i ;
    pf[0] = arr[0] ;
    for(int i {1} ; i<n ; i++) pf[i] = pf[i-1]^arr[i] ;
    // prefix xor array !!! 
    // since a[i]^a[i+1]^a[i+2]^....^a[j] = a[1]^...^a
    int q ; cin >> q ;
    while(q--)
    {
        int l , r ;
        l-- ; r-- ; // convert to 0 based indexing 
        cout << (pf[r]^(l==0 ? 0 : pf[l-1])) << endl;
    }
}