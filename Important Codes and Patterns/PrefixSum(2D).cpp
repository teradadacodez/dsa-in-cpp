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
    int T ; cin >> T ;
    while(T--) samsooong() ;
    auto stop = chrono::high_resolution_clock::now() ;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop-start) ;
    cerr << "Time elapsed : " << time.count() << " μs " << endl;
}
void samsooong()
{
    ll n , m ; cin >> n >> m ;
    vector<vector<ll>> matrix(n,vector<ll>(m)) , pfsmat(n,vector<ll>(m)) ;
    // pfsmat is the prefix sum grid of matrix . 
    // pfsmat[i][j] = pfsmat[i][j-1] + pfsmat[i-1][j] - pfsmat[i-1][j-1] + matrix[i][j] ;
    // this is the construction formula for the pfsmat !!
    for(auto &i : matrix) for(auto &j : i) cin >> j;
    for(int i {0} ; i<n ; i++)
    {
        for(int j {0} ; j<m ; j++)
        {
            // we have to write pfsmat[i][j] = pfsmat[i][j-1] + pfsmat[i-1][j] - pfsmat[i-1][j-1] + matrix[i][j] ;
            // but this will create an error when i=0 , j=0 (0 based indexing) 
            // so we write the conflicting terms with cases 
            // we break down the formula as 
            if(j>0) pfsmat[i][j] += pfsmat[i][j-1] ; //since j-1 is there
            if(i>0) pfsmat[i][j] += pfsmat[i-1][j] ; //since i-1 is there
            if(i>0 && j>0) pfsmat[i][j] -= pfsmat[i-1][j-1] ; // since i-1 and j-1 both are there
            pfsmat[i][j] += matrix[i][j] ; //since no problem for this so no case !
        }
    }
    for(auto i : pfsmat)
    {
        for(auto j : i)
        {
            cout << j << " " ;
        }
        cout << endl;
    }
    // now what if we have q queries and we have to tell the sum
    // of rectangle formed by [l1,r1] and [l2,r2] ? 
    // for this we follow the same process as we did in linear prefix sum 
    int q ; cin >> q ; 
    while(q--)
    {
        int l1 , r1 , l2 , r2 ;
        cin >> l1 >> r1 >> l2 >> r2 ;
        l1-- ; l2-- ; r1-- ; r2-- ; // to convert to 0 based indexing 
        ll ans {0} ; // ans = pfsmat[l2][r2] - pfsmat[l1-1][r2] - pfsmat[l2][r1-1] + pfsmat[l1-1][r1-1] ;
        // we are asked to calculate the sum inside the rectangle formed by the points
        // (l1,r1) , (l2,r1) , (l1,r2) , (l2,r2) ;
        // we do this case wise 
        ans += pfsmat[l2][r2] ;
        if(l1>0) ans -= pfsmat[l1-1][r2] ;
        if(r1>0) ans -= pfsmat[l2][r1-1] ;
        if(l1>0 && r1>0) ans += pfsmat[l1-1][r1-1] ;
        cout << ans << endl;
    }

}