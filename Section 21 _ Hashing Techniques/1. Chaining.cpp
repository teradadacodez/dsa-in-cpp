#include <bits/stdc++.h>
using namespace std;

class node
{
    public :
    int data ;
    node* next ;
    node(int x = INT_MIN , node* p = nullptr) : data(x) , next(p) {} ;
};

// CHAINING : hash table is the array of node pointers i.e. array of linked lists !!
// aka BUCKETING / BINNING since these are buckets or bins !!

// hash function be h(x) = x%100 !!
int h(int x) {return x%100 ;}

// a factor is defined for hash table <lambda> = (no. of keys)/(size of hash table)
// it tells no. of keys per hash , which is also the measuring factor of time complexity of hashing
// because index is accessed at O(1) and then searching in linked list takes O(<lambda>) time !!
// <lambda> is aka loading factor !!

class hashtable
{
    int size ;
    node **hash ;
    public :
    hashtable(int s = 100) : size(s) , hash(new node*[s]()) {} // node *[s]() initializes all pointers to nullptr
    ~hashtable()
    {
        for(int b{0}; b<size; b++)
        {
            node* p = hash[b];
            while(p != nullptr)
            {
                node* nxt = p->next;
                delete p;
                p = nxt;
            }
        }
        delete[] hash;
    }
    void insert(int key) // sorted insert
    {
        int ind {h(key)} ;
        node *newnode = new node(key) ;
        if(hash[ind] == nullptr) hash[ind] = newnode ;
        else
        {
            if(key < hash[ind]->data)
            {
                newnode->next = hash[ind] ;
                hash[ind] = newnode ;
            }
            else
            {
                node *t = hash[ind] ;
                while(t->next != nullptr && t->next->data < key) t = t->next ;
                newnode->next = t->next ;
                t->next = newnode ;
            }
        }
    }
    bool search(int key)
    {
        int ind {h(key)} ;
        node *t = hash[ind] ;
        while(t!=nullptr && t->data != key) t=t->next ;
        return (t!=nullptr) ;
    }
    int remove(int key)
    {
        int x {INT_MIN} ;
        if(!search(key)) return x ;
        int ind {h(key)} ;
        node *t = hash[ind] ;
        node *r = nullptr ; // trailing pointer to t !!
        while(t!=nullptr && t->data!=key)
        {
            r = t ;
            t = t->next ;
        }
        x = t->data ;
        if(r==nullptr) hash[ind] = t->next ;
        else r->next = t->next ;
        delete t;
        return x ;
    }
};
int main()
{
    int a[] = {1,2,3,4,5,11,22,33,44,55,12,23,34,45} ;
    hashtable ht ;
    for(int i {0} ; i<(int)sizeof(a) ; i++) ht.insert(a[i]) ;

    cout << boolalpha << ht.search(5) << " " << ht.search(56) << endl;
    cout << "removed : " << ht.remove(45) << endl;
    cout << boolalpha << ht.search(45) << endl;
}