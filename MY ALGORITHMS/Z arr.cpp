/* WeakBlood <3 */
#include <bits/stdc++.h>
#define ll long long int
#define INF 1e9
#define lINF 1e18
const int MOD = 1e9+7;

using namespace std;
vector<int> z_array(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	#ifdef LOCAL
	ifstream cin("input.txt");
	#endif
	
	string s;
	cin >> s;
	string s1;
	cin >> s1;
	vector<int> z = z_array(s1 + '$' + s);
	
	int N = s1.length();
	int tot = 0;
	for(int i = 0; i < z.size(); i++)
	{
		if(z[i] == N) tot++;
	}
	cout << tot << "\n";
	return 0;
}
