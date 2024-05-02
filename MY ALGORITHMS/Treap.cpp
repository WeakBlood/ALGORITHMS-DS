#include <iostream>
#include <limits>
#include <random>
using namespace std;
mt19937 rng(random_device{}()); 
uniform_int_distribution<int> dist(1, numeric_limits<int>::max());
struct Treap{
    int key,priority,size;
    Treap *left, *right;

    Treap(int _key) : key(_key),size(1),left(nullptr),right(nullptr)
    {
        priority = dist(rng);
    }

    void updateSize()
    {     
        size = 1;
        if(left != nullptr)
        {
            size += left->size;
        }
        if(right != nullptr)
        {
            size += right->size;
        }
    }
};

int getSize(Treap* T)
{
    return T ? T->size : 0;
}

void split(Treap* T, int key, Treap*&L,Treap*& R)
{
    if(!T)
    {
        L = R = nullptr;
    }
    else if(key < T->key)
    {
        split(T->left,key,L,T->left);
        R = T;
    }
    else
    {
        split(T->right,key,T->right,R);
        L = T;
    }
    if(T)
    {
        T->updateSize();
    }
}

Treap* merge(Treap* L, Treap* R)
{
    if(!L || !R)
    {
        return L ? L:R;
    }
    if(L->priority > R-> priority)
    {
        L->right = merge(L->right,R);
        L->updateSize();
        return L;
    }
    else
    {
        R->left = merge(L,R->left);
        R->updateSize();
        return R;
    }
}

Treap* insert(Treap* T, int key) {
    Treap *L, *R;
    split(T, key, L, R);
    Treap* newTreap = new Treap(key);
    Treap* result = merge(merge(L, newTreap), R);
    return result;
}


Treap* erase(Treap* T, int key)
{
    Treap *L,*M,*R;
    split(T,key-1,L,R);
    split(R,key+1,M,R);
    return merge(L,R);
}

int Klarge(Treap* T, int& k) {
    if (T == nullptr) 
    {
        return -1;
    }

    int rightResult = Klarge(T->right, k);
    if (k == 0) 
    {
        return rightResult;
    }

    k--;
    if (k == 0) 
    {
        return T->key; 
    }

    return Klarge(T->left, k);
}

int main()
{
    Treap* root = nullptr;
    root = insert(root,5);
    root = insert(root,2);
    root = insert(root,9);
    root = insert(root,4);
    int K = 1;
    root = erase(root,9);

    cout << Klarge(root,K) << endl;

    return 0;
}