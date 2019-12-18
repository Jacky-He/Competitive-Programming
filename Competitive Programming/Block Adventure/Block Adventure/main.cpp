#include <bits/stdc++.h>
using namespace std;

int testcases;
int n, m, k;
int height [103];


bool possible ()
{
    for (int x = 0; x < n - 1; x++)
    {
        if (height [x]+m+k < height [x + 1])
        {
            return false;
        }
        m += height [x] - max((height [x + 1] - k), 0);
    }
    return true;
}

int main ()
{
    scanf ("%d", &testcases);
    while (testcases--)
    {
        scanf ("%d%d%d", &n, &m, &k);
        for (int x = 0; x < n; x++)
        {
            scanf ("%d", &height [x]);
        }
        if (possible ())
        {
            printf ("YES\n");
        }
        else
        {
            printf ("NO\n");
        }
    }
    return 0;
}
