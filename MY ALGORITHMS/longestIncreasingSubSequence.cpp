#include <bits/stdc++.h>

using namespace std;
int LIS(vector<int>& nums)
{

	int n = nums.size();
	vector<int> ans;
	ans.push_back(nums[0]);
	for (int i = 1; i < n; i++) 
    {
		if (nums[i] > ans.back()) 
        {
			ans.push_back(nums[i]);
		}
		else 
        {
			int low = lower_bound(ans.begin(), ans.end(),nums[i]) - ans.begin();
			ans[low] = nums[i];
		}
	}
	return ans.size();
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
    vector<int> vet(N);
    for(int i = 0; i < N; i++) cin >> vet[i];

    cout << LIS(vet) << "\n";
    return 0;
}