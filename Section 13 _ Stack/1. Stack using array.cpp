#include <bits/stdc++.h>
using namespace std;
// stack works on LIFO (last in first out) principle 
// stack ADT contains 
// 1. space for storing elements
// 2. top pointer
// and some operations like push(x), pop(), peek(index), stacktop(), isempty(), isfull(), ....

/* Diagram of the ADT is :
|-------|
|   1   |  index : 0 , inserted last
|-------|
|   2   |
|-------|
|   3   |
|-------|
|   4   |  index : 3 , inserted first
|-------|
*/
// implementing stack using arrays
class mystack
{
    public :
    int size ;
    int top ;
    int *s ;
};
void create(mystack *st)
{
    cout << "Enter Size : " ;
    cin >> st->size ;
    int x = st->size ;
    st->top = -1 ; 
    st->s = new int[x] ;
}
void display(mystack st)
{
    for(int i {st.top} ; i>=0 ; i--) cout << st.s[i] << " " ;
    cout << endl;
}
// pushing in arrays is done at last because is takes O(1) time 
// but if we push at first position always then we also have to shift all elements further everytime
// which takes O(n) time and for creating a full stack takes O(n^2) time !!
void push(mystack *st , int x)
{
    if(st->top == st->size-1)
    {
        cout << "Stack Overflow" << endl;
        return ;
    }
    st->top++ ; // incrementing top first before inserting x because we have initialized it to -1 !!
    // incrementing it would make it 0 and inserting at 0 makes sense !!
    st->s[st->top] = x ;
}
int pop(mystack *st)
{
    int x {INT_MIN} ;
    if(st->top == -1)
    {
        cout << "Stack Underflow" << endl;
        return INT_MIN;
    }
    x = st->s[st->top] ;
    st->top-- ;
    return x ; 
}
int peek(mystack *st, int index)
{
    int x {INT_MIN} ;
    if(st->top-index+1 < 0)
    {
        cout << "invalid index given" << endl;
        return x ;
    }
    x = st->s[st->top-index+1] ;
    return x;
}
int top(mystack st)
{
    if(st.top == -1) return INT_MIN ;
    return st.s[st.top] ;
}
bool isempty(mystack st)
{
    return (st.top == -1) ;
}
bool isfull(mystack st)
{
    return (st.top == st.size-1) ;
}
int main()
{
    mystack st ;
    create(&st) ;
    int a[] = {1,2,3,4,5} ;
    for(int i {0} ; i<5 ; i++) push(&st,a[i]) ;
    push(&st,6) ;
    display(st) ;
    cout << boolalpha << isfull(st) << endl;
    cout << pop(&st) << endl;
    display(st) ;
    cout << boolalpha << isfull(st) << endl; 
    cout << peek(&st,3) << endl;
    for(int i {0} ; i<4 ; i++) cout << "Popped out : " << pop(&st) << endl;
    cout << boolalpha << isempty(st) << endl ;
    pop(&st) ;
}