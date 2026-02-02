#include <bits/stdc++.h>
using namespace std;

// toeplitz matrix looks like :
// 1 2 3 4 5
// 6 1 2 3 4
// 7 6 1 2 3
// 8 7 6 1 2
// 9 8 7 6 1
// that is elements on same diagnal are same !!
// i.e. elements with same i-j value are same !!
// the i-j values are from n-1 to 1-n 
// if n=5 then i-j are from 4 to -4 !!
// we can save this type of matrix with only first row and the first column
// size of the array needed is 2n-1 !! since the first element is common in both 
// so we have to remove it 
// index formula we can use is TPL[i][j] = A[i-j+n-1] ;
// formed array A is :
// A = 9,8,7,6,1,2,3,4,5
class toeplitz
{  
    int n ;
    int *A ; // for this we have to explicitly define default destructor to free up 
    // heap memory that we are going to assign to it !!
    public :
    toeplitz(int n) : n{n} , A{new int[2*n-1]}
    {
        cout << "One arg constructor called" << endl;
        this->n = n ; // no need to write this statement because we have given constructor initializer list 
        // this->n is the class member n and the rvalue n is the local n of constructor
    }
    toeplitz(int n , int* arr) : n{n} , A{new int[2*n-1]}
    {
        cout << "Two args constructor called" << endl;
        for(int i {0} ; i<2*n-1 ; i++) A[i]=arr[i] ;
    }
    ~toeplitz()
    {
        cout << "destructor called" << endl;
        delete[] A ;
    }
    void set(int i , int j , int x)
    {
        A[i-j+n-1] = x ;
    }
    int get(int i , int j)
    {
        return A[i-j+n-1] ;
    }
    void display()
    {
        for(int i {1} ; i<=n ; i++)
        {
            for(int j {1} ; j<=n ; j++)
            {   
                cout << A[i-j+n-1] << " " ;
            }
            cout << endl;
        }
    }
    friend ostream& operator<<(ostream& COUT,toeplitz& tpl) // stream extraction operator overloaded as a friend function
    {
        COUT << "Size : " << tpl.n << endl;
        for(int i {1} ; i<=tpl.n ; i++)
        {
            for(int j {1} ; j<=tpl.n ; j++)
            {
                COUT << tpl.A[i-j+tpl.n-1] << " " ;
            }
            COUT << endl;
        }
        return COUT ;
    }
};

int main()
{
    // give indices in 1-based indexing
    toeplitz tpl {5} ;
    for(int i {0} ; i<5 ; i++)
    {
        for(int j {0} ; j<5 ; j++)
        {
            tpl.set(i+1,j+1,i+j*j) ;
        }
    }
    tpl.display() ;
    cout << tpl ;
}

