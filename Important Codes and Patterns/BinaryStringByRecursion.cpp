#include <bits/stdc++.h>
using namespace std;

string bins(int n)
{
    if(n==0 || n==1) return to_string(n) ;
    return bins(n/2)+to_string(n%2) ;
}

int main()
{
    cout << bins(21) << endl;
}
