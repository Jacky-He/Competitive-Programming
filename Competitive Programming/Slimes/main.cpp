#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long int ll;
using namespace std;

ll n, num;
ll dp [404][404];
ll psa [404];

ll solve (int from, int to)
{
    if (from == to)
    {
        return 0;
    }
    if (dp [from][to] != INF)
    {
        return dp [from][to];
    }
    ll sum = psa [to] - psa [from - 1];
    for (int k = from; k < to; k++)
    {
        dp [from][to] = min (dp [from][to], sum + solve (from, k) + solve (k + 1, to));
    }
    return dp [from][to];
}

int main()
{
    scanf ("%lld", &n);
    for (int x = 0; x < 404; x++)
    {
        memset (dp [x], 0x3f, sizeof (dp [x]));
    }
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &num);
        dp [x][x] = 0;
        psa [x] = psa [x - 1] + num;
    }
    printf ("%lld", solve (1, n));
    return 0;
}