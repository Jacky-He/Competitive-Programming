#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n;
pair <int, int> ingredients [10];
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d%d", &ingredients [x].first, &ingredients [x].second);
    }
    int result = INF;
    for (int x = 1; x <= (1 << n) - 1; x++)
    {
        int product = 1, sum = 0;
        for (int y = x, cnt = 0; y != 0; y >>= 1, cnt++)
        {
            if (y&1)
            {
                product *= ingredients [cnt].first;
                sum += ingredients [cnt].second;
            }
        }
        result = min ((int)result, abs (product - sum));
    }
    printf ("%d\n", result);
    return 0;
}
