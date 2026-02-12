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
// Q. there is an array containing N elements . determine whether there 
// exists a non empty subarray such than sum of elements in the subarray in divisible by N ?
void samsooong()
{
    // ans. Yes always possible in O(n) !
    int n , k ; cin >> n >> k ;
    vector<int> a(n) ;
    for(auto &i : a) cin >> i ;
    vector<int> pf(n+1) ;
    pf[0]=a[0] ;
    pf[0]%=n ;
    map<int,int> m ;
    for(int i {1} ; i<n ; i++)
    {
        pf[i]=pf[i-1]+a[i] ;
        pf[i]%=n ;
        m[pf[i]]++ ;
    }
    // if any prefix sum is repeating then it is understood that 
    // in between there is a subarray which has the sum divisible 
    // by n ! 
    // or if the prefix sum is not repeating we will have prefixsum
    // array as all the numbers from 0 to n-1 , and where the zero is occuring 
    // it's our answer !
    
}