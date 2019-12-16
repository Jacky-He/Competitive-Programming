#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 1000006
using namespace std;
typedef long long int ll;

int n;
ll num, p;
int bit [MAXN];
ll nums [MAXN];
vector <ll> sorts;

int query (int index)
{
    int res = 0;
    while (index > 0)
    {
        res += bit [index];
        index -= index&(-index);
    }
    return res;
}

void update (int index, int delta)
{
    while (index <= n)
    {
        bit [index] += delta;
        index += index&(-index);
    }
}

int main ()
{
    ll res = 0;
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &nums [x]);
    }
    scanf ("%lld", &p);
    sorts.push_back(0);
    for (int x = 1; x <= n; x++)
    {
        nums [x] -= p;
        nums [x] += nums [x - 1];
        sorts.push_back(nums [x]);
    }
    sort (sorts.begin(), sorts.end());
    for (int x = 1; x <= n; x++)
    {
        nums [x] = lower_bound (sorts.begin(), sorts.end(), nums [x]) - sorts.begin() + 1;
    }
    update ((int)(lower_bound (sorts.begin(), sorts.end(), 0) - sorts.begin() + 1), 1);
    for (int x = 1; x <= n; x++)
    {
        res += query ((int)nums[x]);
        update ((int)nums[x], 1);
    }
    printf ("%lld\n", res);
    return 0;
}
