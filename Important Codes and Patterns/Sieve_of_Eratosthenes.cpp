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

// basically what we do in sieve is we firstly mark all numbers as prime in the boolean array
// then we iterate through every number and mark their multiples as non prime .
// after this rigorous process we are only left with prime number unmarked !! 

const int N = 1e7 ;
bool sieve[N] ;

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
    // here we have done two optimizations, 
    // 1. for marking a number N as non prime in sieve we will not iterate to N
    // but we will see the smallest Prime factor of N and will iterate upto it only,
    // because it's multiple would somehow be processed while iterating !
    // but here is the catch that we would not actually calculate the smallest prime factor
    // for each number but we will iterate upto sqrt(i) because all the factors would somehow get the number i 
    // as there multiple !

    // 2. we will start marking the multiples of i as non prime starting with i*i 
    // because the numbers between i*i and i would have been already marked as 
    // non prime when the multiples of 2 to i-1 were being processed !! 
    for(int i {0} ; i<N ; i++) sieve[i] = 1 ;
    sieve[0] = sieve[1] = 0 ;
    for(int i {2} ; i*i<=N ; i++)
    {
        if(sieve[i] == 1)
        {
            for(int j {i*i} ; j<N ; j+=i) sieve[j] = 0 ; 
        }
    }
    int T ; cin >> T ;
    while(T--) samsooong() ;
    auto stop = chrono::high_resolution_clock::now() ;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop-start) ;
    cerr << "Time elapsed : " << time.count() << " μs " << endl;
}
void samsooong()
{
    // Seive of Eratosthenes
    // One of the most efficient ways to find all Prime numbers upto a given n !
    // We can easily Precompute all Primes <= 1e9 !

    int n ; cin >> n ;
    ll ans {0} ;
    for(int i {2} ; i<=n ; i++) if(sieve[i] == 1) ans++ ;
    cout << ans << endl;
    // tc : O(n*log(log(n))) ;

}