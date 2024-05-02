/* WeakBlood <3 */
//Penso di non aver mai failato così tante ds in vita mia Del Fiore
#include <bits/stdc++.h>
#define ll long long int
#define INF 1e9
#define lINF 1e18
const int MOD = 1e9+7;
using namespace std;

class SqrtDecomposition {
private:
    vector<int> arr;
    vector<int> block_max;
    int blk_size;

public:
    SqrtDecomposition(const std::vector<int>& input) 
	{
        arr = input;
        int n = arr.size();
        blk_size = sqrt(n);
        block_max.assign((n + blk_size - 1) / blk_size, INT_MIN);
        for (int i = 0; i < n; ++i) 
		{
            block_max[i / blk_size] = max(block_max[i / blk_size], arr[i]);
        }
    }

    void update(int idx, int value) 
	{
        int block_idx = idx / blk_size;
        arr[idx] = value;
        block_max[block_idx] = INT_MIN;

        int start = block_idx * blk_size;
        int end = min((block_idx + 1) * blk_size, (int)arr.size());

        for (int i = start; i < end; ++i) {
            block_max[block_idx] = max(block_max[block_idx], arr[i]);
        }
    }

	int leftMost(int l, int r, int target) {
	    int N = arr.size();
	    int start_block = l / blk_size;
	    int end_block = r / blk_size;
	
	    if (start_block == end_block) {
	        for (int i = l; i <= r; ++i) {
	            if (arr[i] > target) return i;
	        }
	    } else {
	    	
	        int end_of_first_block = std::min((start_block + 1) * blk_size - 1, N - 1);
	        for (int i = l; i <= end_of_first_block; ++i) {
	            if (arr[i] > target) return i;
	        }
	        
	        for (int i = start_block + 1; i < end_block; ++i) {
	            if (block_max[i] > target) {
	                int start_index = i * blk_size;
	                int end_index = min((i + 1) * blk_size - 1, N - 1);
	                for (int j = start_index; j <= end_index; j++) {
	                    if (arr[j] > target) return j;
	                }
	            }
	        }
	        
	        int start_of_last_block = end_block * blk_size;
	        for (int i = start_of_last_block; i <= r; ++i) {
	            if (arr[i] > target) return i;
	        }
	    }
	    return N-1;
	}
	int rightMost(int l, int r, int target) {
	    int N = arr.size();
	    int start_block = l / blk_size;
	    int end_block = r / blk_size;
	
	    if (start_block == end_block) {
	        for (int i = r; i >= l; --i) {
	            if (arr[i] > target) return i;
	        }
	    } else {
	        int end_of_first_block = std::min((start_block + 1) * blk_size - 1, N - 1);
	        int start_of_last_block = end_block * blk_size;
	        for (int i = r; i >= start_of_last_block; --i) {
	            if (arr[i] > target) return i;
	        }
	        for (int i = end_block - 1; i >= start_block + 1; --i) {
	            if (block_max[i] > target) {
	                int start_index = i * blk_size;
	                int end_index = min((i + 1) * blk_size - 1, N - 1);
	                for (int j = end_index; j <= start_index; j++) {
	                    if (arr[j] > target) return j;
	                }
	            }
	        }
	        for (int i = end_of_first_block; i >= l; --i) {
	            if (arr[i] > target) return i;
	        }
	    }
	    return 0;
	}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N,Q;
    cin >> N >> Q;
    vector<int> vet(N);
    for(int i = 0; i < N; i++) cin >> vet[i];
    
    SqrtDecomposition comply(vet);
    while(Q--)
    {
    	char type;
    	int a;
    	cin >> type >> a;
    	if(type == 'Q')
		{
			cout << comply.rightMost(0,a,vet[a]) << " " << comply.leftMost(a,N-1,vet[a]) << "\n";
		} 
    	else
    	{
    		int b;
    		cin >> b;
    		vet[a] = b;
    		comply.update(a,b);
		}
	}
    return 0;
}
