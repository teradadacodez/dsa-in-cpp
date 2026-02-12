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
    // bitsets : it is an array of bools where each boolean value 
    // takes only a single bit to get stored 
    // size of the bitset must be known at the compile time !!
    // it is different from vector<bool> in the sense of runtime and
    // space occupied .
    // SPACE : bitset<40> {n/8 bytes} < vector<bool> b(40) {n/8 bytes and some metadata} < bool arr[40] {n bytes and some metadata}
    // RUNTIME : bitset > bool arr[] > vector<bool> arr()
    

    // here are three ways to declare bitsets 
    // general method : bitset<size> name(argument) ;

    bitset<10> a ; // uninitialized = all zeros 
    bitset<10> b(100) ; // decimal initialization
    bitset<10> c("1110010") ; // string initialization
    cout << a << " " << b << " " << c << endl;
    // now suppose we declare two bitsets and we need to find set bits in both 

    bitset<10> d(b&c) ; // all bitwise operations are aplicable on this 
    // understand it like this : we have 
    cout << d << endl;
    // to count no. of set bits in d we have a function to do this 
    cout << d.count() << endl;
    // there are some other functions as well 
    // these will return 
    // 1. whether all bits are high or not 
    // 2. whether none of the bits are high or not 
    // 3. whether any one of the bit is high or not 
    cout << d.all() << " " << d.none() << " " << d.any() << endl;
}