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

ll helper(ll a , ll b) 
{
    if(b==0) return 1 ;
    ll temp {helper(a,b/2)} ;
    temp*=temp ;
    temp%=INF ;
    if(b&1)
    {
        temp *= a ;
        temp %= INF ;
    }
    return temp ;
}
// there can be another helper function 

ll helper2(ll a , ll b)
{
    ll res {1} ;
    while(b>0)
    {
        if(b&1)
        {
            res*=a ;
            res%=INF ;
        }
        a*=a ;
        a%=INF ;
        b>>=1 ;
    }
    return res ;
}

// we found out a^b % mod(INF) !!

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
    // Modular Operations 
    // (A+B)%mod = ((A%mod)+(B%mod))%mod ;
    // (A-B)%mod = ((A%mod)-(B%mod)+mod)%mod ;
    // (A*B)%mod = ((A%mod)*(B%mod))%mod ;
    // (A/B)%mod = ((A%mod)*(B^(-1)%mod))%mod ;
    // now to calculate (B^(-1)%mod))
    // we use fermat's little principle : 
    // it states that that if p is a prime number
    // then for any integer a , the number a^p - a
    // is an integer multiple of p.
    // it has a special case that if a is not divisible by p 
    // the a^(p-1) is an integer multiple of p.
    // so a^(p-1)%p is equal to a^(-1)%p 
    // so (B^(-1)%mod)) = (B^(MOD-1))%MOD !!

    // BINARY EXPONENTIATION : 
    // we calculate a^b in time O(log b) instead of O(b) !

    ll a , b ; cin >> a >> b ;
    cout << helper(a,b) << endl;
    cout << helper2(a,b) << endl;
    
}