#include <bits/stdc++.h>
using namespace std;

// binary search tree : it's a binary tree but for each node the left subtree has elements smaller
// than parent node and right subtree has elements greater than parent node

// PROPERTIES : 
// 1. it should have no duplicates 
// 2. inorder traversal gets us sorted order of node values !
// 3. for a given no. of nodes only ONE BST is possible since there is only one sorted order !
// 4. we can construct a bst from only preorder or postorder traversal !

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

class bst // stands for binary search tree
{
    public :
    node *root ;
    bst(node* r = nullptr) : root(r) 
    {
        // cout << "Tree constructor called" << endl;
    }
    ~bst()
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
    void iter_insert(int key)
    {
        if(!root)
        {
            root = new node(key) ;
            return ;
        }
        node *t = root ;
        node *r ; // tailing pointer of t, to get access to it's previous node !!
        while(t)
        {
            r = t ;
            if(key<t->data) t = t->left ;
            else if(key>t->data) t = t->right ;
            else return ;
        }
        if(key<r->data) r->left = new node(key) ;
        else r->right = new node(key) ;
    }
    void recc_insert(node *&t,int key)
    {
        if(!t)
        {
            t = new node(key) ;
            return ;
        }
        if(key<t->data) recc_insert(t->left,key) ;
        if(key>t->data) recc_insert(t->right,key) ;
    }
    bool iter_search(int key) // iterative search, needs one argument only that is the key !!
    {
        node *t = root ;
        if(!t) return false ;
        while(t)
        {
            if(key<t->data) t = t->left ;
            else if(key>t->data) t = t->right ;
            else return true ;
        }
        return false ;
    }
    bool recc_search(node *t, int key) // recursive search, needs two arguments since it's a recursive function !!
    {
        if(!t) return false ;
        if(key<t->data) return recc_search(t->left,key) ;
        else if(key>t->data) return recc_search(t->right,key) ;
        else return true ;
        return false ;
    }
    void deletenode() ; // TO BE CODED !!!
    void inorder_traversal(node *t)
    {
        if(t)
        {
            inorder_traversal(t->left) ;
            cout << t->data << " " ;
            inorder_traversal(t->right) ;
        }
    }
    // generation bst from given preorder traversal also to be coded !!!
};

int main()
{
    bst b ;
    b.recc_insert(b.root,5) ;
    for(int i {1} ; i<5 ; i++) b.recc_insert(b.root,i) ;
    for(int i {6} ; i<10 ; i++) b.recc_insert(b.root,i) ;
    b.inorder_traversal(b.root) ;
    cout << endl;
    b.recc_insert(b.root,5) ;
    b.inorder_traversal(b.root) ;
    cout << endl;
    cout << boolalpha << b.iter_search(8) << " " << b.iter_search(11) << endl;
    cout << boolalpha << b.recc_search(b.root,8) << " " << b.recc_search(b.root,11) << endl;
}

// DRAWBACKS : the height of a BST depends on order or insertion of keys 
// minimun height is O(log(n)) and max heigth is O(n) ;
// to control height of binary tree we introduce balance factor in it and now 
// we call the tree as AVL trees which are height balanced BST !!