#include <bits/stdc++.h>
using namespace std;

class node
{
    public : 
    int data ;
    node *next ;

    node(int x, node* n = nullptr) : data{x} , next(n) {} // if single node is present it's next is nullptr

}*top = nullptr ;

void push(node *&p, int x)
{
    p = new node(x,p) ; 
    // by this we can make stack of any size, we just have to push as many values as we can
}
void display(node *t)
{
    while(t)
    {
        cout << t->data << " " ;
        t=t->next ;
    }
    cout << endl;
}
int pop(node *&t)
{
    int x {INT_MIN} ;
    node *p = t ;
    if(t == nullptr)
    {
        cout << "Stack Underflow" << endl;
        return x ;
    }
    x = t->data ;
    t = t->next ;
    delete p ;
    return x;
}
int length(node *t)
{
    int k {0} ;
    while(t)
    {
        k++ ; t = t->next ;
    }
    return k ;
}
int peek(node *t, int pos)
{
    int x {INT_MIN} ;
    if(pos<0 || pos>length(t))
    {
        cout << "Invalid index given, returning ";
        return x ;
    }
    for(int i {0} ; i<pos-1 ; i++) t = t->next ;
    return t->data ;
}

// ------------------- APPLICATIONS ------------------------

// say we are given with a string s = "((a+b)*(c-d))"; then we can scan through this string and
// push every '(' and pop that out for every ')' , ignoring all other characters a,b,c,d,+,-,* etc...
// string s is assumed to be mathematically correct, (a+)b(c*d) this is balanced but not correct mathematically
bool parenthesis_balance(string s)
{
    node *t = nullptr ;
    for(auto i : s)
    {
        if(i=='(') push(t,1) ;
        if(i==')') pop(t) ;
    }
    return (length(t)==0) ;
}
bool bracket_balance(string s) // general version !!!
{
    node *t = nullptr ;
    for(auto i : s)
    {
        if(i=='{'||i=='['||i=='(') push(t,i-'0') ;
        if(i=='}'||i==']'||i==')')
        {
            if(!t) return false ;
            if(i-'0' != (t->data)+((i==')')?1:2)) return false ; 
            // char codes of brackets are '{' = 123 , '}' = 125 , '(' = 40 , ')' = 41 , '[' = 91 , ']' = 93 ;
            if(t) pop(t) ;
            else return false ;
        }
    }
    return (t==nullptr) ;
}
// we require a custom helper function of precedences in which we have highest precedence of operands !!
int precedence(char x)
{
    if(x=='+'||x=='-') return 1 ;
    if(x=='*'||x=='/') return 2 ;
    return 3 ; // for operands a,b,c...
}
string infix_to_postfix(string exp)
{
    node *t = nullptr ;
    string ans ;
    for(auto i : exp)
    {
        while(t!=nullptr && precedence(i)<=precedence(t->data+'0')) 
        {
            ans.push_back(t->data+'0');
            pop(t) ;
        }
        push(t,i-'0') ;
    }
    while(t)
    {
        ans.push_back(t->data+'0') ;
        pop(t) ;
    }
    return ans ;
}
// but this function will only be applicable to +,-,*,/ i.e. the operators with 
// left to right associativity .
// for a general case with paranthesis and power operator "^" , we have a different precedence functions !!
// observe that for operator with R to L associativity has increased precedence instack !!
// and vice versa for operator with L to r associativity
int instack_precedence(char x)
{
    if(x=='+'||x=='-') return 2 ;
    if(x=='*'||x=='/') return 4 ;
    if(x=='^') return 5 ;
    if(x=='(') return 0 ;
    return 8 ; // for operands a,b,c...
}
int outstack_precedence(char x)
{
    if(x=='+'||x=='-') return 1 ;
    if(x=='*'||x=='/') return 3 ;
    if(x=='^') return 6 ;
    if(x=='(') return 7 ;
    if(x==')') return 0 ;
    return 8 ; // for operands a,b,c...
}
string infix_to_postfix_general(string exp)
{
    node *t = nullptr ;
    string ans ;
    for(auto i : exp)
    {
        if(isalnum(i)) ans.push_back(i) ;
        else if(i == '(') push(t,i-'0');
        else if(i == ')')
        {
            while(t && (t->data+'0')!='(')
            {
                ans.push_back(t->data+'0');
                pop(t) ;
            }
            if(t) pop(t) ; // pops out last '('
        }
        else
        {
            while(t!=nullptr && outstack_precedence(i)<=instack_precedence(t->data+'0') && (t->data+'0')!='(') 
            {
                ans.push_back(t->data+'0');
                pop(t) ;
            }
            push(t,i-'0') ;
        }
    }
    while(t)
    {
        char c = t->data+'0' ;
        if(c!='('||c!=')') ans.push_back(t->data+'0') ;
        pop(t) ;
    }
    return ans ;
} 
long long evaluate_postfix(string s)
{
    node *t = nullptr ;
    for(auto i : s)
    {
        if(isdigit(i)) push(t,i-'0') ;
        else
        {
            long long y {pop(t)} , x {pop(t)} ;
            if(i=='+') push(t,(x+y)) ;
            if(i=='-') push(t,(x-y)) ;
            if(i=='*') push(t,(x*y)) ;
            if(i=='/') push(t,(x/y)) ;
            if(i=='^') push(t,pow(x,y)) ;
        }
    }
    long long res = pop(t) ;
    return res ;
}
int main()
{
    push(top,10) ;
    push(top,20) ;
    push(top,30) ;
    display(top) ;
    int k {length(top)} ;
    cout << k << endl;
    for(int i {0} ; i<k ; i++) cout << "Popped out : " << pop(top) << " " ; cout << endl;
    pop(top) ;
    for(int i {0} ; i<5 ; i++) push(top,i+1) ;
    display(top) ;
    cout << peek(top,4) << endl;
    cout << peek(top,6) << endl;
    string s = "((a+b)*(c-d))";
    cout << boolalpha << parenthesis_balance(s) << endl;
    string s1 = "[(a+b)*{c-(a/b)}]" ;
    cout << boolalpha << bracket_balance(s1) << " " << bracket_balance(s) << endl;
    string s2 = "((a+b)/(c+d)*e-f^g^h)" ;
    cout << infix_to_postfix_general(s2) << endl;
    string s3 = "3+5*8/2^2-1" ;
    cout << evaluate_postfix(infix_to_postfix_general(s3)) << endl;
}
