#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct dest
{
    int to, tm, thick;
};
struct Compare
{
    bool operator () (const dest& a, const dest& b)
    {
        return a.tm > b.tm;
    }
};
int k, n, m;
int a, b, t, h;
int A, B;
vector <dest> adj [2001];
int dis [2001][2001]; //first: time, second: hull
priority_queue <dest, vector <dest>, Compare> Q;
dest makedest (int x, int y, int z)
{
    dest d;
    d.to = x;
    d.tm = y;
    d.thick = z;
    return d;
}
int main ()
{
    scanf ("%d%d%d", &k, &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d%d", &a, &b, &t, &h);
        adj [a].push_back (makedest (b, t, h));
        adj [b].push_back (makedest (a, t, h));
    }
    scanf ("%d%d", &A, &B);
    for (int x = 0; x < 2001; x++)
    {
        memset (dis [x], 0x3f, sizeof (dis [x]));
    }
    Q.push (makedest (A, 0, 0));
    dis [A][0] = 0;
    while (!Q.empty())
    {
        int thetime = Q.top().tm;
        int thethick = Q.top().thick;
        int thenode = Q.top().to;
        Q.pop();
        for (dest each: adj [thenode])
        {
            if (thethick + each.thick < k && dis [each.to][thethick + each.thick] > thetime + each.tm)
            {
                dis [each.to][thethick + each.thick] = thetime + each.tm;
                Q.push (makedest (each.to, thetime + each.tm, thethick + each.thick));
            }
        }
    }
    int min = INF;
    for (int x = 0; x <= k; x++)
    {
        if (dis [B][x] < min)
        {
            min = dis [B][x];
        }
    }
    printf ("%d\n", min == INF? -1: min);
    return 0;
}

