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
    // the array has to be sorted first !!!
    int n ; cin >> n ;
    vector<int> arr(n) ;
    for(auto &i : arr) cin >> i ;
    if(is_sorted(arr.begin(),arr.end()))
    {
        int diff = arr[0]-0 ; // diff a[i] - i will be constant for an A.P.
        for(int i {0} ; i<n ; i++)
        {
            if(arr[i] - i != diff)
            {
                while(diff<(arr[i]-i))
                {
                    cout << i+diff << " " ;
                    diff++ ;
                }
            }
        }
        cout << endl;
        return ;
    }

    // method 2 : HASHING (it is a technique in which the element is the index of another container)
    // used in unsorted array mainly !!
    // we need to know firstly the maximun element of the array 
    // becuase that will make the size of the hash table !
    // aka bitset 
    // one con of hashing is that  we need a lot of space for large arrays 
    // if mx is very large due to compiler and machine limitations we cannot 
    // make that much big array !!
    int mx {0} ;
    for(auto i : arr) mx=max(i,mx) ;
    int H[mx] {0} ;
    for(auto i : arr) H[i]++ ;
    cout << "Missing Elems are : " << endl;
    for(int i {1} ; i<mx ; i++) if(H[i]==0) cout << i << " " ; cout << endl;
}