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
    // gcd = hcf !!
    // gcd(a,b) = m , this means a%m = b%m = 0 , m is the greatest number which divides both a and b !
    // gcd(a,b) function has time complexity of O(log(max(a,b))) ;
    // if gcd(a,b) = m then gcd(a + m*b , b) = m !!
    // gcd(a,b,c) = __gcd(a,__gcd(b,c)) ;
    // gcd(a,b) <= min(a,b) ;
    // gcd(a,0) = a ; // works with most compilers !
    int n ; cin >> n ;
    vector<int> a(n) ;
    int gcd {0} ; 
    for(auto &i : a)
    {
        cin >> i ;
        gcd = __gcd(gcd,i) ;
    }
    cout << "gcd of array a : " << gcd << endl;

    // lcm(a,b)*gcd(a,b) = a*b ;
    // so lcm(a,b) = a*b/gcd(a,b) ;
    // same thing we can do to find the lcm of an array 
    // initialize the lcm variable to lcm of first and second element of the array !
    // then run the loop !!
    // PIGEONHOLE PRINCIPLE : if there are N containers and M items (N<M) , then 
    // there is atleast 1 container that contains more than one item after distributing
    // all items ! 

    // there is always a subarray of an array which has it's sum divisible by n 
    // proof by prefix sum !!
}