#include <bits/stdc++.h>
using namespace std;

int w, h, n, num;
int psa [255][255];

set <pair <int, int>> factors (int num)
{
    set <pair <int, int>> s;
    for (int x = 1; x <= num; x++)
    {
        s.insert ({x, num/x});
        s.insert ({num/x, x});
    }
    return s;
}
int main ()
{
    scanf ("%d%d%d", &w, &h, &n);
    for (int x = 1; x <= h; x++)
    {
        for (int y = 1; y <= w; y++)
        {
            scanf ("%d", &num);
            psa [x][y] = num + psa [x - 1][y] + psa [x][y - 1] - psa [x - 1][y - 1];
        }
    }
    int maxi = 0;
    for (pair <int, int> each: factors (n))
    {
        cout << each.first << " " << each.second << endl;
        for (int x = 1; x + each.first - 1 <= h; x++)
        {
            for (int y = 1; y + each.second - 1 <= w; y++)
            {
                int a = x + each.first - 1;
                int b = y + each.second - 1;
                maxi = max (maxi, psa [a][b] - psa [x - 1][b] - psa [a][y - 1] + psa [x - 1][y - 1]);
            }
        }
    }
    printf ("%d\n", maxi);
    return 0;
}



