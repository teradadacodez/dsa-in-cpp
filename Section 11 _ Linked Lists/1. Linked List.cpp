#include <bits/stdc++.h>
using namespace std;

class node
{
    public :
    int data ;
    node *next ; // self referential structure/class
    node()
    {
        next = nullptr ;
    }
}; // we can do [ }*first = nullptr ; ] also but below is the more cleaner version !

// diagram of the class 
/*   
     node 1             node 2
|------|------|    |------|------|
| DATA | LINK |--->| DATA | LINK |--->continues
|------|------|    |------|------|

link of node i containes address of node i+1 ;
*/
node *first = nullptr ;
node *last = nullptr ;
node *second = nullptr ;
node *third = nullptr ;

void create1(int A[] , int n)
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
        last->next = t ; // last->next will store the address of the next full node object
        // in the 'next' member attribute of previous node object !!
        last = t ; // and then 'last' itself will update to t since t is the last node !!
    }
}
void create2(int A[] , int n)
{
    node *t , *last ;
    second = new node ;
    second->data = A[0] ;
    second->next = nullptr ;
    last = second ;

    for(int i {1} ; i<n ; i++)
    {
        t = new node ;
        t->data = A[i] ;
        t->next = nullptr ;
        last->next = t ; // last->next will store the address of the next full node object
        // in the 'next' member attribute of previous node object !!
        last = t ; // and then 'last' itself will update to t since t is the last node !!
    }
}
// to display the linked list
void display(node *p)
{
    while(p!=nullptr)
    {
        cout << p->data << " " ;
        p=p->next ;
    }
    cout << endl;
}
// recursive function to display linked list 
void displayreccur(node *p)
{
    if(p!=nullptr)
    {
        cout << p->data << " " ;
        displayreccur(p->next) ;
    }
}
// count no. of nodes
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
// to calculate sum of linked list elements
long long sum(node *p)
{
    long long s {0} ;
    while(p!=nullptr)
    {
        s+=p->data ;
        p=p->next ;
    }
    return s ;
}
// to find max element
int maxLL(node *p)
{
    int mx {INT_MIN} ;
    while(p!=nullptr)
    {
        mx=max(mx,p->data) ;
        p=p->next ;
    }
    return mx ;
}
// linear search in LL 
node* search(node *p , int x)
{
    while(p!=nullptr&&x!=p->data) p = p->next ;
    return p ;
}
// there can be two cases for insertion 
// 1. Insert before the first node 
// 2. Insert just after any given location 
void insert(int pos , int x)
{
    node *t , *p ;
    if(pos==0)
    {
        t = new node ;
        t->data=x ;
        t->next=first ;
        first = t ;
    }
    else
    {
        p = first ;
        for(int i {0} ; i<pos-1 && p!=nullptr ; i++) p = p->next ; 
        if(p!=nullptr)
        {
            t = new node ;
            t->data=x ;
            t->next=p->next ;
            p->next=t ;
        }
    }
}
// to insert element always at last 
void insertlast(int x)
{
    node *t = new node ;
    t->data=x ;
    t->next=nullptr ;
    if(first==nullptr) first = last = t ;
    else
    {
        last->next=t ;
        last = t ;
    }
}
// to insert elements at sorted position such that final LL is sorted
void sortedinsert(node *p , int x)
{
    node *t,*q = nullptr ;
    t = new node ;
    t->data=x ; 
    t->next=nullptr ;
    if(first == nullptr) first = t ;
    else
    {
        while(p && p->data < x)
        {
            q = p ;
            p=p->next ;
        }
        if(p==first)
        {
            t->next=first ;
            first = t ;
        }
        else
        {
            t->next=q->next ;
            q->next=t ;
        }
    }
}
// to delete a node 
int deletenode(node *p, int pos)
{
    if(pos<1 || pos>countnodes(p)) return INT_MIN ;
    node *q = nullptr ;
    int x {INT_MIN} ;
    if(pos == 1)
    {
        q = first ;
        x = first->data ;
        first = first->next ;
        if(!first) last = nullptr ;
        delete q ;
    }
    else
    {
        for(int i {0} ; i<pos-1 ; i++)
        {
            q = p ; p = p->next ;
        }
        q->next=p->next ;
        x=p->data ;
        if(!q->next) last = q ;
        delete p ;
    }
    return x ;
}
// to check if LL is sorted ?
bool issorted(node *p)
{
    int x {INT_MIN} ;
    while(p)
    {
        if(p->data<x) return false ;
        x = p->data ;
        p = p->next ;
    }
    return true ;
}
// to remove the duplicates elements from a sorted LL
void removeduplicatesinsorted(node *p) // LL must be sorted !
{
    node *q {p->next} ;
    while(q)
    {
        if(p->data!=q->data)
        {
            p = q ;
            q = q->next ;
        }
        else
        {
            p->next = q->next ;
            delete q ;
            q = p->next ;
        }
    }
}
// reversing liked list with two methods
// 1. Reversing elements (order of the link is unchanged but the values of each node is changed) 
// 2. Reversing links (value of a node is unchanged but the link order is reversed) {more preffered 
//    because in our case we have a linked list of just one integer but what if we have more no. of 
//    attributes like for a student roll no , branch , ph.no etc.} we wont copy all that data, instead we
//    reverse the link !!!
void reversing1(node *p)
{
    int *A = new int[countnodes(p)] ;
    int i {0} ;
    while(p)
    {
        A[i++] = p->data ;
        p = p->next ;
    }
    p = first ; i-- ;
    while(p)
    {
        p->data = A[i--] ;
        p = p->next ;
    }
    delete[] A ;
}
void reversing2(node *p)
{
    node *q {nullptr} , *r {nullptr} ;
    while(p)
    {
        r = q ;
        q = p ;
        p = p->next ;
        q->next = r ;
    }
    first = q ;
}
void reversing3(node* q , node *p) // using recussion
{
    if(p)
    {
        reversing3(p,p->next) ;
        p->next=q ;
    }
    else first = q ;
}
// merging two sorted linked list we require two more pointer (say third and last (helper pointer)) !
// we donot require extra space for it only two pointers are required ! 
void merge(node *p , node *q)
{
    node *last = nullptr ;
    if(p->data<q->data)
    {
        third=last=p ;
        p = p->next ;
        third->next = nullptr ;
    }
    else
    {
        third=last=q ;
        q=q->next ;
        third->next=nullptr ;
    }
    while(p&&q)
    {
        if(p->data<q->data)
        {
            last->next=p ;
            last = p ;
            p= p->next ;
            last->next = nullptr ;
        }
        else
        {
            last->next=q ;
            last = q ;
            q= q->next ;
            last->next = nullptr ;
        }
    }
    if(p) last->next=p ;
    if(q) last->next=q ;
}
// to concatenate i.e. to point the last node of one LL to first node of second LL !
void concat(node *p , node *q)
{
    third = p ;
    while(p->next) p = p->next ;
    p->next=q ;
}
// loopcheck in linked list.
// consider a linear race track, with two cars with top speed 100 and 200 kmph, 
// once they start they will never meet each other again since the track is linear.
// but if track if circular they will surely meet at some point !!
// same concept is applied here
// we start with two pointers, once moves by one step and another moves by two steps !
bool isloop(node *f)
{
    node *p = nullptr ;
    node *q = nullptr ;
    p = q = f ;
    do
    {
        p = p->next ;
        q = q->next ;
        q = (q) ? q->next : q ;
    }
    while(p&&q and p!=q) ;
    return (p==q) ? true : false ;
}
signed main()
{
    int A[] = {10,20,30,40,50} ;
    create1(A,5) ;
    node *t1 = first->next->next ;
    node *t2 = first->next->next->next->next ;
    t2->next=t1 ;
    cout << boolalpha << isloop(first) << endl;
}