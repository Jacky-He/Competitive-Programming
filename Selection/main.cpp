#include <bits/stdc++.h>
#define MAXN 300004
using namespace std;

struct s {
    int l; int r; int cnt [22];
};
s tree [MAXN*4];

int n, m;
int op, a, b, c;

void push_up (int index)
{
    if (tree [index].l == tree [index].r) {return;}
    for (int x = 0; x < 22; x++)
    {
        tree [index].cnt [x] = tree [index*2].cnt [x] + tree [index*2 + 1].cnt [x];
    }
}

void init (int index, int left, int right)
{
    tree [index].l = left;
    tree [index].r = right;
    if (left == right)
    {
        int num;
        scanf ("%d", &num);
        memset (tree [index].cnt, 0, sizeof (tree [index].cnt));
        tree [index].cnt [num]++;
        return;
    }
    int mid = (left + right)/2;
    init (index*2, left, mid);
    init (index*2 + 1, mid + 1, right);
    push_up (index);
}

void update (int index, int left, int right, int newval)
{
    if (tree [index].l > right || tree [index].r < left)
    {
        return;
    }
    if (tree [index].l >= left && tree [index].r <= right)
    {
        memset (tree [index].cnt, 0, sizeof (tree [index].cnt));
        tree [index].cnt [newval]++;
        return;
    }
    update (index*2, left, right, newval);
    update (index*2 + 1, left, right, newval);
    push_up(index);
}

int excnt [22];

void query (int index, int left, int right)
{
    if (tree [index].l > right || tree [index].r < left)
    {
        return;
    }
    if (tree [index].l >= left && tree [index].r <= right)
    {
        for (int x = 0; x < 22; x++)
        {
            excnt [x] += tree [index].cnt [x];
        }
        return;
    }
    query (index*2, left, right);
    query (index*2 + 1, left, right);
}

int main ()
{
    scanf ("%d%d", &n, &m);
    init (1, 1, n);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d", &op);
        if (op == 1)
        {
            scanf ("%d%d", &a, &b);
            update (1, a, a, b);
        }
        else if (op == 2)
        {
            scanf ("%d%d%d", &a, &b, &c);
            memset (excnt, 0, sizeof (excnt));
            query (1, a, b);
            int goodness = 21;
            while (c > 0)
            {
                c -= excnt [goodness];
                goodness--;
            }
            printf ("%d\n", goodness + 1);
        }
    }
    return 0;
}
