#include <bits/stdc++.h>
using namespace std;
int n, k;
int temp;
int attractions [1000003];
int maxforward [1000003];
int maxbackward [1000003];
int main ()
{
    scanf ("%d%d", &n, &k);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &temp);
        attractions [x] = temp;
        maxforward [x] = max (maxforward [x - 1], temp);
    }
    for (int x = n; x > 0; x--)
    {
        maxbackward [x] = max (maxbackward [x + 1], attractions [x]);
    }
    int result = 0;
    if (k == n)
    {
        printf ("%d\n", maxforward [n]);
        return 0;
    }
    for (int x = n - k; x <= k; x++)
    {
        result = max (result, maxforward [x] + maxbackward [x + 1]);
    }
    printf ("%d\n", result);
    return 0;
}