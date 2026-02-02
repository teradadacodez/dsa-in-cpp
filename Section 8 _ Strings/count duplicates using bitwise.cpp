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
    samsooong() ;
    auto stop = chrono::high_resolution_clock::now() ;
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(stop-start) ;
    cerr << "Time elapsed : " << time.count() << " μs " << endl;
}
void samsooong()
{
    string s ; 
    getline(cin,s) ;
    for(auto &i : s) tolower(i) ; 
    // we take only a single interger and check the duplicates in it !!
    // all letters must be in lower case !!
    int x {0} ;
    // first of all we know that there can be 26 distinct characters 
    // so for checking we can take 26 bits but we dont have 26 bit datatype
    // so we take 32 bit datatype i.e. int !!

    // we will add the 1<<(s[i]-97) to x for every index and check whether 
    // at each step whether that bit was already high or not !! 

    for(int i {0} ; i<s.size() ; i++)
    {
        if(s[i]<97||s[i]>122) continue ;
        int y {1<<(s[i]-97)} ;
        if(x&y) cout << s[i] << " is duplicate" << endl;
        else x|=y ;
    }
    // to count frequencies hashing is always the best option !!
}