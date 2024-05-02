#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
int t, n;
 
vector<pair<int, int>> arr;
 
long long ans;
 
ordered_set st;
 
void solve(){

 
    sort(arr.begin(), arr.end());
 
    ans = 0;
    st.clear();
 
    for(auto p : arr){
        ans += st.size() - st.order_of_key(p.second);
 
        st.insert(p.second);
    }
 
    cout << ans << "\n";
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef LOCAL
	ifstream cin("input.txt");
	#endif
    cin >> t;
 
    while(t--){
    	cin >> n;
    	arr.assign(n, {});
    	for(auto &p : arr) cin >> p.second >> p.first;
        solve();
    }
}