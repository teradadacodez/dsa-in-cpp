#include <bits/stdc++.h>
using namespace std;

class diagonal
{  
    int n ;
    int *A ; // for this we have to explicitly define default destructor to free up 
    // heap memory that we are going to assign to it !!
    public :
    diagonal(int n) : n{n} , A{new int[n]}
    {
        cout << "One arg constructor called" << endl;
        this->n = n ;
        // this->n is the class member n and the rvalue n is the local n of constructor
    }
    diagonal(int n , int* arr) : n{n} , A{new int[n]}
    {
        cout << "Two args constructor called" << endl;
        for(int i {0} ; i<n ; i++) A[i]=arr[i] ;
    }
    ~diagonal()
    {
        cout << "destructor called" << endl;
        delete[] A ;
    }
    void set(int i , int j , int x)
    {
        if(i==j) A[i-1] = x ;
    }
    int get(int i , int j)
    {
        if(i==j) return A[i-1] ;
        return 0 ;

    }
    void display()
    {
        for(int i {0} ; i<n ; i++)
        {
            for(int j {0} ; j<n ; j++)
            {
                cout << ((i==j)?A[i]:0) << " " ;
            }
            cout << endl;
        }
    }
    friend ostream& operator<<(ostream& COUT,diagonal& diag) // stream extraction operator overloaded as a friend function
    {
        COUT << "Size : " << diag.n << endl;
        for(int i {0} ; i<diag.n ; i++)
        {
            for(int j {0} ; j<diag.n ; j++)
            {
                if(i==j) COUT << diag.A[i] << " " ;
                else COUT << 0 << " " ;
            }
            COUT << endl;
        }
        return COUT ;
    }
};

int main()
{
    diagonal diag {5} ;
    for(int i {0} ; i<5 ; i++) diag.set(i+1,i+1,i+1) ;
    diag.display() ;
    cout << diag ;
}