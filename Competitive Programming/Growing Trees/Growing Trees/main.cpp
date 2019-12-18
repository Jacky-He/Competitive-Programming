#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
pair <int, int> trees [1000]; //first: height, second: rate
int n;
int sameHeight (pair <int, int> t1, pair <int, int> t2)
{
    if (t1.first == t2.first)
    {
        return 0;
    }
    int difference = t1.first - t2.first; // speed difference has to be opposite in sign
    int speedDifference = t1.second - t2.second;
    if (speedDifference == 0)
    {
        return INF;
    }
    if ((difference < 0 ^ speedDifference < 0) && (difference % speedDifference == 0))
    {
        return abs(difference / speedDifference);
    }
    return INF;
}
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d%d", &trees [x].first, &trees [x].second);
    }
    int result = INF;
    for (int x = 0; x < n; x++)
    {
        for (int y = x + 1 ; y < n; y++)
        {
            result = min (result, sameHeight (trees [x], trees [y]));
        }
    }
    printf ("%d\n", result == INF? -1:result);
    return 0;
}
