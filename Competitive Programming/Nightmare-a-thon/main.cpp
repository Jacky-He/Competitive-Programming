#include <bits/stdc++.h>
using namespace std;
int n, q, num;
int psa [500001][11];
int a, b;

int main ()
{
    scanf ("%d%d", &n, &q);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &num);
        for (int y = 0; y <= 10; y++)
        {
            psa [x][y] = psa [x - 1][y];
        }
        psa [x][num]++;
    }
    for (int x = 1; x <= q; x++)
    {
        scanf ("%d%d", &a, &b);
        int rating = 0;
        for (int y = 1; y <= 10; y++)
        {
            if (psa [a - 1][y])
            {
                rating = max (rating, y);
            }
            if (psa [n][y] - psa [b][y])
            {
                rating = max (rating, y);
            }
        }
        int numnum = psa [n][rating] - psa [b][rating] + psa [a - 1][rating];
        printf ("%d %d\n", rating, numnum);
    }
    return 0;
}