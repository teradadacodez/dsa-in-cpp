#include <bits/stdc++.h>
using namespace std;

class element
{
    public : 
    int i ;
    int j ; 
    int x ;
};
class sparse 
{
    int m ;
    int n ;
    int num ;
    element* e ;
    public :
    sparse(int n , int m , int num)
    {
        cout << "Constructor called" << endl;
        this->n = n;
        this->m = m ;
        this->num = num ;
        e = new element[this->num] ;
    }
    sparse(const sparse& s) //this is copy constructor and is necessary to make while using pointers in class !!!!
    {
        cout << "Copy Constructor called" << endl;
        m = s.m ;
        n = s.n ;
        num = s.num ;
        e = new element[num] ; // here we make allocate new memory in heap and copy the data as it is !
        for(int i {0} ; i<num ; i++) e[i] = s.e[i] ;
    }
    ~sparse()
    {
        cout << "Destructor called" << endl;
        delete[] e ;
    }
    void create()
    {
        cout << "Enter i , j and value : " << endl;
        for(int k {0} ; k<num ; k++)
        {
            cin >> e[k].i >> e[k].j >> e[k].x ;
        }
    }
    void display()
    {
        cout << "Your Sparse Matrix is : " << endl;
        int k {0} ;
        for(int i {0} ; i<m ; i++)
        {
            for(int j {0} ; j<n ; j++)
            {
                if(i==e[k].i && j==e[k].j) cout << e[k++].x << " " ;
                else cout << 0 << " " ;
            }   
            cout << endl;
        }
    }
    friend sparse addspr(sparse s1 , sparse s2)
    {
        sparse res(s1.n, s1.m, s1.num + s2.num); // allocate sufficient space

        int i = 0, j = 0, k = 0;
        while (i < s1.num && j < s2.num)
        {
            if (s1.e[i].i < s2.e[j].i)
                res.e[k++] = s1.e[i++];
            else if (s1.e[i].i > s2.e[j].i)
                res.e[k++] = s2.e[j++];
            else
            {
                if (s1.e[i].j < s2.e[j].j)
                    res.e[k++] = s1.e[i++];
                else if (s1.e[i].j > s2.e[j].j)
                    res.e[k++] = s2.e[j++];
                else
                {
                    res.e[k] = s1.e[i++];
                    res.e[k++].x += s2.e[j++].x;
                }
            }
        }

        while (i < s1.num) res.e[k++] = s1.e[i++];
        while (j < s2.num) res.e[k++] = s2.e[j++];

        res.num = k;
        return res;
    }
};
// we can also over load >> , << , + operators !!
int main()
{
    sparse spr1(3,3,3) , spr2(3,3,3) ;
    spr1.create() ;
    spr2.create() ;
    spr1.display() ;
    spr2.display() ;
    sparse res = addspr(spr1,spr2) ;
    res.display() ;
}