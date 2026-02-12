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

int main()
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
// this problem is when we have to find the final state of the given array after doing some operations 
// which looks as l,r,d (from l to r we have to add d to it) !!
void samsooong()
{
    int n ; cin >> n ;
    vector<int> arr(n,0) , brr(n,0) ;
    int q ; cin >> q ; 
    // brr is the brute force solution of the problem 
    // arr is the difference array solution of the problem 
    while(q--)
    {
        int l , r , x ; cin >> l >> r >> x ;
        l-- , r-- ;
        for(int i {l} ; i<=r ; i++) brr[i] += x ;
        arr[l] += x ;
        if(r<n-1) arr[r+1] -= x ;
    }
    cout << "arr is : " << endl;
    for(auto i : arr) cout << i << " " ;
    cout << endl;
    cout << "brr is : " << endl;
    for(auto i : brr) cout << i << " " ; 
    cout << endl;
    vector<int> pf(n) ;
    pf[0] = arr[0] ;
    for(int i {0} ; i<n-1 ; i++) pf[i+1] = pf[i] + arr[i+1] ;
    cout << "arr after prefix sum is : " << endl;
    for(auto i : pf) cout << i << " " ; 
    cout << endl;
}