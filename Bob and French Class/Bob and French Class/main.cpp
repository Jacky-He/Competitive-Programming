#include <bits/stdc++.h>
#define MAX_N 1000000007
using namespace std;
int main ()
{
    int n;
    scanf ("%d\n", &n);
    int french [n];
    int english [n];
    int dp [n + 1][3];
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &french [x]);
    }
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &english [x]);
    }
    for (int i = 0; i < 3; i++) {dp [0][i] = 0;}
    for (int x = 1; x <= n; x++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                dp [x][j] = max (dp [x - 1][0], max (dp [x - 1][1], dp [x - 1][2])) + english [x - 1];
            }
            else
            {
                dp [x][j] = dp [x - 1][j - 1] + french [x - 1];
            }
        }
    }
    int sum = max (max (dp [n][0], dp [n][1]), dp [n][2]);
    cout << sum << endl;
    return 0;
}
