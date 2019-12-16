#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int n;
int pillars [1000003];
ll total = 0;
int maxn = 0, maxi = 0;
int main ()
{
    scanf ("%d", &n);
    if (n == 1)
    {
        scanf ("%d", &n);
        printf ("%d", 0);
        return 0;
    }
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &pillars [x]);
        if (pillars [x] >= maxn)
        {
            maxn = pillars [x];
            maxi = x;
        }
    }
    int left = 0;
    int right = 1;
    for (int x = 0; x <= maxi; x++)
    {
        if (pillars [right] >= pillars [left])
        {
            for (int y = left + 1; y < right; y++)
            {
                total += pillars [left] - pillars [y];
            }
            left = right;
        }
        right++;
    }
    left = n - 1;
    right = n - 2;
    for (int x = n - 1; x >= maxi; x--)
    {
        if (pillars [right] <= pillars [left])
        {
            for (int y = left + 1; y < right; y++)
            {
                total += pillars [right] - pillars [y];
            }
            right = left;
        }
        left--;
    }
    printf ("%lld\n", total);
    return 0;
}
