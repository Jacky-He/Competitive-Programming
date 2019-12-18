#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 150004
using namespace std;
int arr [4][MAXN];
int n, num;
int result = INF;
int dp [4][MAXN];
int a [] = {1, 2, 3};
int main ()
{
    scanf ("%d", &n);
    for (int x = 1; x <= 3; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf ("%d", &num);
            arr [x][y] = num;
        }
    }
    do
    {
        for (int x = 0; x < 4; x++)
        {
            memset (dp [x], 0x3f, sizeof (dp [x]));
        }
        dp [0][0] = 0;
        for (int x = 1; x <= 3; x++)
        {
            for (int y = x; y <= n; y++)
            {
                dp [x][y] = min (dp [x - 1][y - 1], dp [x][y - 1]) + arr [a[x - 1]][y];
            }
        }
        result = min (result, dp [3][n]);
    }
    while (next_permutation(a, a + 3));
    printf ("%d\n", result);
    return 0;
}

