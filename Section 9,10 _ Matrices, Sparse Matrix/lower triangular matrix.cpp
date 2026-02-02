#include <bits/stdc++.h>
using namespace std;

// lower triangular matrix looks like :
// 1  0  0  0  0
// 2  3  0  0  0
// 4  5  6  0  0 
// 7  8  9  10 0
// 11 12 13 14 15

// that is elements with i<j are 0 else non zero !!

// we can save this type of matrix in row-major form
// as A = 1 , 2,3 , 4,5,6 , 7,8,9,10 , 11,12,13,14,15 
// total 1+2+3+4+5 = (5)(5+1)/2 elements to be stored
// in general an array of size n(n+1)/2 is needed ;
// index formula is LT[i][j] = A[(i*(i-1)/2)+j-1] , for i>=j ;
// else we know that LT[i][j] = 0 for i<j ; 
class lowertriangular
{  
    int n ;
    int *A ; // for this we have to explicitly define default destructor to free up 
    // heap memory that we are going to assign to it !!
    public :
    lowertriangular(int n) : n{n} , A{new int[n*(n+1)/2]}
    {
        cout << "One arg constructor called" << endl;
        this->n = n ; // no need to write this statement because we have given constructor initializer list 
        // this->n is the class member n and the rvalue n is the local n of constructor
    }
    lowertriangular(int n , int* arr) : n{n} , A{new int[n*(n+1)/2]}
    {
        cout << "Two args constructor called" << endl;
        for(int i {0} ; i<n*(n+1)/2 ; i++) A[i]=arr[i] ;
    }
    ~lowertriangular()
    {
        cout << "destructor called" << endl;
        delete[] A ;
    }
    void set(int i , int j , int x)
    {
        if(i>=j) A[((i*(i-1)/2)+j-1)] = x ;
    }
    int get(int i , int j)
    {
        if(i>=j) return A[((i*(i-1)/2)+j-1)] ;
        return 0 ;

    }
    void display()
    {
        for(int i {0} ; i<n ; i++)
        {
            for(int j {0} ; j<n ; j++)
            {   
                if(i<j) cout << 0 << " " ;
                else cout << A[((i*(i+1)/2)+j)] << " " ;
            }
            cout << endl;
        }
    }
    friend ostream& operator<<(ostream& COUT,lowertriangular& ltri) // stream extraction operator overloaded as a friend function
    {
        COUT << "Size : " << ltri.n << endl;
        for(int i {0} ; i<ltri.n ; i++)
        {
            for(int j {0} ; j<ltri.n ; j++)
            {
                if(i<j) COUT << 0 << " " ;
                else COUT << ltri.A[((i*(i+1)/2)+j)] << " " ;
            }
            COUT << endl;
        }
        return COUT ;
    }
};

int main()
{
    // give indices in 1-based indexing
    lowertriangular ltri {5} ;
    for(int i {0} ; i<5 ; i++)
    {
        for(int j {0} ; j<5 ; j++)
        {
            ltri.set(i+1,j+1,i+j+1) ;
        }
    }
    ltri.display() ;
    cout << ltri ;
}