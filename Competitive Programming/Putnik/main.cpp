#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long int ll;

int n, flighttime;

int dis [1505][1505];
int dp [1505][1505]; //from, to

int main ()
{
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf ("%d", &flighttime);
            dis [x][y] = flighttime;
        }
    }
    memset (dp, 0x3f, sizeof (dp));
    for (int x = 0; x <= n; x++)
    {
        dp [x][x] = 0;
    }
    for (int x = 2; x <= n; x++)
    {
        for (int i = 1; x == 2? i <= x - 1 : i < x - 1; i++)
        {
            dp [x][x - 1] = min (dp [x][x - 1], dis [x][i] + dp [i][x - 1]);
            dp [i][x] = min (dp [i][x], dp [i][x - 1] + dis [x - 1][x]);
            dp [x][i] = min (dp [x][i], dis [x][x - 1] + dp [x - 1][i]);
            dp [x - 1][x] = min (dp [x - 1][x], dp [x - 1][i] + dis [i][x]);
        }
    }
    int res = INF;
    for (int x = 1; x < n; x++)
    {
        res = min(min (res, dp [n][x]), dp [x][n]);
    }
    printf ("%d\n", res);
    return 0;
}
