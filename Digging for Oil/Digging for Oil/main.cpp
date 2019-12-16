#include <bits/stdc++.h>
using namespace std;

struct square
{
    int x, y, k, sum;
};
bool cmp (square s1, square s2)
{
    return s1.sum > s2.sum;
}
square makesquare (int a, int b, int c)
{
    square s;
    s.x = a;
    s.y = b;
    s.sum = c;
    return s;
}
int m, n, k, num;
int psa [1505][1505];
vector <square> v;
bool overlap (square s1, square s2)
{
    int maxx1 = s1.x + k - 1;
    int minx1 = s1.x;
    int maxy1 = s1.y + k - 1;
    int miny1 = s1.y;
    int maxx2 = s2.x + k - 1;
    int minx2 = s2.x;
    int maxy2 = s2.y + k - 1;
    int miny2 = s2.y;
    return !(minx1 > maxx2 || maxx1 < minx2 || maxy1 < miny2 || miny1 > maxy2);
}

int main ()
{
    scanf ("%d%d%d", &m, &n, &k);
    for (int x = 1; x <= m; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf ("%d", &num);
            psa [x][y] = psa [x - 1][y] + psa [x][y - 1] + num - psa [x - 1][y - 1];
        }
    }
    for (int x = 1; x + k - 1 <= m; x++)
    {
        for (int y = 1; y + k - 1 <= n; y++)
        {
            v.push_back (makesquare(x, y, psa [x + k - 1][y + k - 1] - psa [x - 1][y + k - 1] - psa [x + k - 1][y - 1] + psa [x - 1][y - 1]));
        }
    }
    sort (v.begin(), v.end(), cmp);
    int maxsum = 0;
    for (int x = 1; x + k - 1 <= m; x++)
    {
        for (int y = 1; y + k - 1 <= n; y++)
        {
            int sum = 0;
            square s1 = makesquare(x, y, psa [x + k - 1][y + k - 1] - psa [x - 1][y + k - 1] - psa [x + k - 1][y - 1] + psa [x - 1][y - 1]);
            sum = s1.sum;
            square s2 = makesquare(x, y, 0);
            int cnt = 0;
            for (int i = 0; i < (int)v.size(); i++)
            {
                if (!overlap (s1, v[i]) && !overlap (s2, v[i]))
                {
                    sum += v[i].sum;
                    if (cnt == 0)
                    {
                        s2 = v[i];
                    }
                    else if (cnt == 1)
                    {
                        break;
                    }
                    cnt++;
                }
            }
            maxsum = max (maxsum, sum);
        }
    }
    printf ("%d\n", maxsum);
    return 0;
}
