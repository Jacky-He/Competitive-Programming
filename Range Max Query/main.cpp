#include <bits/stdc++.h>
using namespace std;

int n, m, num, from, to;
int sparse [100005][17];

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        sparse [x][0] = num;
    }
    for (int y = 1; (1 << y) <= n; y++)
    {
        for (int x = 0; x + (1 << y) <= n; x++)
        {
            sparse [x][y] = max (sparse [x][y - 1], sparse [x + (1 << (y - 1))][y - 1]);
        }
    }
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d", &from, &to);
        from--;
        to--;
        int k = (int)log2(to - from + 1);
        printf ("%d\n", max (sparse [from][k], sparse [to - (1 << k) + 1][k]));
    }
    return 0;
}


