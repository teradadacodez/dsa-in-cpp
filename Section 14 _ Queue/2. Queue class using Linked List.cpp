#include <bits/stdc++.h>
using namespace std;

class node
{
    public :
    int data ;
    node *next ;
    node(int x) : data(x), next(nullptr) {cout << "node constructor called" << endl;} 
} ;

class Queue
{
    node *front ;
    node *rear ;
    public : 
    // here we are managing memory manually then we must follow Rule of Five (RoF) in OOPs !!!
    // RoF states that : IF WE ARE MANAGING MEMORY MANUALLY THEN WE MUST EXPLICITLY DEFINE
    // 1. COPY CONSTRUCTOR
    // 2. ASSIGNMENT OPERATOR
    // 3. MOVE CONSTRUCTOR (not in this code)
    // 4. MOVE ASSIGNMENT (not is this code)
    // 5. DESTRUCTOR
    // following the principle of RAII ("Resource Aquisition Is Initialization")
    Queue() : front(nullptr), rear(nullptr) {cout << "Queue constructor called" << endl;}
    ~Queue()
    {
        node *temp {nullptr} ;
        while(front)
        {
            temp = front ;
            front = front->next ;
            delete temp ;
        }
        rear = nullptr ;
        cout << "Queue destructor called" << endl;
    }
    Queue(const Queue&) = delete ; // disabling copy constructor
    Queue& operator=(const Queue&) = delete ; // disabling assignment
    void enqueue(int x)
    {
        node *t = new node(x) ;
        if(!rear) front = rear = t ;
        else
        {
            rear->next=t ;
            rear = t ;
        }
    }
    int dequeue()
    {
        if(!front)
        {
            rear = nullptr ;
            cout << "Queue is empty" << endl;
            return INT_MIN ;
        }
        int x = front->data ;
        node *temp = front ;
        front = front->next ;
        if(!front) rear=nullptr ;
        delete temp ;
        return x ;
    }
    int head() const
    {
        if(!front)
        {
            cout << "Queue is empty" << endl;
            return INT_MIN ;
        }
        return front->data ;
    }
    void display() const
    {
        for(node *temp = front ; temp ; temp = temp->next) cout << temp->data << " " ; cout << endl;
    }
};

int main()
{
    Queue q ;
    for(int i {0} ; i<10 ; i++) q.enqueue(i+1) ;
    q.display() ;
    cout << q.head() << endl;
    cout << "Dequeued item is : " << q.dequeue() << endl;
    cout << "Dequeued item is : " << q.dequeue() << endl;
    cout << "Dequeued item is : " << q.dequeue() << endl;
    cout << "Dequeued item is : " << q.dequeue() << endl;
    cout << q.head() << endl;
}