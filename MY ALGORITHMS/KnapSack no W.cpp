/* WeakBlood <3 */
#include <bits/stdc++.h>
#define ll long long int
#define INF 1e9
#define lINF 1e18
const int MOD = 1e9+7;
using namespace std;

ll knapsackValueBased(const vector<ll>& weights, const vector<ll>& values, ll W) {
    ll max_value = 0;
    for (int value : values) {
        max_value += value;
    }
    
    vector<ll> dp(max_value + 1, INT_MAX);
    dp[0] = 0;

    for (size_t i = 0; i < weights.size(); ++i) {
        for (ll v = max_value; v >= values[i]; --v) {
            if (dp[v - values[i]] != INT_MAX) {
                dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
            }
        }
    }
    
    ll max_value_achievable = 0;
    for (ll v = 0; v <= max_value; ++v) {
        if (dp[v] <= W) {
            max_value_achievable = v;
        }
    }

    return max_value_achievable;
}
	

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	#ifdef LOCAL
	ifstream cin("input.txt");
	#endif
	
	ll N,W;
	cin >> N >> W;
	vector<ll> value(N),weights(N);
	for(int i = 0; i < N; i++){
		cin >> weights[i] >> value[i];
	} 
	cout << knapsackValueBased(weights,value,W) << "\n";
	return 0;
}
