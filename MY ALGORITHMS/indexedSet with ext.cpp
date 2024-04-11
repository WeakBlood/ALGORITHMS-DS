#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// We're pairing the value with its original index to distinguish between duplicates and maintain order
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
	#ifdef LOCAL
	ifstream cin("input.txt");
	#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    indexed_set myCoolSet;
    
    // Insert elements with their indices
    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        myCoolSet.insert({i+1, n}); // Using 1-based index for consistency with problem statement
    }
    
    // Removing and printing elements according to given positions
    for(int i = 0; i < N; i++) {
        int pos;
        cin >> pos;
        // Find the element at position 'pos' (1-indexed)
        auto it = myCoolSet.find_by_order(pos-1);
        cout << it->second << " "; // Print the value of the element
        myCoolSet.erase(it); // Remove the element from the set
    }
    return 0;
}

