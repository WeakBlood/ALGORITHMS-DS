/* WeakBlood <3 */
#include <bits/stdc++.h>
#define LL long long int
#define INF 1e9
#define lINF 1e18
using namespace std;

class Hash {
private:
    static constexpr int SZ = 3;
    static constexpr LL mod = 2e9 + 11;
    static constexpr array<LL,SZ> pr = {29,31,37};
    
public:
    int n;
    string s;
    vector<array<LL,SZ>> hsh;
    vector<array<LL,SZ>> pws;

    Hash(int _n, string _s) : n(_n), s(_s) {
        hsh.resize(n + 1);
        pws.resize(n + 1);
        for(int j = 0; j < SZ; ++j)
        {
        	hsh[0][j] = 0;
        	pws[0][j] = 1;
		}
        for (int i = 1; i <= n; ++i) {
        	for(int j = 0; j < SZ; ++j)
        	{
        		pws[i][j] = pws[i - 1][j] * pr[j] % mod;
            	hsh[i][j] = pr[j] * hsh[i - 1][j] + (s[i - 1] - '`');
            	hsh[i][j] %= mod;
			}

        }
    }

    array<LL,SZ> get_hash(int l, int len) {
    	array<LL,SZ> ans;
    	for(int j = 0; j < SZ; ++j)
    	{
    		ans[j] = (hsh[l + len][j] - hsh[l][j] * pws[len][j] % mod + mod) % mod;
		}
        return ans;
    }

    bool same(int l, int r, int len) {
        return get_hash(l, len) == get_hash(r, len);
    }
};

bool founded(Hash &myHashing, int interval, int N)
{
	set<array<LL,3>> mySet;
	for(int i = 0; i + interval <= N; i++)
    {
    	array<LL,3> thisHash = myHashing.get_hash(i,interval);
    	if(mySet.find(thisHash)!=mySet.end()) return true;
    	  
    	mySet.insert(thisHash);
	}
	return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N;
    cin >> N;
    string s;
    cin >> s;
    Hash myHashing(N,s);
    
	int l = 0; int r = N;
	int best = 0;
	while(l <= r)
	{
		int middle = l + (r - l) / 2;
		if(founded(myHashing,middle,N))
		{
			best = middle;
			l = middle+1;
		}
		else r = middle-1;
	}
	cout << best << "\n";
     return 0;
}
