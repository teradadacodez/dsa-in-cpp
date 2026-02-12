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
// main things are 
// 1. make an array of zeros and then apply all operations on it and then add the corresponding elements of the given array
// 2. to reduce time complexity we counted how many times each operation is implemented on the array by making a range frequency array rf and taking the prefix sum of it !
void samsooong()
{
    ll n , m , k ; cin >> n >> m >> k ;
    vector<ll> a(n) , arr(n,0) ;
    for(auto &i : a) cin >> i ;
    vector<vector<ll>> op(m) ;
    for(ll i {0} ; i<m ; i++)
    {
        ll l , r , d ; cin >> l >> r >> d ;
        l-- ; r-- ;
        op[i] = {l,r,d} ;
    }
    vector<ll> rf(m,0) ;
    while(k--)
    {
        ll x , y ; cin >> x >> y ;
        x-- ; y-- ;
        rf[x]++ ;
        if(y+1<m) rf[y+1]-- ;
    }
    for(ll i {0} ; i<m-1 ; i++) rf[i+1] += rf[i] ;
    for(ll i {0} ; i<m ; i++)
    {
        ll l {op[i][0]} , r {op[i][1]} , d {op[i][2]} , freq {rf[i]} ;
        arr[l] += freq*d ;
        if(r+1<n) arr[r+1] -= freq*d ;
    }
    for(ll i {0} ; i<n-1 ; i++) arr[i+1] += arr[i] ;
    for(ll i {0} ; i<n ; i++) arr[i] += a[i] ;
    for(auto i : arr) cout << i << " " ;
    cout << endl;
}