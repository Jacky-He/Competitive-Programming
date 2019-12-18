#include <bits/stdc++.h>
#define LOG 17
using namespace std;

int flowers [5005];
int dp [5005];
int fences [100005];
int sparse [100005][17];
int n, m;

void init ()
{
    for (int x = 0; x < m; x++)
    {
        sparse [x][0] = fences [x];
    }
    for (int y = 1; (1 << y) <= m; y++)
    {
        for (int x = 0; x + (1 << y) - 1 < m; x++)
        {
            sparse [x][y] = min (sparse [x][y - 1], sparse [x + (1 << (y - 1))][y - 1]);
        }
    }
}

int query (int from, int to) //inclusive
{
    int l = to - from + 1;
    int k = (int)log2(l);
    return min (sparse [from][k], sparse [from + l - (1 << k)][k]);
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &flowers [x]);
    }
    for (int x = 0; x < m; x++)
    {
        scanf ("%d", &fences [x]);
    }
    init ();
    memset (dp, 0x3f, sizeof (dp));
    sort (flowers + 1, flowers + n + 1);
    dp [0] = 0;
    for (int x = 1; x <= n; x++)
    {
        int upper = (x == n? m : flowers [x + 1] - 1);
        for (int y = 1; y <= x; y++)
        {
            int lower = (y == 1? 1 : flowers [y - 1] + 1);
            dp [x] = min (dp [x], dp [y - 1] + query(flowers [x] - flowers [y], upper - lower));
        }
    }
    printf ("%d\n", dp [n]);
    return 0;
}
