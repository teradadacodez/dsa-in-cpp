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
void samsooong()
{
    // we are given an array of N elements , answer the following q queries 
    // query : [l,r] ;
    // we need to print a[l] + 2*a[l+1] + 3*a[l+2] + ..... + (r+l-1*)a[r] ;
    // this is kind of a subarray sum problem so first intution is to calculate prefixsum array
    int n ; cin >> n ;
    vector<int> arr(n) , p(n+1,0) ;
    for(auto &i : arr) cin >> i ; 
    for(int i {0} ; i<n ; i++) p[i+1] = p[i] + arr[i] ;

    // cout << "Normal Prefix Sum Array : " << endl;
    // for(auto i : p) cout << i << " " ;
    // cout << endl;

    // now we can write it in summation as 
    // sum(l to r) {(i-l+1)*a[i]} = sum(l to r) {i*a[i]} + (l-1)*sum(l to r) {a[i]} ;
    // first term is the prefix sum of the array a[1] + 2*a[2] + 3*a[3] + ....
    // second term we calculated earlier it's just the normal prefix sum 
    vector<int> ps(n+1) ;
    for(int i {0} ; i<n ; i++) ps[i+1] = ps[i] + (i+1)*arr[i] ;

    // cout << "Modified Prefix Sum Array : " << endl;
    for(auto i : ps) cout << i << " " ;
    cout << endl;

    // sum(l to r) {(i+l-1)*a[i]} = ps[r]-ps[l-1] - (l-1)*(p[r] - p[l-1]) ;
    int q ; cin >> q ;
    while(q--)
    {
        int l , r ; cin >> l >> r ;
        // l-- ; r-- ; // convert to 0 based indexing 
        cout << ps[r] - ps[l-1] - (l-1)*(p[r]-p[l-1]) << endl ; 
    }
}