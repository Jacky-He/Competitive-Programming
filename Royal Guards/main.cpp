#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map <int, vector <int>> vertical;
unordered_map <int, vector <int>> horizontal;
int buildings, points;
int x, y;
int x2, y2;
ll cnt;
int main ()
{
    scanf ("%d", &buildings);
    for (int i = 0; i < buildings; i++)
    {
        scanf ("%d%d", &x, &y);
        vertical [x].push_back (y);
        horizontal [y].push_back (x);
    }
    for (auto& each: vertical)
    {
        sort (each.second.begin(), each.second.end());
    }
    for (auto& each: horizontal)
    {
        sort (each.second.begin(), each.second.end());
    }
    scanf ("%d", &points);
    scanf ("%d%d", &x, &y);
    for (int i = 1; i < points; i++)
    {
        scanf ("%d%d", &x2, &y2);
        if (x2 == x)
        {
            int smaller = min (y2, y);
            int bigger = max (y2, y);
            cnt += upper_bound (vertical [x].begin(), vertical [x].end(), bigger) - lower_bound(vertical [x].begin(), vertical [x].end(), smaller);
        }
        else if (y2 == y)
        {
            int smaller = min (x2, x);
            int bigger = max (x2, x);
            cnt += upper_bound (horizontal [y].begin(), horizontal [y].end(), bigger) - lower_bound (horizontal [y].begin(), horizontal [y].end(), smaller);
        }
        x = x2;
        y = y2;
    }
    printf ("%lld\n", cnt);
    return 0;
}