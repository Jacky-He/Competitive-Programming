#include <bits/stdc++.h>
using namespace std;
struct Point {int x, y; Point (int a, int b) {x = a; y = b;}};
int n, m, a, b;
vector <Point> cities;
int quadrant (int x, int y)
{
    if (x > 0 && y > 0)
    {
        return 1;
    }
    else if (x > 0 && y < 0)
    {
        return 4;
    }
    else if (x < 0 && y > 0)
    {
        return 2;
    }
    else if (x < 0 && y < 0)
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d%d", &a, &b);
        Point p = Point (a, b);
        cities.push_back (p);
    }
    for (int x = 0; x < m; x++)
    {
        vector <Point> vertices;
        for (int y = 0; y < 3; y++)
        {
            scanf ("%d%d", &a, &b);
            Point p = Point (a, b);
            vertices.push_back (p);
        }
        int cnt = 0;
        for (Point city: cities)
        {
            for (Point vertice: vertices)
            {
                
            }
        }
    }
    return 0;
}
