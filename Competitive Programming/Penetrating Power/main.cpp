#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long int ll;

struct s {
    ll lazy = 0; ll max; int l; int r;
};
int n, k, q, op;
int a, b;
ll lazy [MAXN*4 + 4];
ll maxi [MAXN*4 + 4];
int l [MAXN*4 + 4];
int r [MAXN*4 + 4];

void push_down (int index)
{
    if(lazy[index] == 0) return;
    if (l[index] == r[index])
    {
        maxi [index] += lazy [index];
        lazy [index] = 0;
        return;
    }
    maxi [index] += lazy [index];
    lazy [index<<1] += lazy [index];
    lazy [(index<<1)|1] += lazy [index];
    lazy [index] = 0;
}

void push_up (int index)
{
    maxi [index] = max (maxi [index<<1], maxi [(index<<1)|1]);
}

void update (int index, int left, int right, int delta)
{
    if (l [index] > right || r[index] < left)
    {
        push_down (index);
        return;
    }
    if (l[index] >= left && r[index] <= right)
    {
        lazy[index] += delta;
        push_down (index);
        return;
    }
    push_down (index);
    update(index*2, left, right, delta);
    update (index*2 + 1, left, right, delta);
    push_up (index);
}

ll query (int index, int left, int right)
{
    if (l[index] > right || r[index] < left)
    {
        push_down (index);
        return 0;
    }
    if (l[index] >= left && r[index] <= right)
    {
        push_down (index);
        return maxi [index];
    }
    push_down (index);
    return max(query (index*2, left, right), query (index*2 + 1, left, right));
}

void init (int index, int left, int right)
{
    l[index] = left;
    r[index] = right;
    if (left == right)
    {
        return;
    }
    int mid = (left + right)/2;
    init (index*2, left, mid);
    init (index*2 + 1, mid + 1, right);
}

int main ()
{
    scanf ("%d%d%d", &n, &k, &q);
    init (1, 0, n);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d%d%d", &op, &a, &b);
        if (op == 0)
        {
            update (1, max (0, a - k + 1), min(a, n), b);
        }
        else if (op == 1)
        {
            int small = min (a, b);
            int big = min(n, max (a, b));
            if (small > n)
            {
                printf ("%d\n", 0);
                continue;
            }
            printf ("%lld\n", query (1, small, min(big, n)));
        }
    }
    return 0;
}

/*
 8 1 8
 0 2 10
 0 0 4
 0 6 15
 1 0 5
 0 3 6
 0 1 3
 1 0 7
 1 1 2
 
 
 
 
 */
