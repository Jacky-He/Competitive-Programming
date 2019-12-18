#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int n, stone;
ll dp [100001];
int stones [100001];
int main ()
{
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &stone);
        stones [x] = stone;
    }
    for (int x = 2; x <= n; x++)
    {
        if (x == 2)
        {
            dp [x] = dp [x - 1] + abs (stones [x] - stones [x - 1]);
        }
        else
        {
            dp [x] = min (dp [x - 1] + abs(stones [x] - stones [x - 1]), dp [x - 2] + abs (stones [x] - stones [x - 2]));
        }
    }
    printf ("%lld\n", dp [n]);
    return 0;
}
