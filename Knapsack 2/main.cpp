#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
typedef long long int ll;
using namespace std;
int n, w;
int weight, value;
pair <int, int> costs [101];
int dp [100001];
int main ()
{
    scanf ("%d%d", &n, &w);
    int sum = 0;
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d%d", &weight, &value);
        costs [x] = {weight, value};
        sum += value;
    }
    memset (dp, 0x3f, sizeof (dp));
    dp [0] = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = sum; y >= costs [x].second; y--)
        {
            if (dp [y - costs [x].second] != INF)
            {
                dp [y] = min (dp [y - costs [x].second] + costs [x].first, dp [y]);
            }
        }
    }
    for (int x = sum; x >= 0; x--)
    {
        if (dp [x] <= w)
        {
            printf ("%d\n", x);
            return 0;
        }
    }
    return 0;
}
