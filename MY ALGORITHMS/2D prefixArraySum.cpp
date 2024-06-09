/* WeakBlood <3 */
#include <bits/stdc++.h>
#define ll long long int
#define INF 1e9
#define lINF 1e18
const int MOD = 1e9+7;
using namespace std;

vector<vector<int>> prefix2D(int N, int M, const vector<vector<int>> &grid){
	vector<vector<int>> results(N,vector<int>(M,0)); 
    results[0][0] = grid[0][0]; 
    for (int i = 1; i < M; i++) 
        results[0][i] = results[0][i - 1] + grid[0][i]; 
    for (int i = 1; i < N; i++) 
        results[i][0] = results[i - 1][0] + grid[i][0]; 

    for (int i = 1; i < N; i++) { 
        for (int j = 1; j < M; j++) {
			results[i][j] = results[i - 1][j] + results[i][j - 1] - results[i - 1][j - 1] + grid[i][j]; 
		} 
    }
    return results;
}
int getSum(const vector<vector<int>> &results, int r1, int c1, int r2, int c2) {
    int sum = results[r2][c2];

    if (r1 > 0)
        sum -= results[r1 - 1][c2];
    if (c1 > 0)
        sum -= results[r2][c1 - 1];
    if (r1 > 0 && c1 > 0)
        sum += results[r1 - 1][c1 - 1];

    return sum;
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
	int t = 1;
	while(T--){
		int N,M,K,A,B;
		cin >> N >> M >> K >> A >> B;
		vector<vector<int>> grid(N,vector<int>(M,0));
		for(int i = 0; i < K; i++){
			int a,b;
			cin >> a >> b;
			grid[a][b]++;
		}
		auto res = prefix2D(N,M,grid);
		int mini = INF;
		for(int i = 0; i+A <= N; i++){
			for(int j = 0; j+B <= M; j++){
				mini = min(mini,getSum(res,i,j,i+A-1,j+B-1));
			}
		}
		cout << "Case #" << t << ": " << mini << "\n";
		t++;
	}
	return 0;
}
