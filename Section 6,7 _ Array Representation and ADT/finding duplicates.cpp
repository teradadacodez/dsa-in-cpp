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
    int n ; cin >> n;
    vector<int> arr(n) ;
    for(auto &i : arr) cin >> i ;
    // for(auto i : arr) cout << i << " " ; cout << endl;
    bool issor {is_sorted(arr.begin(),arr.end())} ;
    // cout << boolalpha << issor << endl; 
    if(issor == false) 
    {
        int mx {0} ;
        for(auto i : arr) mx = max(i,mx) ;
        int H[mx] ;
        for(int i {0} ; i<=mx ; i++) H[i] = 0 ;
        for(auto i : arr) H[i]++ ;
        for(int i {0} ; i<=mx ; i++) if(H[i]>1)
        {
            cout << "duplicates of " << i << " are : " << H[i]-1 << endl;
        }
        return ;
    }
    // this in only for sorted array because if there are 

    for(int i {0} ; i<n ; i++)
    {
        if(arr[i] == arr[i+1])
        {
            int j {i+1} ;
            while(arr[j] == arr[i]) j++ ;
            cout << "duplicates of " << arr[i] << " are : " << j-i-1 << endl;
            i=j-1 ; 
        }
    }
}