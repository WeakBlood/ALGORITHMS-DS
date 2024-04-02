#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif

    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) cin >> arr[i];
    if(N == 1)
    {
        cout << arr[0]*2 << "\n";
        return 0;
    }
    sort(arr.begin(),arr.end());
    int l = -1;
    int r = N;
    ll sumL = 0;
    ll sumR = 0;
    ll intersection = 0;
    while(l < r)
    {
        if(sumL <= sumR)
        {
            l++;
            if(l == r) 
            {
                intersection = arr[r] - sumL < 0 ? 0:arr[r] - sumL;
                break;
            }
            sumL+=arr[l];
        }
        else
        {
            r--;
            if(l == r) 
            {
                intersection = arr[r] - sumL < 0 ? 0:arr[r] - sumL;
                break;
            }
            sumR+=arr[r];
        }
    }

    cout << sumL + sumR + intersection << "\n";
    return 0;
}