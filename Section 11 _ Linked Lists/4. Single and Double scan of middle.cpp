#include <bits/stdc++.h>
using namespace std;

class node
{
    public :
    int data ;
    node *next ; 
    node()
    {
        next = nullptr ;
    }
}; 


node *first = nullptr ;
node *last = nullptr ;

void create(int A[] , int n)
{
    node *t , *last ;
    first = new node ;
    first->data = A[0] ;
    first->next = nullptr ;
    last = first ;

    for(int i {1} ; i<n ; i++)
    {
        t = new node ;
        t->data = A[i] ;
        t->next = nullptr ;
        last->next = t ; 
        last = t ;
    }
}
void display(node *p)
{
    while(p!=nullptr)
    {
        cout << p->data << " " ;
        p=p->next ;
    }
    cout << endl;
}
int countnodes(node *p)
{
    int c {0} ;
    while(p!=nullptr)
    {
        c++ ;
        p=p->next ;
    }
    return c ;
}
int double_scan_middle(node *p)
{
    int k {countnodes(p)} ; // first scan !
    for(int i {0} ; i<(k/2)-1 ; i++) p = p->next ; // second scan !!
    return p->data ;
}
int single_scal_middle(node *p)
{
    node *q = p ;
    while(q)
    {
        q = q->next ;
        if(q) q = q->next ;
        if(q) p = p->next ;
    } // only one scan of q !!
    return p->data ;
}

int main()
{
    int a[] = {1,2,3,4,5,6} ;
    create(a,6); 
    display(first) ;
    cout << double_scan_middle(first) << endl;
    cout << single_scal_middle(first) << endl;
}