#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
struct s
{
    int left, right, freq;
    ll sum;
};
int n, m, operation, from, to;
s tree [400005];
void push_up (int index)
{
    tree [index].sum = tree [index*2].sum + tree [index*2 + 1].sum;
    tree [index].freq = tree [index*2].freq + tree [index*2 + 1].freq;
}
void init (int index, int left, int right)
{
    tree [index].left = left;
    tree [index].right = right;
    if (left == right)
    {
        scanf ("%lld", &tree [index].sum);
        if (tree [index].sum == 1 || tree [index].sum == 0)
        {
            tree [index].freq = 1;
        }
        return;
    }
    int mid = (left + right)/2;
    init (index*2, left, mid);
    init (index*2 + 1, mid + 1, right);
    push_up (index);
}
ll query (int index, int left, int right)
{
    if (tree [index].left > right || tree [index].right < left)
    {
        return 0;
    }
    if (tree [index].left >= left && tree [index].right <= right)
    {
        return tree [index].sum;
    }
    return query (index*2, left, right) + query (index*2 + 1, left, right);
}
void update (int index, int left, int right)
{
    if (tree [index].left > right || tree [index].right < left)
    {
        return;
    }
    if (tree [index].left == tree [index].right)
    {
        tree [index].sum = (int) sqrt(tree [index].sum);
        if (tree [index].sum == 0 || tree [index].sum == 1)
        {
            tree [index].freq = 1;
        }
        return;
    }
    if (tree [index*2].freq < tree [index*2].right - tree [index*2].left + 1)
    {
        update (index*2, left, right);
    }
    if (tree [index*2 + 1].freq < tree [index*2 + 1].right - tree [index*2 + 1].left + 1)
    {
        update (index*2 + 1, left, right);
    }
    push_up (index);
}
int main ()
{
    scanf ("%d", &n);
    init (1, 1, n);
    scanf ("%d", &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d", &operation, &from, &to);
        if (operation == 1)
        {
            printf ("%lld\n", query (1, from, to));
        }
        else if (operation == 2)
        {
            update (1, from, to);
        }
    }
    return 0;
}


