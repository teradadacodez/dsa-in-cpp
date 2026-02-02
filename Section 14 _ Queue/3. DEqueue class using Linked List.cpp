#include <bits/stdc++.h>
using namespace std;

// in a DEqueue (Double Ended queue) we can insert from both nodes front and rear but delete from only front as it's still a queue !! 
class node
{
    public :
    int data ;
    node *prev ;
    node *next ;
    node(int x, node *p = nullptr, node* n = nullptr) : data(x), prev(p), next(n) {cout << "node constructor called" << endl;}
    ~node() {cout << "node destructor called" << endl;}
} ;

class DEqueue // doubly ended queue ;
{
    node *front ;
    node *rear ;
    public :
    DEqueue() : front(nullptr), rear(nullptr) {cout << "DEqueue constructor called" << endl;}
    ~DEqueue()
    {
        while(front)
        {
            node *temp = front ;
            front = front->next ;
            delete temp ;
        }
        rear = nullptr ;
        cout << "DEqueue destructor called" << endl;
    }
    DEqueue(const DEqueue&) = delete ; // disabling copy constructor
    DEqueue& operator=(const DEqueue&) = delete ; // disabling assignment
    void rear_insert(int x)
    {
        node *t = new node(x,rear,nullptr) ;
        if(!rear) front = rear = t ;
        else
        {
            rear->next=t ;
            rear = t ;
        }
    }
    void front_insert(int x)
    {
        node *t = new node(x,nullptr,front) ;
        if(!front) front = rear = t ;
        else
        {
            front->prev=t ;
            front = t ;
        }
    }
    void display()
    {
        node *temp = front ;
        while(temp!=rear)
        {
            cout << temp->data << " " ;
            temp = temp->next ;
        }
        cout << endl;
    }
    int pop()
    {
        int x {INT_MIN} ;
        if(!front)
        {
            cout << "Queue is empty" << endl;
            return x ;
        }
        x = front->data ;
        node *t = front ;
        front = front->next ;
        if(front) front->prev = nullptr ;
        else rear = nullptr ;
        delete t ;
        return x ;
    }
    int head()
    {
        int x {INT_MIN} ;
        if(!front)
        {
            cout << "Queue is empty" << endl;
            return x ;
        }
        return front->data ;
    }
    // add peek if you want. it's easy af !
};

int main()
{
    DEqueue dq ;
    for(int i {0} ; i<5 ; i++) dq.rear_insert(i+1) ;
    cout << dq.head() << endl;
    for(int i {0} ; i<5 ; i++) dq.front_insert(i+6) ;
    cout << dq.head() << endl;
    dq.display() ;
    cout << "Popped out : " << dq.pop() << endl;
    dq.display() ;
}