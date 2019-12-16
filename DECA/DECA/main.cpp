#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll house [1000001];    //index: index, value: house number
ll tree [4000002];
ll delta [4000002];
ll hi [4000002];
ll lo [4000002];
ll l, r, v, check;
int n, q, operation;
void prop (ll index)
{
    delta [index<<1] += delta [index];
    delta [index<<1|1] += delta [index];
    delta [index] = 0;
}
void update (ll index)
{
    tree [index] = tree [index<<1] + delta [index<<1] + tree [index<<1|1] + delta [index<<1|1];
}
void init (ll left, ll right, ll index)
{
    hi [index] = right;
    lo [index] = left;
    if (left == right)
    {
        return;
    }
    ll mid = (left + right)>>1;
    init (left, mid, index<<1);
    init (mid + 1, right, index<<1|1);
}
void increment (ll left, ll right, ll value, ll index)
{
    if (house [hi [index]] < left || house [lo[index]] > right)
    {
        return;
    }
    if (house [hi[index]] <= right && house [lo[index]] >= left)
    {
        delta [index] += value;
        return;
    }
    prop (index);
    increment (left, right, value, index<<1);
    increment (left, right, value, index<<1|1);
    update (index);
}
ll query (ll friends, ll index)
{
    if (hi [index] < friends || lo [index] > friends)
    {
        return 0;
    }
    if (hi [index] == friends && lo [index] == friends)
    {
        return tree [index] + delta [index];
    }
    prop(index);
    ll Left = query (friends, index<<1);
    ll Right = query (friends, index<<1|1);
    update (index);
    return max (Left, Right);
}
int main ()
{
    scanf ("%d%d", &n, &q);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &house [x]);
    }
    init (1, n, 1);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d", &operation);
        if (operation == 1)
        {
            scanf ("%lld%lld%lld", &l, &r, &v);
            increment (l, r, v, 1);
        }
        else if (operation == 2)
        {
            scanf ("%lld", &check);
            printf ("%lld\n", query (check, 1));
        }
    }
    return 0;
}
