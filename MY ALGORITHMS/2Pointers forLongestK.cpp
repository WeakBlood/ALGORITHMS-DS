/* WeakBlood <3 */
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif

    int N,K;
    cin >> N >> K;
    int l = 1;
    map<int,int> mappa;

    int diff = 0;
    int bigL = 1,bigR = 1;
    int arr[N+1];
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        int num = arr[i];
        if(mappa[num] == 0)
        {
            while(diff == K && l <= i)
            {
                mappa[arr[l]]--;
                if(!mappa[arr[l]]) diff--;
                l++;
            }
            diff++;
        }
        mappa[num]++;
        if(i - l > bigR - bigL)
        {
            bigR = i;
            bigL = l;
        }
    }

    cout << bigL << " " << bigR;
    return 0;
}