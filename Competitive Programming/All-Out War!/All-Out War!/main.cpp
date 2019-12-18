#include <bits/stdc++.h>
#define MAXN 30004
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long int ll;

ll lazy [5*MAXN + 10];
int lo [5*MAXN + 10];
int hi [5*MAXN + 10];
ll mini [5*MAXN + 10];

int n, q, a, b;
ll c;

void push_up (int index)
{
    mini [index] = min (mini [index*2], mini [index*2 + 1]);
}

void push_down (int index)
{
    lazy [index*2] += lazy [index];
    lazy [index*2 + 1] += lazy [index];
    mini [index] -= lazy [index];
    lazy [index] = 0;
}

void update (int left, int right, int index, ll delta)
{
    if (lo [index] > right || hi [index] < left)
    {
        push_down (index);
        return;
    }
    if (lo [index] >= left && hi [index] <= right)
    {
        lazy [index] += delta;
        push_down (index);
        return;
    }
    push_down (index);
    update (left, right, index*2, delta);
    update (left, right, index*2 + 1, delta);
    push_up (index);
}

ll query (int left, int right, int index)
{
    if (lo [index] > right || hi [index] < left)
    {
        push_down (index);
        return INF;
    }
    if (lo [index] >= left && hi [index] <= right)
    {
        push_down (index);
        return mini [index];
    }
    push_down (index);
    ll res = min(query (left, right, index*2), query (left, right, index*2 + 1));
    push_up (index);
    return res;
}

void init (int left, int right, int index)
{
    lo [index] = left;
    hi [index] = right;
    if (left == right)
    {
        scanf ("%lld", &mini [index]);
        return;
    }
    int mid = (left + right)/2;
    init (left, mid, index*2);
    init (mid + 1, right, index*2 + 1);
    push_up (index);
}

int main ()
{
    scanf ("%d%d", &n, &q);
    init (1, n, 1);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d%d%lld", &a, &b, &c);
        update (a, b, 1, c);
        ll res = query (a, b, 1);
        ll res2 = query (1, n, 1);
        printf ("%lld %lld\n", res < 0? 0 : res, res2 < 0? 0 : res2);
    }
    return 0;
}


