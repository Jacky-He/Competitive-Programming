#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll n;
ll dp [30000006];

ll w (ll num)
{
    if (num == 0)
    {
        return 0;
    }
    if (num == 1)
    {
        return 1;
    }
    if (num < 30000006 && dp [num] != 0)
    {
        return dp [num];
    }
    ll cnt = num - num/2;
    ll root = (ll) sqrt (num);
    pair <ll, ll> prev = {0, 0};
    for (int k = 2; k <= root; k++)
    {
        cnt += w (num/k);
        if (k == root)
        {
            cnt += (num/k - root) * w (k);
        }
        cnt += (prev.second - num/k) * w (prev.first);
        prev = {k, num/k};
    }
    if (num < 30000006)
    {
        return dp [num] = cnt;
    }
    return cnt;
}
int main ()
{
    scanf ("%lld", &n);
    printf ("%lld\n", w(n));
    return 0;
}
