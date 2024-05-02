#include "bits/stdc++.h"

using namespace std;
using LL = long long;

class Hash {
private:
    static constexpr int SZ = 2;
    static constexpr LL mod = 2e9 + 11;
    static constexpr LL pr = 29;
    
public:
    int n;
    string s;
    vector<LL> hsh;
    vector<LL> pws;

    Hash(int _n, string _s) : n(_n), s(_s) {
        hsh.resize(n + 1);
        pws.resize(n + 1);
        hsh[0] = 0;
        pws[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pws[i] = pws[i - 1] * pr % mod;
            hsh[i] = pr * hsh[i - 1] + (s[i - 1] - '`');
            hsh[i] %= mod;
        }
    }

    LL get_hash(int l, int len) {
        return (hsh[l + len] - hsh[l] * pws[len] % mod + mod) % mod;
    }

    bool same(int l, int r, int len) {
        return get_hash(l, len) == get_hash(r, len);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N, Q;
    cin >> N;
    string s;
    cin >> s;
    cin >> Q;
    Hash myHashing(N,s);
    vector<int> divisors[N+1];
    
    for(int i = 1; i <= N; i++)
    {
    	for(int j = i+i; j<= N; j+=i)
    	{
    		divisors[j].push_back(i);
		}
	}
    while (Q--) {
        int l, r;
        cin >> l >> r;
		
		int n = r - l + 1;
		
		bool ok = false;
		
		for(auto u:divisors[n])
		{
			if(myHashing.same(l,l+u,n-u)){
				ok = true;
				break;
			} 
		}
		if(ok) cout << "YES" << "\n";
		else cout << "NO" << "\n";
    }

    return 0;
}

