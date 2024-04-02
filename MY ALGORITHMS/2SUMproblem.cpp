#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif

    int N,X;

    cin >> N >> X;
    vector<pair<int,int>> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(),arr.end());


    int l = 0;
    int r = N - 1;

    while(l < r)
    {
        if(arr[l].first + arr[r].first < X) l++;
        else if(arr[l].first + arr[r].first > X) r--;
        else
        {
            cout << arr[l].second+1 << " " << arr[r].second+1 << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}