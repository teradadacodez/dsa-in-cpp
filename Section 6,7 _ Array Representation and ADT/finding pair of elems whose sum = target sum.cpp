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
    int n , k ; cin >> n >> k ;
    vector<int> arr(n) ;
    for(auto &i : arr) cin >> i ;
    // we can opt O(n^2) approach
    // but this is O(n) approach
    // this will work for both unsorted and sorted array !
    // this will not work for duplicate elements !
    // but for a sorted array we can have two , more efficient approaches !
    // first one in binary search and second one is two pointer !!
    // two pointer approach is simpler to code !!
    bool issor {is_sorted(arr.begin(),arr.end())} ;
    if(issor == true)
    {
        int i {0} , j{n-1} ;
        while(i<j)
        {
            int s {arr[i]+arr[j]} ;
            if(s == k) 
            {
                cout << arr[i] << " " << arr[j] << endl;
                i++ ; j-- ;
            }
            else if(s<k) i++ ;
            else j-- ;
        }
        return ;
    }

    int mx {0} ; 
    for(auto i : arr) mx = max(i,mx) ;

    int H[mx] ;
    for(int i {0} ; i<mx ; i++) H[i] = 0 ;

    for(auto i : arr)
    {
        if(H[k-i] == 1) cout << i << "+" << k-i << "=" << k << endl;
        H[i] = 1 ;
    }

}