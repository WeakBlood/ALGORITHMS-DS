/* WeakBlood <3 */
#include <bits/stdc++.h>

using namespace std;


int finding(int N, const vector<int> &arr, int interval)
{
	if(N == interval) return -1;
	bool allEqual = true;
	int idx = interval;
	for(int i = 1; i < N/interval && allEqual; i++)
	{
		//here the magic happens, if all segments are equal this means that we are gonna have N / intervals possible rotations 
		int nI = 0;
		for(int j = idx; j < idx + interval; j++)
		{
			if(arr[nI] != arr[j]) allEqual = false;
			nI++;
		}
		idx += interval;
	}
	if(allEqual) return N/interval;
	return -1;
}
int solve(int N, const vector<int> &arr)
{
	// finding divisors ihihi
	auto sqrtOf = sqrt(N);
	int Maxi = 1;
	for(int i = 1; i <= sqrtOf; i++)
	{
		if(N%i == 0)
		{
			//there could be 2 
			if(N / i == i)
			{
				//there is only 1
				Maxi = max(finding(N,arr,i),Maxi);
			}
			else
			{
				//there are two 
				Maxi = max(finding(N,arr,i),Maxi);
				Maxi = max(finding(N,arr,N/i),Maxi);
			}
		}
	}
	return Maxi;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    #endif
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
    	int N;
	    cin >> N;
		vector<int> arr(N);
		for(int i = 0; i < N; i++) cin >> arr[i];
		cout << "Case #" << t << ": " << solve(N,arr) << "\n";
	}
     return 0;
}
