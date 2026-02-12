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
    for(int i {0} ; i<N ; i++) spf[i] = i ;
    for(int i {2} ; i*i<N ; i++)
    {
        if(spf[i] == i)
        {
            for(int j {i*i} ; j<N ; j+=i)
            {
                if(spf[j] == j) spf[j] = i ;
            }
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
    string x , y ; cin >> x >> y ;
    sort(x.begin(),x.end()) ;
    sort(y.begin(),y.end()) ;
    set<int> dx , dy ; // all prime factors of digit spaces of x and y ;
    do
    {
        if(x[0] == '0') continue;
        else
        {
            int num {stoi(x)} ;
            while(num>1)
            {
                dx.insert(spf[num]) ;
                num/=spf[num] ;
            }
        }
    }while(next_permutation(x.begin(),x.end()));
    do
    {
        if(y[0] == '0') continue;
        else
        {
            int num {stoi(y)} ;
            while(num>1)
            {
                dy.insert(spf[num]) ;
                num/=spf[num] ;
            }
        }
    }while(next_permutation(y.begin(),y.end()));
    int ans {1} ;
    for(auto i : dx)
    {
        if(dy.find(i)!=dy.end()) ans = max(ans,i) ;
    }  
    cout << ans << endl;


}