#include <bits/stdc++.h>

using namespace std;


struct Dsu{
    vector<int> parent,rank;
    int N;
    Dsu(int N_):N(N_)
    {
        rank.resize(N,1);
        parent.resize(N);
        for(int i = 0; i < N; i++) parent[i] = i;
    }

    int find_set(int a)
    {
        return parent[a] == a ? a:parent[a] = find_set(parent[a]);
    }

    bool merge(int a, int b)
    {
        a = find_set(a); 
        b = find_set(b);
        if(a == b) return false;
        if(rank[a] < rank[b]) swap(a,b);
        rank[a]+=rank[b];
        parent[b] = a;
        return true;
    }
};
