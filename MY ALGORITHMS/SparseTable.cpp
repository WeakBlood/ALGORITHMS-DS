#include <bits/stdc++.h>

using namespace std;

struct SparseTable{
    vector<vector<int>> table;
    vector<vector<int>> id;
    SparseTable(int N,const vector<int> &arr)
    {
        int log = log2(N) + 1;
        table.resize(N,vector<int> (log));
        id.resize(N,vector<int> (log));
        for(int i = 0; i < N; i++)
        {   
            table[i][0] = arr[i];
            id[i][0] = i;
        } 

        for(int j = 1; j < log; ++j)
        {
            for(int i = 0; i + (1 << j) <= N; i++)
            {
                if(table[i][j-1] < table[i + (1 << (j-1))][j-1])
                {
                    table[i][j] = table[i][j-1];
                    id[i][j] = id[i][j-1];
                }
                else
                {
                    table[i][j] =  table[i + (1 << (j-1))][j-1];
                    id[i][j] =  id[i + (1 << (j-1))][j-1];
                }
            }
        }
    }
    int query(int l, int r)
    {
        int j = log2(r - l + 1);
        if(table[l][j] < table[r - (1 << j) + 1][j])
        {
            return id[l][j];
        }
        else
        {
            return id[r - (1 << j) + 1][j];
        }
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

    SparseTable sparse(N,vet);
    while(Q--)
    {
        int l,r;
        cin >> l >> r;
        l--; r--;
        cout << vet[sparse.query(l,r)] << "\n";
    }
    return 0;
}