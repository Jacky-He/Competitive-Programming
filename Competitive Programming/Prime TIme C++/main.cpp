#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
vector <int> points;
int n, t, num, result = INF;
int main ()
{
    scanf ("%d%d", &n, &t);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        points.push_back (num);
    }
    sort (points.begin(), points.end());
    for (int i = 0, j = t - 1; j < n; i++, j++)
    {
        if ((points [i] > 0 && points [j] > 0) || (points [i] < 0 && points [j] < 0))
        {
            result = min (result, max (abs (points [j]), abs (points [i])));
        }
        else
        {
            result = min(min (result, abs (points [j]) + abs(points [i])*2), abs(points [j])*2 + abs (points [i]));
        }
    }
    printf ("%d\n", result);
    return 0;
}
