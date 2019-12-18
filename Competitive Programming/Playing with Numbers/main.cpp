#include <bits/stdc++.h>
#define MAXN 400005
using namespace std;

struct s {
    int l; int r; int max; int ll; int lr; int rr; int rl;
};

s tree [4*MAXN + 4];
int elements [MAXN];
int n, q, num, a, b;

void push_up (int index)
{
    if (tree [index].l == tree [index].r) {return;}
    if (tree [index*2].ll == tree [index*2].rl && tree [index*2].lr == tree [index*2].rr)
    {
        if (elements [tree [index*2].rr] <= elements [tree [index*2 + 1].ll])
        {
            tree [index].max = max(max (tree [index*2].max, tree [index*2 + 1].max), tree [index*2 + 1].lr - tree [index*2].rl + 1);
            tree [index].ll = tree[index*2].ll;
            tree [index].lr = tree [index*2 + 1].lr;
            if (tree [index*2 + 1].lr == tree [index*2 + 1].rr)
            {
                tree [index].rr = tree [index*2 + 1].rr;
                tree [index].rl = tree [index*2].ll;
            }
            else
            {
                tree [index].rr = tree [index*2 + 1].rr;
                tree [index].rl = tree [index*2 + 1].rl;
            }
        }
        else
        {
            tree [index].ll = tree [index*2].ll;
            tree [index].lr = tree [index*2].lr;
            tree [index].rr = tree [index*2 + 1].rr;
            tree [index].rl = tree [index*2 + 1].rl;
            tree [index].max = max (tree [index*2].max, tree [index*2 + 1].max);
        }
    }
    else
    {
        if (elements [tree [index*2].rr] <= elements [tree [index*2 + 1].ll])
        {
            tree [index].max = max(max (tree [index*2].max, tree [index*2 + 1].max), tree [index*2 + 1].lr - tree [index*2].rl + 1);
            tree [index].ll = tree [index*2].ll;
            tree [index].rr = tree [index*2 + 1].rr;
            if (tree [index*2 + 1].lr == tree [index*2 + 1].rr)
            {
                tree [index].rl = tree [index*2].rl;
                tree [index].lr = tree [index*2].lr;
            }
            else
            {
                tree [index].lr = tree [index*2].lr;
                tree [index].rl = tree [index*2 + 1].rl;
            }
        }
        else
        {
            tree [index].ll = tree [index*2].ll;
            tree [index].lr = tree [index*2].lr;
            tree [index].rr = tree [index*2 + 1].rr;
            tree [index].rl = tree [index*2 + 1].rl;
            tree [index].max = max (tree [index*2].max, tree [index*2 + 1].max);
        }
    }
}

void update (int index, int left, int right, int newele)
{
    if (tree [index].l > right || tree [index].r < left)
    {
        return;
    }
    if (tree [index].r <= right && tree [index].l >= left)
    {
        return;
    }
    update (index*2, left, right, newele);
    update (index*2 + 1, left, right, newele);
    push_up (index);
}

void init (int index, int left, int right)
{
    tree [index].l = left;
    tree [index].r = right;
    if (left == right)
    {
        scanf ("%d", &num);
        elements [left] = num;
        tree [index].max = 1;
        tree [index].ll = tree [index].lr = tree [index].rr = tree [index].rl = left;
        return;
    }
    int mid = (left + right)/2;
    init (index*2, left, mid);
    init (index*2 + 1, mid + 1, right);
    push_up(index);
}



int main ()
{
    scanf ("%d%d", &n, &q);
    init (1, 1, n);
    printf("%d\n", tree [1].max);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d%d", &a, &b);
        elements [a] = b;
        update (1, a, a, b);
        printf ("%d\n", tree [1].max);
    }
    return 0;
}
