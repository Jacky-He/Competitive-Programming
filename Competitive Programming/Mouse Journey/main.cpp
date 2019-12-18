#include <bits/stdc++.h>
using namespace std;
int rows, cols, cats, a, b, dp [30][30];
int main ()
{
    scanf ("%d%d%d", &rows, &cols, &cats);
    for (int x = 0; x < 30; x++) memset (dp [x], -1, sizeof (dp [x]));
    memset (dp [0], 0, sizeof (dp [0]));
    for (int x = 0; x < 30; x++) dp [x][0] = 0;
    for (int x = 0; x < cats; x++){scanf ("%d%d", &a, &b);dp [a][b] = 0;}
    dp [0][1] = 1;
    for (int x = 1; x <= rows; x++) for (int y = 1; y <= cols; y++) dp [x][y] = dp [x][y] != 0? dp [x - 1][y] + dp [x][y - 1]:0;
    printf ("%d\n", dp [rows][cols]);
    return 0;
}
