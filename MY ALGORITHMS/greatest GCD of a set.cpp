/* WeakBlood <3 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000001;
int maxi = 1;
bitset<MAXN> table;
void findDiv(int X)
{
	int squirt = sqrt(X);
	for(int i = 1; i<= squirt; i++)
	{
		if(X % i == 0)
		{
			if(table[i]) maxi = max(maxi,i);
			if(table[X/i]) maxi = max(maxi,X/i);
			table[X/i] = 1;
			table[i] = 1;
		}
	}
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
    
    for(int i = 0; i < N; i++)
    {
    	int n;
    	cin >> n;
    	findDiv(n);
	}
	
	cout << maxi << "\n";
     return 0;
}
