#include <bits/stdc++.h>
using namespace std;

class node
{
    public : 
    node *left ;
    int data ;
    node *right ;
    node(int x, node *l = nullptr, node *r = nullptr) : data(x), left(l), right(r) 
    {
        // cout << "node constructor called" << endl;
    }
    ~node()
    {
        // cout << "node destructor called" << endl;
    }
};

class binarytree
{
    public :
    node *root ;
    binarytree(node* r = nullptr) : root(r) 
    {
        // cout << "Tree constructor called" << endl;
    }
    ~binarytree()
    {
        destroy(root) ;
        // cout << "Tree destructor called" << endl;
    }
    void destroy(node *t)
    {
        if(!t) return ;
        destroy(t->left) ;
        destroy(t->right) ;
        delete t ;
    }
    void create_tree()
    {
        string line ;
        queue<node*> qq ;
        node *p,*t ;
        cout << "Enter root node value : "; getline(cin,line) ;
        while(line.empty())
        {
            cout << "Root cannot be empty, enter a valid value : ";
            getline(cin,line) ;
        }
        int x = stoi(line) ;
        root = new node(x) ;
        qq.push(root) ;
        while(!qq.empty())
        {
            p = qq.front() ;
            qq.pop() ;
            cout << "Enter Left child of " << p->data << " (to leave blank, press enter) : " ;
            getline(cin,line) ;
            if(!line.empty())
            {
                x = stoi(line) ;
                t = new node(x) ;
                p->left = t ;
                qq.push(t) ;
            }
            cout << "Enter Right child of " << p->data << " (to leave blank, press enter) : " ;
            getline(cin,line) ;
            if(!line.empty())
            {
                x = stoi(line) ;
                t = new node(x) ;
                p->right = t ;
                qq.push(t) ;
            }
        }
    }
    void preorder_traversal(node *t)
    {
        if(t)
        {
            cout << t->data << " " ;
            preorder_traversal(t->left) ;
            preorder_traversal(t->right) ;
        }
    }
    void inorder_traversal(node *t)
    {
        if(t)
        {
            inorder_traversal(t->left) ;
            cout << t->data << " " ;
            inorder_traversal(t->right) ;
        }
    }
    void postorder_traversal(node *t)
    {
        if(t)
        {
            postorder_traversal(t->left) ;
            postorder_traversal(t->right) ;
            cout << t->data << " " ;
        }
    }
    void levelorder_traversal(node *t)
    {
        if(!t) return ;
        queue<node*> q ; 
        q.push(t) ;
        while(!q.empty())
        {
            t = q.front() ;
            q.pop() ;
            cout << t->data << " " ;
            if(t->left) q.push(t->left) ;
            if(t->right) q.push(t->right) ;
        }
    }
    // now these three functions will have same recursive outline as calulate(left), calculate(right), return <something> !!
    // we can add new conditions and different returns to create different useful functions !!
    int countnodes(node *t)
    {
        if(t)
        {
            int x {countnodes(t->left)} ;
            int y {countnodes(t->right)} ;
            return x+y+1 ;
        }
        return 0 ;
    }
    int height(node *t)
    {
        if(t)
        {
            int x {height(t->left)} ;
            int y {height(t->left)} ;
            return max(x,y)+1 ;
        }
        return 0 ;
    }
    int count_leaves(node *t)
    {
        if(t)
        {
            int x {count_leaves(t->left)} ;
            int y {count_leaves(t->right)} ;
            if(t->left && t->right) return x+y+1 ;
            // change this condition to t->left ^ t.right which is equivalent to  
            // ((t->left && (!t->right)) || (t->right && (!t->right)))
            // you will get nodes with degree 1
            // similarly you can find degree 0 , degree>=1 also !
            else return x+y ;
        }
        return 0 ;
    }
    void iterative_preorder(node *t) ;
    void iterative_inorder(node *t) ;
    void iterative_postorder(node *t) ;
    void iterative_levelorder(node *t) ;
} ;
// we need a stack<node*> for this !!
// upon moving to next node first we should push the address of previous node to the stack
// and when we reach a leaf node's nullptr or when the function call ends we pop out the top of the 
// stack and go to that address !

// preorder steps are print, left, right !!
void binarytree::iterative_preorder(node *t)
{
    if(!t) return ;
    stack<node*> st ;
    while(t!=nullptr || (!st.empty()))
    {
        if(t!=nullptr)
        {
            cout << t->data << " " ;
            st.push(t) ;
            t = t->left ;
        }
        else
        {
            t = st.top() ;
            st.pop() ;
            t = t->right ;
        }
    }
}
void binarytree::iterative_inorder(node *t)
{
    if(!t) return ;
    stack<node*> st ;
    while(t!=nullptr || (!st.empty()))
    {
        if(t!=nullptr)
        {
            st.push(t) ;
            t = t->left ;
        }
        else
        {
            t = st.top() ;
            st.pop() ;
            cout << t->data << " " ;
            t = t->right ;
        }
    }
}
void binarytree::iterative_postorder(node *t)
{
    if(!t) return ;
    stack<node*> st ;
    node *vis ; // last visited node
    while(t!=nullptr || (!st.empty()))
    {
        if(t)
        {
            st.push(t) ;
            t = t->left ;
        }
        else
        {
            node *peeknode = st.top() ;
            // if right exists and not visited yet then : 
            if(peeknode->right && vis != peeknode->right)
            {
                t = peeknode->right ;
            }
            else
            {
                cout << peeknode->data << " " ;
                vis = peeknode ;
                st.pop() ;
            }
        }
    }
}
void binarytree::iterative_levelorder(node *t)
{
    queue<node*> qq ;
    cout << t->data << " ";
    qq.push(t) ;
    while(!qq.empty())
    {
        t = qq.front() ;
        qq.pop() ;
        if(t->left)
        {
            cout << t->left->data << " ";
            qq.push(t->left) ;
        }
        if(t->right)
        {
            cout << t->right->data << " ";
            qq.push(t->right) ;
        }
    }   
}
int main()
{
    binarytree bt ;
    bt.create_tree() ;
    bt.levelorder_traversal(bt.root) ;
    cout << endl;
    bt.iterative_levelorder(bt.root) ;
    cout << endl;
}