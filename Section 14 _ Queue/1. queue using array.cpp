#include <bits/stdc++.h>
using namespace std;

// queue : works on FIFO (first in first out) priciple

// queue ADT wants
// 1. space for storing elements 
// 2. front pointer (for deletion)
// 3. rear pointer (for insertion)

// operations : enqueue(x), dequeue(), isempty(), isfull(), last(), first(), ...

// queue using array with two pointers!!!

// [NOTE] : using a single pointer insert takes O(1) time and delete takes O(n) time !!
//          but using two pointers both takes O(1) time !!


class myqueue
{
    public :
    int size ; 
    int front ; 
    int rear ;
    int *q ;
    myqueue(int n = 10) : size{n} , front {-1} , rear {-1}
    {
        cout << "constructor called" << endl;
        q = new int[size] ;
    }     
    ~myqueue()
    {
        cout << "destructor called" << endl;
        delete[] q ;
    }
};
void create(myqueue *q , int a[] , int n)
{
    for(int i {0} ; i<q->size ; i++) q->q[i] = a[i] ;
    q->rear = n-1 ;
}
void display(const myqueue *q)
{
    for(int i {q->front+1} ; i<=q->rear ; i++) cout << q->q[i] << " " ; cout << endl;
}
void enqueue(myqueue *q, int x)
{
    if(q->rear == q->size-1)
    {
        cout << "Queue if full !" << endl;
        return ;
    }
    q->rear++ ;
    q->q[q->rear] = x ;
}
int dequeue(myqueue *q)
{
    int x {INT_MIN} ;
    if(q->front==q->rear)
    {
        cout << "Queue is already empty, returning " << endl;
        return x;
    }
    q->front++ ;
    x = q->q[q->front] ;
    return x ;
}
int main()
{
    myqueue que ;
    for(int i {0} ; i<10 ; i++) enqueue(&que,i) ;
    display(&que) ;
    cout << que.front << " " << que.rear << endl;
    enqueue(&que,11) ;
    cout << dequeue(&que) << endl;
}
