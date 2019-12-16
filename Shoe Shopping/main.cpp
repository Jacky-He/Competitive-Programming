#include <bits/stdc++.h>
using namespace std;
int n;
double dp [10004];
int prices [10004];
int main ()
{
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &prices [x]);
        if (x == 1)
        {
            dp [x] = prices [x];
        }
        else if (x == 2)
        {
            dp [x] = min (prices [x], prices [x - 1])*0.5 + max (prices [x], prices [x - 1]);
        }
        else
        {
            dp [x] = dp [x - 2] + min (prices [x], prices [x - 1])*0.5 + max (prices [x], prices [x - 1]);
            dp [x] = min (dp [x], prices [x] + prices [x - 1] + prices [x - 2] - min(min (prices [x], prices [x - 1]), prices [x - 2]) + dp [x - 3]);
            dp [x] = min (dp [x], prices [x] + dp [x - 1]);
        }
    }
    printf ("%.1f\n", dp [n]);
    return 0;
}
