#include <bits/stdc++.h>
using namespace std;

// DOUBLY LINKED LIST is a type of linked list in which each node except first and last node 
// has a link to it's previous and next node !!!
// first node has the link only to it's next node and the last node has the link only to it's previous node
class node
{
    public :
    node *prev ;
    int data ;
    node *next ;
}*first = nullptr ;

// creating a doubly linked list
void create(int a[] , int n)
{
    node *p , *last ;
    first = new node ;
    first->data = a[0] ;
    first->next = nullptr ;
    first->prev = nullptr ;
    last = first ;
    for(int i {1} ; i<n ; i++)
    {
        p = new node ;
        p->data = a[i] ;
        p->next = last->next ;
        p->prev = last ;
        last->next = p ;
        last = p ;
    }
}
// display
void display(node *p)
{
    while(p)
    {
        cout << p->data << " " ;
        p = p->next ;
    }
    cout << endl;
}
// length
int length(node *p)
{
    int k {0} ;
    while(p)
    {
        k++ ; p = p->next ;
    }
    return k ;
}
// insert in a doubly linked list 
void insert(int pos , int x , node *p)
{
    if(pos<0 || pos>length(p)) return ;
    node *t ;
    if(pos==0)
    {
        t = new node ;
        t->prev = nullptr ;
        t->data = x ;
        t->next = first ;
        first->prev = t ;
        first = t ;
    }
    else
    {
        for(int i {0} ; i<pos-1 ;i++) p = p->next ;
        t = new node ;
        t->data = x ;
        t->next = p->next ;
        t->prev = p ;
        if(p->next) p->next->prev = t ;
        p->next = t ;
    }
}
// deleting a node
int deletenode(int pos)
{
    node *p ;
    int x {0} ;
    if(pos<=0 || pos>length(first)) return INT_MIN ;
    if(pos==1)
    {
        p = first ;
        first = first->next ;
        x = p->data ;
        delete p ;
        if(first) first->prev = nullptr ;
    }
    else
    {
        p = first ;
        for(int i {0} ; i<pos-1 ; i++) p = p->next ;
        p->prev->next = p->next ;
        if(p->next) p->next->prev = p->prev ;
        x = p->data ;
        delete p ;
    }
    return x ; 
}
// reversing 
void reverse(node *p)
{
    node *t ;
    while(p)
    {
        t = p->next ;
        p->next = p->prev ;
        p->prev = t ;
        p = p->prev ;
        if((p!=nullptr) && (p->next==nullptr)) first = p ; 
    }
}
int main()
{
    int a[] = {1,2,3,4,5} ;
    create(a,5) ;
    cout << length(first) << endl;
    display(first) ;
    insert(0,0,first) ;
    insert(3,10,first) ;
    insert(7,6,first) ;
    display(first) ;
    cout << deletenode(4) << endl;
    display(first) ;
    cout << deletenode(1) << endl;
    display(first) ;
    reverse(first) ;
    display(first) ;
}   
