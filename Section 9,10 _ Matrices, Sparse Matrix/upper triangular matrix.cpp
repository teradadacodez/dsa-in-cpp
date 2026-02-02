#include <bits/stdc++.h>
using namespace std;

// upper triangular matrix looks like :
// 1  2  3  4  5
// 0  6  7  8  9
// 0  0  10 11 12
// 0  0  0  13 14
// 0  0  0  0  15

// that is elements with i>j are 0 else non zero !!

// we can save this type of matrix in row-major form
// as A = 1,2,3,4,5 , 6,7,8,9 , 10,11,12 , 13,14 , 15 ; 
// total 5+4+3+2+1 = (5)(5+1)/2 elements to be stored
// in general an array of size n(n+1)/2 is needed ;
// index formula is UT[i][j] = A[((i-1)(2(n+1)-i))+j-i] , for i<=j ;
// else we know that UT[i][j] = 0 for i>j ; 
class uppertriangular
{  
    int n ;
    int *A ; // for this we have to explicitly define default destructor to free up 
    // heap memory that we are going to assign to it !!
    public :
    uppertriangular(int n) : n{n} , A{new int[n*(n+1)/2]}
    {
        cout << "One arg constructor called" << endl;
        this->n = n ; // no need to write this statement because we have given constructor initializer list 
        // this->n is the class member n and the rvalue n is the local n of constructor
    }
    uppertriangular(int n , int* arr) : n{n} , A{new int[n*(n+1)/2]}
    {
        cout << "Two args constructor called" << endl;
        for(int i {0} ; i<n*(n+1)/2 ; i++) A[i]=arr[i] ;
    }
    ~uppertriangular()
    {
        cout << "destructor called" << endl;
        delete[] A ;
    }
    void set(int i , int j , int x)
    {
        if(i<=j) 
        {
            cout << "Setted A[" << n*(i-1) - ((i-1)*(i-2)/2) + j-i << "] = " << x << endl;
            A[n*(i-1) - ((i-1)*(i-2)/2) + j-i] = x ;
        }
    }
    int get(int i , int j)
    {
        if(i<=j) return A[n*(i-1) - ((i-1)*(i-2)/2) + j-i] ;
        return 0 ;
    }
    void display()
    {
        for(int i {1} ; i<=n ; i++)
        {
            for(int j {1} ; j<=n ; j++)
            {   
                if(i>j) cout << 0 << " " ;
                else cout << A[n*(i-1) - ((i-1)*(i-2)/2) + j-i] << " " ;
            }
            cout << endl;
        }
    }
    friend ostream& operator<<(ostream& COUT,uppertriangular& utri) // stream extraction operator overloaded as a friend function
    {
        COUT << "Size : " << utri.n << endl;
        for(int i {1} ; i<=utri.n ; i++)
        {
            for(int j {1} ; j<=utri.n ; j++)
            {
                if(i>j) COUT << 0 << " " ;
                else COUT << utri.A[utri.n*(i-1) - ((i-1)*(i-2)/2) + j-i] << " " ;
            }
            COUT << endl;
        }
        return COUT ;
    }
};

int main()
{
    // give indices in 1-based indexing
    uppertriangular utri {5} ;
    for(int i {0} ; i<5 ; i++)
    {
        for(int j {0} ; j<5 ; j++)
        {
            utri.set(i+1,j+1,i+j+1) ;
        }
    }
    utri.display() ;
    cout << utri ;
}

// NOTE : 
// row-major form of upper traingular is equivalent to 
// column-major form of lower triangular matrix !!!!
