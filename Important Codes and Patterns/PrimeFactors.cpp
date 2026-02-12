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
    // this code is to get PRIME FACTORS of a number !!
    // this method is called TRIAL DIVISION method !!
    int n ; cin >> n ;
    vector<int> primefact(1,1) ;
    // since 1 is always a prime factor so we already have 1 in primefact
    for(int i {2} ; i*i <= n ; i++)
    {
        if(n%i == 0) 
        {
            while(n%i == 0) n/=i ; // here we removed all i's from n because
            // the number which would be formed by i (as a prime factor) further
            // will never form, like if we remove all 2's then we don't need to 
            // take care of 4 or 6 or 8 or ... further !!
            primefact.push_back(i) ;
        }
    }
    if(n>1) primefact.push_back(n) ;
    cout << "No. of Prime factors of " << n << " are : " << primefact.size() << endl;
    for(auto i : primefact) cout << i << " " ; cout << endl;
}