#include <bits/stdc++.h>
using namespace std;

int n, num;
double missions [21][21]; //bond, mission
double dp [(1 << 20)]; //missions

double solve (int mask)
{
    if (dp [mask] >= 0)
    {
        return dp [mask];
    }
    int numones = __builtin_popcount (mask);
    if (numones == 0)
    {
        return 1;
    }
    double result = 0;
    for (int x = 0; x < n; x++)
    {
        if ((mask >> x)&1)
        {
            result = max (result, missions [numones - 1][x]*solve (mask&(~(1 << x))));
        }
    }
    return dp [mask] = result;
}

int main ()
{
    scanf ("%d", &n);
    memset (dp, -1.0, sizeof (dp));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            scanf ("%d", &num);
            missions [x][y] = num/100.0;
        }
    }
    printf ("%f\n", solve ((1 << n) - 1)*100);
    return 0;
}
