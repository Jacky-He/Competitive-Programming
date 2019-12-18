#include <bits/stdc++.h>
using namespace std;

int dp [202][202];
int n;
int arr [202];

int solve (int from, int to)
{
    if (from > to)
    {
        return 0;
    }
    if (dp [from][to] != 0)
    {
        return dp [from][to];
    }
    if (from == to)
    {
        return dp [from][to] = arr [from - 1] + arr [from] + arr [from + 1];
    }
    int sum = arr [from - 1] + arr [to + 1];
    for (int k = from; k <= to; k++)
    {
        dp [from][to] = max (dp [from][to], sum + arr [k] + solve (from, k - 1) + solve (k + 1, to));
    }
    return dp [from][to];
}

int main()
{
    scanf ("%d", &n);
    while (n != 0)
    {
        for (int x = 0; x < 202; x++)
        {
            memset (dp [x], 0, sizeof (dp [x]));
        }
        for (int x = 1; x <= n; x++)
        {
            scanf ("%d", &arr [x]);
        }
        printf ("%d\n", solve (2, n - 1));
        scanf ("%d", &n);
    }
    return 0;
}