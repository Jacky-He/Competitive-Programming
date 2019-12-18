#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int n, m;
int num;
ll grid [505][505];

int main ()
{
    scanf ("%d%d", &n, &m);
    memset (grid, 0x3f, sizeof (grid));
    grid [0][1] = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            scanf ("%d", &num);
            grid [x][y] = min (grid [x - 1][y], grid [x][y - 1]) + num;
        }
    }
    printf ("%lld\n", grid [n][m]);
    return 0;
}
