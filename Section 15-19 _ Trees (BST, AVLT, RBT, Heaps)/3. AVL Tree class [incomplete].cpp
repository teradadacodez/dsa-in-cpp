#include <bits/stdc++.h>
using namespace std;

// balance factor of a parent node = height of left subtree - height of right subtree 
// bf = |hl - hr| <= 1 , we calculate in such a way that it must one of the following values !
// bf = {-1,0,1} !!
// if every node's bf lies in the set then the tree is said balanced avltree or an avl tree
// if atleast one node has |bf| > 1 then the complete tree is said to be imbalanced avltree !
class node
{
    public : 
    node *left ;
    int data ;
    int height ;
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

class avltree
{
    public :
    node *root ;
    avltree(node* r = nullptr) : root(r) 
    {
        // cout << "Tree constructor called" << endl;
    }
    ~avltree()
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
    int nodeheight(const node *t)
    {
        int hl , hr ;
        hl = t&&t->left ? t->left->height : 0 ;
        hr = t&&t->right ? t->right->height : 0 ;
        return max(hl,hr)+1 ;
    }
    int balancefactor(node *t)
    {
        int hl , hr ;
        hl = t&&t->left ? t->left->height : 0 ;
        hr = t&&t->right ? t->right->height : 0 ;
        return hl-hr ;
    }
    void insert(int key)
    {
        recc_insert(root,key) ;
    }
    private : 
    void recc_insert(node *&t,int key)
    {
        if(!t)
        {
            t = new node(key) ;
            t->height = 1 ;
            return ;
        }
        if(key<t->data) recc_insert(t->left,key) ;
        if(key>t->data) recc_insert(t->right,key) ;
        t->height = nodeheight(t) ;

        if(balancefactor(t) == 2 && balancefactor(t->left) == 1) LLrotation(t) ;
        else if(balancefactor(t) == 2 && balancefactor(t->left) == -1) LRrotation(t) ;
        else if(balancefactor(t) == -2 && balancefactor(t->right) == -1) RRrotation(t) ;
        else if(balancefactor(t) == -2 && balancefactor(t->right) == 1) RLrotation(t) ;
    }
    void LLrotation(node *&t)
    {
        cout << "LL rotation" << endl;
        node *tl = t->left ;
        node *tlr = tl->right ;

        tl->right = t ;
        t->left = tlr ;
        if(root==t) root = tl ;
        t->height = nodeheight(t) ;
        tl->height = nodeheight(tl) ; // update all heights 
        t = tl ;
        return ;
    }
    void LRrotation(node *&t)
    {
        cout << "LR rotation" << endl;
        node *tl = t->left ;
        node *tlr = tl->right ;

        tl->right = tlr->left ; // REMEMBER NOT TO DO LIKE THIS : tlr = trl->left and
        t->left = tlr->right ;  // tl = tlr->right !!
        // this is because we declared tl and tlr as external pointer for if we loose a link to t->left 
        // and t->left->right accessing them !!
        tlr->left = tl ;
        tlr->right = t ;
        if(t == root) root=tlr ;
        t->height = nodeheight(t) ;
        tl->height = nodeheight(tl) ;
        tlr->height = nodeheight(tlr) ; // update all heights 
        t = tlr ;
        return ;
    }
    void RRrotation(node *&t)
    {
        cout << "RR rotation" << endl;
        node *tr = t->right ;
        node *trl = tr->left ;
        tr->left = t ;
        t->right = trl ;
        if(t == root) root = tr ;
        t->height = nodeheight(t) ;
        tr->height = nodeheight(tr) ; // update all heights 
        t = tr ;
        return ;
    }   
    void RLrotation(node *&t)
    {
        cout << "RL rotation" << endl;
        node *tr = t->right ;
        node *trl = tr->left ;
        tr->left = trl->right ;
        trl->right = tr ;
        t->right = trl->left ;
        trl->left = t ;
        if(t==root) root = trl ;
        t->height = nodeheight(t) ;
        tr->height = nodeheight(tr) ;
        trl->height = nodeheight(trl) ; // update all heights
        t = trl ;
        return ;
    }
    // delete function to be coded !!
};

int main()
{
    avltree avl ;
    for(int i {1} ; i<6 ; i++) avl.insert(i) ;
    cout << avl.root->data << endl;
}