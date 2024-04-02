#include <bits/stdc++.h>

using namespace std;
#define ll long long int
class FenwickTree{
    private: 
        vector<ll> bit;
        int N;
    public: 
        FenwickTree(int N_)
        {
            this->N = N_;
            bit.assign(N+1,0);
        }
    
    FenwickTree(const vector<int> &vet): FenwickTree(vet.size())
    {
        for(size_t i = 0; i < vet.size(); i++) update(i,vet[i]);
    } 

    void update(int idx, int val, bool increment)
    {
        //using this for incremenent updates
        for(++idx; idx <= N; idx+= idx & -idx) bit[idx]+=val;
    }
    void update(int idx, int val)
    {
        //this for update where now vet[i] = val;
        ll now = sum(idx) - sum(idx - 1);
        ll diff = val - now;
        for(++idx; idx <= N; idx+= idx & -idx) bit[idx]+=diff;
    }    
    ll sum(int idx)
    {
        ll v = 0;
        for(++idx; idx > 0; idx -= idx & -idx) v+=bit[idx];
        return v;
    }
    ll rangeSum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    } 

};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int n,Q;

    cin >> n >> Q;

    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++) cin >> arr[i];

    FenwickTree myFenwickTree(arr);

    while(Q--)
    {
        int type,l,r;
        cin >> type >> l >> r;
        if(type == 1) myFenwickTree.update(l,r);
        else cout << myFenwickTree.rangeSum(l,r) << "\n";
    }
    return 0;
}