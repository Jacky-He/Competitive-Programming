#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr [100001];
int n, m;
ll bsearch (ll a, int index)
{
    int lo = index + 1; int hi = n - 1;
    if (lo > hi)
    {
        return -1;
    }
    while (lo + 1 < hi)
    {
        int mid = (lo + hi)/2;
        if (arr[mid] + a > m)
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    if (arr[hi] + a <= m)
    {
        return hi;
    }
    if (arr[lo] + a <= m)
    {
        return lo;
    }
    return -1;
}
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < n; x++)
    {
        scanf ("%lld", &arr [x]);
    }
    sort (arr, arr + n);
    ll count = 0;
    for (int x = 0; x < n; x++)
    {
        ll temp = bsearch (arr [x], x);
        if (temp != -1)
        {
            count += temp - x;
        }
    }
    printf ("%lld\n", count);
    return 0;
}

