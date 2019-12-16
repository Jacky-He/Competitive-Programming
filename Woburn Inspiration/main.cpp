#include <bits/stdc++.h>
#define MAX_N 1000000007
using namespace std;
int main ()
{
    int r, c, k;
    scanf ("%d%d%d", &r, &c, &k);
    int matrix [c][r];
    int counter = 0;
    int lastOne = 0;
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < c; y++)
        {
            scanf ("%d", &matrix [y][x]);
        }
    }
    for (int x = 0; x < c; x++)
    {
        lastOne = 0 - MAX_N;
        for (int y = 0; y < r; y++)
        {
            if (matrix [x][y] == 1)
            {
                lastOne = y;
            }
            else if (matrix [x][y] == 2)
            {
                if (y - k <= lastOne)
                {
                    counter++;
                }
            }
        }
    }
    printf ("%d\n", counter);
    return 0;
}
