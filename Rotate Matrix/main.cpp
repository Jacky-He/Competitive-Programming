#include <bits/stdc++.h>
using namespace std;
int rows, cols;
int main ()
{
    scanf ("%d%d", &rows, &cols);
    int matrix [rows][cols];
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            scanf ("%d", &matrix [x][y]);
        }
    }
    int result [cols][rows];
    for (int c = cols - 1, another = 0; c >= 0; c--, another++)
    {
        for (int r = 0; r < rows; r++)
        {
            result [another][r] = matrix [r][c];
        }
    }
    for (int x = 0; x < cols; x++)
    {
        for (int y = 0; y < rows; y++)
        {
            printf ("%d ", result [x][y]);
        }
        printf ("\n");
    }
    return 0;
}
