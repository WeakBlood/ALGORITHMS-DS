#include <bits/stdc++.h>


using namespace std;
#define ll long long int
// REMEMBER THIS ALGORITHM IS FOR RANGE [L,R[ NOT [L,R]!!!!!!"!"
struct segmentSimple{
    int N;
    vector<ll> tree;
    
    segmentSimple(int N_, const vector<int> &vet):N(N_)
    {
        tree.resize(N*2);
        for(int i = 0; i < N; i++) tree[i+N] = vet[i];
        for(int i = N - 1; i > 0; i--) tree[i] = tree[i*2] + tree[i*2+1];
    }

    void update(int p, int val)
    {
        for(tree[p+N]+=val; p > 1; p>>=1) tree[p>>1] = tree[p^1] + tree[p];
    }

    ll sum(int l, int r)
    {
        ll s = 0;
        for(l+=N,r+=N; l < r; l >>= 1, r>>=1)
        {
            if(l & 1) s+=tree[l++];
            if(r & 1) s+=tree[--r];
        }
        return s;
    }
};




