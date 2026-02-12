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

// to find whether a subset of an array has a sum equal to a target sum or not !!
bool helper(int ind, int s , int n , vector<int>& arr , int& sum)
{
    if(s==sum) return true ;
    if(ind>=n) return false ;
    if(s>sum) return false ;
    bool ans = helper(ind+1,s+arr[ind],n,arr,sum) ;
    if(ans == true) return true ;
    ans = helper(ind+1,sum,n,arr,sum) ;
    return ans ;

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
    samsooong() ;
    auto stop = chrono::high_resolution_clock::now() ;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop-start) ;
    cerr << "Time elapsed : " << time.count() << " μs " << endl;
}
void samsooong()
{
    int n ; cin >> n ;
    vector<int> arr(n) ; 
    for(auto &i : arr) cin >> i;
    int sum ; cin >> sum ;
    bool ans {helper(0,0,n,arr,sum)} ;
    cout << boolalpha << ans << endl;
}