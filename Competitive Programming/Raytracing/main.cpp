#include <bits/stdc++.h>
using namespace std;

int n, num, q, operation, a, b, c, d;
int fenwick [8194][8194];
int arr [8194];

int lowbit (int num)
{
    return num&(-num);
}

void add (int index, int height, int delta)
{
    while (index <= n)
    {
        int temp = height;
        while (temp <= n)
        {
            fenwick [index][temp] += delta;
            temp += lowbit (temp);
        }
        index += lowbit (index);
    }
}

int query (int index, int height)
{
    int sum = 0;
    while (index > 0)
    {
        int temp = height;
        while (temp > 0)
        {
            sum += fenwick [index][temp];
            temp -= lowbit (temp);
        }
        index -= lowbit (index);
    }
    return sum;
}


int main ()
{
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &num);
        add (x, num + 1, 1);
        arr [x] = num + 1;
    }
    scanf ("%d", &q);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d", &operation);
        if (operation == 1)
        {
            scanf ("%d%d%d%d", &a, &b, &c, &d);
            //cout << query (b + 1, d + 1) << "hsidfs" << endl;
            printf ("%d\n", (query (b + 1, d + 1) - query (b + 1, c)) - (query (a, d + 1) - query (a, c)));
        }
        else if (operation == 2)
        {
            scanf ("%d%d", &a, &b);
            int prev = arr [a + 1];
            add (a + 1, prev, -1);
            add (a + 1, b + 1, 1);
            arr [a + 1] = b + 1;
        }
    }
    return 0;
}



