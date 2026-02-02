#include <bits/stdc++.h>
using namespace std;

// tower of hanoi 
// rules are no larges disk can be places over a smaller disk 
// and only one disk at a time !!

void towerofhanoi(int n , int a , int b , int c)
{
    if(n>0)
    {
        towerofhanoi(n-1,a,c,b) ;
        cout << "(" << a << "," << c << ")," ;
        towerofhanoi(n-1,b,a,c) ;
    }
}
int toh(int n , int a , int b , int c)
{
    static int moves {0} ; // or declare globally
    if(n>0)
    {
        toh(n-1,a,c,b) ;
        moves++ ;
        toh(n-1,c,b,a) ;
    }
    return moves ;
}
int main()
{
    towerofhanoi(8,1,2,3) ;
    cout << "total moves are : " << toh(8,1,2,3) << endl;
}