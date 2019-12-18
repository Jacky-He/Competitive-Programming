#include <bits/stdc++.h>
using namespace std;

int n, m, from, to;
pair <int, int> sparse [50005][17];
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &sparse [x][0].first);
        sparse [x][0].second = sparse[x][0].first;
    }
    for (int x = 1; (1 << x) <= n; x++)
    {
        for (int y = 0; y + (1 << x) <= n; y++)
        {
            sparse [y][x].first = max (sparse [y][x - 1].first, sparse [y + (1 << (x - 1))][x - 1].first);
            sparse [y][x].second = min (sparse [y][x - 1].second, sparse [y + (1 << (x - 1))][x - 1].second);
        }
    }
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d", &from, &to);
        from--;
        to--;
        int k = (int)log2 (to - from + 1);
        printf ("%d\n", max (sparse [from][k].first, sparse [to - (1 << k) + 1][k].first)-min (sparse [from][k].second, sparse [to - (1 << k) + 1][k].second));
    }
    return 0;
}
