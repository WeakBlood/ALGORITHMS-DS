#include <bits/stdc++.h>

using namespace std;

#define INF numeric_limits<int>::max()

struct Segment{
    int N;
    vector<int> tree;

    Segment(int N):N(N)
    {
        tree.resize(N*2,INF);
    }

    void update(int idx, int value)
    {
        for(tree[idx+=N]=value; idx > 1; idx>>=1)
        {
            tree[idx>>1] = min(tree[idx],tree[idx^1]);
        }
    }

    int mini(int l, int r)
    {
        l = min(l,N); r = min(r,N);

        int ABSmin = INF;
        for(l+=N,r+=N; l < r; l>>=1,r>>=1)
        {
            if(l & 1)  ABSmin = min(ABSmin,tree[l++]);
            if(r & 1) ABSmin = min(ABSmin,tree[--r]);
        }
        return ABSmin;
    }
    
};
int salta(int N, vector<int> &S, vector<int> A, vector<int> B)
{
    vector<int> dp(N);

    Segment segment(N+1);
    segment.update(N,0);
    for(int i = N-1; i >= 0; i--)
    {
        dp[i] = max(S[i],segment.mini(i+A[i],i+B[i]+1));
        segment.update(i,dp[i]);
    }
    return dp[0];
}