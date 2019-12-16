#include <bits/stdc++.h>
using namespace std;
int n, num;
int dp [4003];
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < 3; x++)
    {
        scanf ("%d", &num);
        dp [num] = max (dp [num], 1);
        for (int y = 1; y <= n; y++)
        {
            if (y - num >= 0 && dp [y - num] != 0)
            {
                dp [y] = max (dp [y], dp [y - num] + 1);
            }
        }
    }
    printf ("%d\n", dp [n]);
    return 0;
}