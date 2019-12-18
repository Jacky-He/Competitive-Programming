#include <bits/stdc++.h>
using namespace std;
int t, n, musician;
int musicians [501];
int dp [501][5001];
int order [501];
int main ()
{
    memset (order, -1, sizeof (order));
    scanf ("%d%d", &t, &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &musician);
        musicians [x] = musician;
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= t; y++)
        {
            if (y - musicians [x] >= 0)
            {
                dp [x][y] = max (dp [x - 1][y - musicians [x]] + musicians [x], dp [x - 1][y]);
            }
        }
    }
    int curr = t;
    int x = n;
    while (curr != 0)
    {
        if (dp [x][curr] != dp [x - 1][curr])
        {
            curr -= musicians [x];
            order [x] = curr;
        }
        x--;
    }
    int position = 0;
    for (int x = 1; x <= n; x++)
    {
        if (order [x] != -1)
        {
            printf ("%d ", order [x]);
        }
        else
        {
            order [x] = position;
            printf ("%d ", order [x]);
            position += musicians [x];
        }
    }
    return 0;
}
