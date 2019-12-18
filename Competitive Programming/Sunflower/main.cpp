#include <bits/stdc++.h>
using namespace std;
int minimum = 1000000007;
int n;
int main ()
{
    scanf ("%d", &n);
    int data [n][n];
    int data2 [n][n];
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            scanf ("%d", &data [row][col]);
            if (data [row][col] < minimum)
            {
                minimum = data [row][col];
            }
        }
    }
    while (data [0][0] != minimum)
    {
        for (int row = n - 1, col1 = n - 1; row >= 0; row--, col1--)
        {
            for (int col = n - 1, row1 = 0; col >= 0; col--, row1++)
            {
                data2 [row][col] = data [row1][col1];
            }
        }
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                data [row][col] = data2 [row][col];
            }
        }
    }
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            printf ("%d ", data [row][col]);
        }
        printf("\n");
    }
    return 0;
}
