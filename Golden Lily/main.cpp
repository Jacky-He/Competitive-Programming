#include <bits/stdc++.h>
using namespace std;
int graph [1001][1001]; //length, depth
int dis [1001][1001];
int l, d, a, b;
queue <pair <int, int>> Q;
vector <pair <int, int>> adj (pair <int, int> p)
{
    vector <pair <int, int>> v;
    if (p.first + 1 < l)
    {
        v.push_back ({p.first + 1, p.second});
    }
    if (p.second < d)
    {
        v.push_back ({p.first, p.second + 1});
    }
    if (p.first - 1 >= 0)
    {
        v.push_back ({p.first - 1, p.second});
    }
    return v;
}
int main ()
{
    scanf ("%d%d", &l, &d);
    for (int x = 0; x < 1001; x++)
    {
        memset (dis [x], 0x3f, sizeof (dis [x]));
    }
    for (int x = 0; x < d; x++)
    {
        for (int y = 0; y < l; y++)
        {
            scanf ("%d", &graph [y][x]);
        }
    }
    Q.push ({0, 0});
    dis [0][0] = graph [0][0];
    while (!Q.empty())
    {
        pair <int, int> temp = Q.front();
        Q.pop();
        for (pair <int, int> each: adj (temp))
        {
            if (dis [each.first][each.second] > dis [temp.first][temp.second] + graph [each.first][each.second])
            {
                dis [each.first][each.second] = dis [temp.first][temp.second] + graph [each.first][each.second];
                Q.push (each);
            }
        }
    }
    scanf ("%d%d", &a, &b);
    printf ("%d\n", dis [a][b]);
    return 0;
}