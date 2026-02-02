#include <bits/stdc++.h>
using namespace std;

class node
{
    public :
    int data ;
    node *next ;
    node(int x, node *n = nullptr) : data(x), next(n) {cout << "node constructor called" << endl;}
    ~node() {cout << "node destructor called" << endl;}
} ;

class Stack
{
    node *top ;
    public :
    // here we are managing memory manually then we must follow Rule of Five (RoF) in OOPs !!!
    // RoF states that : IF WE ARE MANAGING MEMORY MANUALLY THEN WE MUST EXPLICITLY DEFINE
    // 1. COPY CONSTRUCTOR
    // 2. ASSIGNMENT OPERATOR
    // 3. MOVE CONSTRUCTOR (not in this code)
    // 4. MOVE ASSIGNMENT (not in this code)
    // 5. DESTRUCTOR
    // following the principle of RAII ("Resource Aquisition Is Initialization")
    Stack() : top(nullptr) {cout << "Stack constructor called" << endl;}
    ~Stack()
    {
        node *temp {nullptr} ;
        while(top)
        {
            temp = top ;
            top = top->next ;
            delete temp ;
        }
        cout << "Stack destructor called" << endl;
    }
    Stack(const Stack&) = delete ; // disabling copy constructor
    Stack& operator=(const Stack&) = delete ; // disabling assignment
    void push(int x)
    {
        top = new node(x,top) ;
    }
    int pop()
    {
        node *p = top ;
        if(top == nullptr)
        {
            cerr << "Stack Underflow" << endl;
            return INT_MIN ;
        }
        int x = top->data ;
        top = top->next ;
        delete p ;
        return x ;
    }
    int length()
    {
        int k {0} ;
        node *t = top ;
        while(t)
        {
            k++ ; t=t->next ;
        }
        return k ;
    }
    int peek(int pos)
    {
        node *t = top ;
        int x {INT_MIN} ;
        if(pos<1||pos>length())
        {
            cout << "invalid index" << endl;
            return x; 
        }
        for(int i {0} ; i<pos-1 ; i++) t = t->next ;
        return t->data ;
    }
    int head()
    {
        if(!top)
        {
            cerr << "Stack Underflow" << endl;
            return INT_MIN ;
        }
        return top->data ;
    }
    void display()
    {
        node *t = top ;
        while(t)
        {
            cout << t->data << " " ; t=t->next ;
        }
        cout << endl;
    }
};

int main()
{
    Stack st ;
    for(int i {0} ; i<10 ; i++) st.push(i+1) ;
    st.display() ;
}