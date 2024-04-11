/* WeakBlood <3 */
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;

#define g __gnu_cxx::
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    g crope arr;
    int N;
    g crope separator('|');
    for(int i = 0; i < N; i++)
    {
        string s; cin >> s;
        arr = arr + separator + g crope(s.c_str());
    }
    arr = arr + separator;
    return 0;
}