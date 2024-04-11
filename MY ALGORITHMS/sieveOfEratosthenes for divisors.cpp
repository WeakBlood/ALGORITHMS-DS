#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9+7;
#define ll long long int
ll fastExp(ll a, int b)
{
    ll res = 1;
    while(b > 0)
    {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b>>=1;
    }
    return res;
}

int main()
{
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N;
    cin >>  N;

    while(N--)
    {
        int a,b;
        cin >> a >> b;
        cout << fastExp(a,b) << "\n";
    }
    return 0;
}
