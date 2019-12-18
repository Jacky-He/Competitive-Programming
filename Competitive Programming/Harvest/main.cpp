#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long int ll;
ll psa [200002];
ll row, col, k;
ll a, b;
ll dp [200002];
int main ()
{
    scanf ("%lld%lld%lld", &row, &col, &k);
    for (int x = 0; x < col; x++)
    {
        scanf ("%lld%lld", &a, &b);
        psa [a]--;
        psa [b + 1]++;
    }
    psa [0] = col;
    for (int y = 0; y < 2; y++)
    {
        for (int x = 1; x <= row; x++)
        {
            psa[x] = psa[x] + psa[x - 1];
        }
        psa [0] = 0;
    }
    memset (dp, 0x3f, sizeof (dp));
    ll i = 1, j = 1;
    ll ans = INF;
    while (i <= row && j <= row)
    {
        if (psa [i] - psa [j - 1] >= k)
        {
            dp [i] = min (i - j + 1, dp [i - 1] + 1);
            j++;
        }
        else
        {
            i++;
        }
        ans = min (ans, dp [i]);
    }
    printf ("%lld\n", ans == INF? -1:ans);
    return 0;
}