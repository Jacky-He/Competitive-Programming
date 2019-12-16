#include <bits/stdc++.h>
using namespace std;
int n, q;
int psa [2002];
set<pair<int, int>> sum [5000];
int num, l, r;
int main ()
{
    scanf ("%d%d", &n, &q);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &num);
        psa [x] = psa [x - 1] + num;
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = x; y <= n; y++)
        {
            sum [psa [y] - psa [x - 1]].insert({x, y});
        }
    }
    for (int x = 0; x < q; x++)
    {
        scanf ("%d%d%d", &l, &r, &num);
        bool yes = false;
        for (pair <int, int> each: sum [num])
        {
            if (each.first >= l && each.second <= r)
            {
                printf ("YES\n");
                yes = true;
                break;
            }
        }
        if (!yes)
        {
            printf ("NO\n");
        }
    }
    return 0;
}


