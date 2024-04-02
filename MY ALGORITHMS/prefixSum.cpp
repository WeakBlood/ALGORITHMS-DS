#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N,Q;

    cin >> N >> Q;
    vector<ll> vet(N+1);
    vet[0] = 0;
    cin >> vet[1];
    for(int i = 2; i <= N; i++)
    {
        cin >> vet[i];
        vet[i]+=vet[i-1];
    }

    while(Q--)
    {
        int l,r;
        cin >> l >> r;
        int idx = l-1;
        cout << vet[r] - vet[idx] << "\n";
    }
    return 0;
}