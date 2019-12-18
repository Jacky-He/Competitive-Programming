#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct s
{
    ll l = 0, r = 0, sum = 0, lazy = 0;
};
int m, n, q, operation, first, second;
ll change;
s tree [800004];
ll arr [200002];
void push_down (int index)
{
    tree [index*2].lazy = (tree [index*2].lazy + tree [index].lazy)%m;
    tree [index*2 + 1].lazy = (tree [index*2 + 1].lazy + tree [index].lazy)%m;
    tree [index].sum = (tree [index].sum + (tree [index].lazy*((tree [index].r - tree [index].l + 1)%m))%m)%m;
    tree [index].lazy = 0;
}
void push_up (int index)
{
    ll temp1 = (tree [index*2].lazy*((tree [index*2].r - tree [index*2].l + 1)%m))%m;
    ll temp2 = (tree [index*2 + 1].lazy*((tree [index*2 + 1].r - tree [index*2 + 1].l + 1)%m))%m;
    tree [index].sum = ((tree [index*2].sum + tree [index*2 + 1].sum)%m + (temp1 + temp2)%m)%m;
}
ll query  (int index, int left, int right)
{
    if (tree [index].l > right || tree [index].r < left)
    {
        return 0;
    }
    if (tree [index].l >= left && tree [index].r <= right)
    {
        return (tree [index].sum + (tree [index].lazy*((tree [index].r - tree [index].l + 1)%m))%m)%m;
    }
    push_down (index);
    return (query (index*2, left, right) + query (index*2 + 1, left, right))%m;
}
void update (int index, int left, int right, ll delta)
{
    if (tree [index].l > right || tree [index].r < left)
    {
        return;
    }
    if (tree [index].l >= left && tree [index].r <= right)
    {
        tree [index].lazy = (delta + tree [index].lazy)%m;
        return;
    }
    push_down (index);
    update (index*2, left, right, delta);
    update (index*2 + 1, left, right, delta);
    push_up (index);
}
void init (int index, int left, int right)
{
    tree [index].l = left;
    tree [index].r = right;
    if (left == right)
    {
        scanf ("%lld", &tree [index].sum);
        tree [index].sum %= m;
        return;
    }
    int mid = (left + right)/2;
    init (index*2, left, mid);
    init (index*2 + 1, mid + 1, right);
    tree [index].sum = (tree [index*2].sum + tree [index*2 + 1].sum)%m;
}
int main ()
{
    scanf ("%d%d%d", &m, &n, &q);
    init (1, 1, n);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d", &operation);
        if (operation == 1)
        {
            scanf ("%d%d%lld", &first, &second, &change);
            update (1, first, second, change);
        }
        else if (operation == 2)
        {
            scanf ("%d%d", &first, &second);
            printf ("%lld\n", query (1, first, second));
        }
    }
    return 0;
}
/*
2 5 3
1 2 3 4 5
2 1 4
1 2 5 7
2 1 5

*/
