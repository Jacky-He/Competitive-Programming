#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, k;
int values [201];
int numleft [201];
pair <int, int>* dp1 = new pair <int, int> [20001];
pair <int, int>* dp2 = new pair <int, int> [20001];
pair <int, int> cmp (pair <int, int> p1, pair <int, int> p2, int num)
{
    if (p1.second > num && p2.second > num)
    {
        return {INF, INF};
    }
    if (p2.second > num)
    {
        return p1;
    }
    if (p1.second > num)
    {
        return p2;
    }
    return min (p1, p2);
}
int main ()
{
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &values [x]);
    }
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &numleft [x]);
    }
    scanf ("%d", &k);
    for (int x = 1; x <= k; x++)
    {
        dp1 [x] = {INF, 0};
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= k; y++)
        {
            if (y - values [x] >= 0)
            {
                pair <int, int> p1, p2, p3;
                p1 = dp2 [y - values [x]];
                p1.first++;
                p1.second++;
                p2 = dp1 [y - values [x]];
                p2.first++;
                p2.second = 1;
                p3 = dp1 [y];
                p3.second = 0;
                dp2 [y] = cmp(cmp (p1, p2, numleft [x]), p3, numleft [x]);
            }
            else
            {
                dp2 [y] = dp1 [y];
                dp2 [y].second = 0;
            }
        }
        pair <int, int>* pt = dp1;
        dp1 = dp2;
        dp2 = pt;
    }
    printf ("%d\n", dp1 [k].first);
    return 0;
}