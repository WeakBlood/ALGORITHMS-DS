#include <bits/stdc++.h>

using namespace std;
#define ll long long int
vector<vector<ll>> grid;
vector<list<int>> graph;
vector<int> prec;
int N;
ll find_path(int s, int f)
{
    vector<ll> flow(N,0);
    queue<int> q;
    flow[s] = 1 << 30;
    q.push(s);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int u: graph[node])
        {
            if(!flow[u] && grid[node][u])
            {
                flow[u] = min(grid[node][u],flow[node]);
                prec[u] = node;
                q.push(u);
            }
        }
    }
    return flow[f];
}

ll maxFlow(int s, int f)
{
    ll flow = 0;
    ll newFlow = 0;
    prec.resize(N);
    while((newFlow = find_path(s,f)))
    {
        flow+=newFlow;
        int node = f;

        while(node != s)
        {
            int u = prec[node];
            grid[node][u]+=newFlow;
            grid[u][node]-=newFlow;
            node = u;
        }
    }
    return flow;
}
int main()
{
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int M;
    cin >> N >> M;
    grid.resize(N,vector<ll> (N,0));
    graph.resize(N);
    for(int i = 0; i < M; i++)
    {
        int src,des,cap;
        cin >> src >> des >> cap;
        src--;des--;
        grid[src][des]+= cap;
        graph[src].push_back(des);
        graph[des].push_back(src);
    }

    cout << maxFlow(0,N-1) << endl;
    return 0;
}