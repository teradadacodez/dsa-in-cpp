#include <bits/stdc++.h>
using namespace std;

class node
{
    public :
    int data ;
    node *next ;
    node(int x, node *n = nullptr) : data(x), next(n) {}
    ~node() {}
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
    Stack() : top(nullptr) {}
    ~Stack()
    {
        node *temp {nullptr} ;
        while(top)
        {
            temp = top ;
            top = top->next ;
            delete temp ;
        }
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
    // making isEmpty function for this code
    bool isEmpty()
    {
        return (top==nullptr) ;
    }
};

// implementing queue using two stacks
// idea is we will push in stack 1 and pop out from stack two provided that
// we pushed all elems of stack 1 to stack 2, the order gets reversed !!

int main()
{
    string s {"tanmay jain"} ;
    Stack st1, st2 ;
    for(auto i : s) st1.push(i-'0') ;
    while(!st1.isEmpty()) st2.push(st1.pop()) ;
    string ans ;
    while(!st2.isEmpty()) ans.push_back(st2.pop()+'0') ;
    cout << ans << endl;
}