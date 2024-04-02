#include <bits/stdc++.h>

using namespace std;

struct Value{
    int v,idx;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N;
    cin >> N;
    stack<Value> s;
    int num;
    cin >> num;
    s.push({num,1});
    cout << 0 << " ";
    for(int i = 1; i < N; i++)
    {
        cin >> num;
        while(!s.empty() && s.top().v >= num) s.pop();
        if(!s.empty()) cout << s.top().idx << " ";
        else cout << 0 << " ";
        s.push({num,i+1});
    }
    return 0;
}