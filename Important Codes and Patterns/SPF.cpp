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

const int N = 1e7 ;
int spf[N] ;

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
    for(int i {0} ; i<N ; i++) spf[i] = i ; // we will mark all numbers are prime and therefore they are their spf !
    for(int i {2} ; i*i<N ; i++)
    {
        if(spf[i]==i) // this condition is checking that if i is spf i.e. they are considering itself as prime
        {
            for(int j {i*i} ; j<N ; j+=i)
            {
                if(spf[j] == j) spf[j] = i ;
            }                
        }
    }
    // tc : O(n*log(log(n))) 
    int T ; cin >> T ;
    while(T--) samsooong() ;
    auto stop = chrono::high_resolution_clock::now() ;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop-start) ;
    cerr << "Time elapsed : " << time.count() << " μs " << endl;
}
void samsooong()
{
    // here we calculate SPF(Smallest Prime Factor) of a number.
    int n ; cin >> n ;
    for(int i {0} ; i<n ; i++) cout << spf[i] << " " ; cout << endl;
    // we can use spf to find prime factorization of n !
    cout << "Prime Factorization of " << n << " is : " ;
    while(n>1)
    {
        cout << spf[n] << " " ;
        n/=spf[n] ;
    }
    cout << endl;

}