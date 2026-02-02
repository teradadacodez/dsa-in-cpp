#include <bits/stdc++.h>
using namespace std;

// cyclic linked list 
// a head node is pointing on one of the node of a looped linked list
// from which we can access all nodes since all are in a loop !
// we are using the first represention in which the last node is pointing on the 
// first or head node 

class node
{
    public :
    int data ;
    node *next ;
}*head=nullptr ;

void create(int A[] , int n)
{
    node *t , *last ;
    head = new node ;
    head->data = A[0] ;
    head->next = head ;
    last = head ;
    for(int i {1} ; i<n ; i++)
    {
        t = new node ;
        t->data = A[i] ;
        t->next = last->next ;
        last->next = t ;
        last = t ;
    } 
}
// length of circular LL
int length(node *p)
{
    int k {0} ;
    while(p->next!=head)
    {
        p = p->next ;
        k++ ;
    }
    return k+1 ;
}
// to display we cannot use while loop with the condition while(p!=head) !!
// because this loop will not work since on first iteration p == head !
// so we use do while loop so that the next time p reaches head node it stops !
void display(node *p)
{
    do
    {
        cout << p->data << " " ;
        p = p->next ;   
    } while (p!=head);  
    cout << endl;
}
// recursive display funtion for cyclic LL
void recurdisplay(node *p)
{
    static int flag = 0 ;
    if(p!=head || flag == 0)
    {
        flag = 1 ;
        cout << p->data << " " ;
        recurdisplay(p->next) ;
    }
    flag = 0 ;
}
// inserting in a circular linked list !!
// insert before head 
// or insert after a position (pos)
void insert(int pos , int x , node *p)
{
    if(pos<0 || pos>length(head)) return ;
    if(pos!=0)
    {
        for(int i {0} ; i<pos-1 ; i++) p = p->next ;
        node *t = new node ;
        t->data = x ;
        t->next = p->next ;
        p->next = t ;
    }     
    else
    {
        node *t = new node ;
        while(p->next!=head) p = p->next ;
        p->next = t ;
        t->data = x ;
        t->next = head ;
        head = t ;
    }
}
// deleting from circular linked list !
int deletenode(int pos)
{
    node *p , *q ;
    int x {0} ;
    if(pos<0 || pos>length(head)) return INT_MIN ;
    if(pos!=0)
    {
        p = head ;
        for(int i {0} ; i<pos-2 ; i++) p = p->next ;
        q = p->next ;
        p->next = q->next ;
        x = q->data;
        delete q ;
    }
    else
    {
        p = head ;
        while(p->next != head) p = p->next ;
        p->next = head->next ;
        x = head->data ;
        delete head ;
        head = p->next ;
    }
}
int main()
{
    int a[] = {1,2,3,4,5} ;
    create(a,5) ;
    display(head) ;
    recurdisplay(head) ;
    cout << endl;
    insert(0,0,head) ;
    insert(6,6,head) ;
    display(head) ;
    deletenode(7) ;
    display(head) ;
}