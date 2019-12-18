#include <bits/stdc++.h>
#define MOD 998244353
typedef long long int ll;
using namespace std;
ll n, item;
ll dp [2001][2001]; //items, books
ll mod (ll a) {return a%MOD < 0? a%MOD + MOD: a%MOD;}
int main ()
{
    for (int x = 0; x < 2001; x++)
    {
        dp [x][0] = 1;
    }
    scanf ("%lld", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &item);
        for (int y = 1; y <= n; y++)
        {
            dp [x][y] = mod(mod(dp [x - 1][y - 1]*item) + dp [x - 1][y]);
        }
    }
    for (int x = 1; x <= n; x++)
    {
        printf ("%lld ", dp [n][x]);
    }
    return 0;
}
