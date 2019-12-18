#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long int ll;

int n, q, s, t, d;
ll num;
ll dp [105][105][105]; //first: days, second: source, third: dest

int main ()
{
    scanf ("%d", &n);
    memset (dp, 0x3f, sizeof (dp));
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf ("%lld", &num);
            if (num != 0)
            {
                dp [1][x][y] = num;
            }
        }
    }
    
    for (int x = 1; x <= n; x++)
    {
        dp [1][x][x] = 0;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp [1][i][j] = min (dp [1][i][j], dp [1][i][k] + dp [1][k][j]);
            }
        }
    }
    
    
    for (int day = 2; day <= n; day++)
    {
        for (int source = 1; source <= n; source++)
        {
            for (int dest = 1; dest <= n; dest++)
            {
                for (int node = 1; node <= n; node++)
                {
                    dp [day][source][dest] = min (dp [day][source][dest], max(dp [day - 1][source][node], dp [1][node][dest]));
                }
            }
        }
    }
    scanf ("%d", &q);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d%d%d", &s, &t, &d);
        printf ("%lld\n", dp [d][s][t] == INF? 0 : dp [d][s][t]);
    }
    return 0;
}
/*
3
0 1 4
0 0 1
0 1 0
4
1 3 1
1 2 2
3 1 2
3 1 1


*/

