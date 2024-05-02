#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int MAXN = 1e6;
int primes[MAXN+7];
void sieveOf()
{
    for(int x = 2; x <= MAXN; x++)
    {
        if(primes[x]) continue;
        for(int j = x; j <= MAXN; j+=x) primes[j] = x;
    }
}
 
int count(int x)
{
    int div = 1;
    while(x != 1)
    {
        int maxiPrime = primes[x];
        int count = 0;
        while(x % maxiPrime == 0)
        {
            count++;
            x = x / maxiPrime;
        }
        div = div * (count + 1);
    }
    return div;
}
int main()
{
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
 
    int T;
    cin >> T;
    sieveOf();
    while(T--)
    {
        int x;
        cin >> x;
        cout << count(x) << "\n";
    }
    return 0;
}
