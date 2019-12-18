#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
    int to, weight, sec;
};
struct cmp
{
    bool operator() (const edge& e1, const edge& e2)
    {
        return e1.weight > e2.weight;
    }
};
edge makeedge (int to, int weight, int sec)
{
    edge something;
    something.to = to;
    something.weight = weight;
    something.sec = sec;
    return something;
}
int seconds, n, m;
int from, to, weight, above;
vector <edge> adj [1601];
int dis [1601][3601];
priority_queue <edge, vector <edge>, cmp> Q;
int main ()
{
    scanf ("%d", &seconds);
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d%d", &from, &to, &weight, &above);
        if (above == 1)
        {
            adj [from].push_back (makeedge(to, weight, weight));
            adj [to].push_back (makeedge (from, weight, weight));
        }
        else
        {
            adj [from].push_back (makeedge(to, weight, 0));
            adj [to].push_back (makeedge (from, weight, 0));
        }
    }
    for (int x = 0; x < 1601; x++)
    {
        memset (dis [x], 0x3f, sizeof (dis [x]));
    }
    dis [0][0] = 0;
    Q.push(makeedge (0, 0, 0)); //first node, second weight, third seconds;
    while (!Q.empty())
    {
        int theweight = Q.top().weight;
        int thenode = Q.top().to;
        int thesec = Q.top().sec;
        Q.pop();
        for (edge each: adj [thenode])
        {
            if (thesec + each.sec <= seconds && dis [each.to][thesec + each.sec] > theweight + each.weight)
            {
                dis [each.to][thesec + each.sec] = theweight + each.weight;
                Q.push (makeedge(each.to, theweight + each.weight, thesec+each.sec));
            }
        }
    }
    int min = INF;
    for (int x = 0; x <= seconds; x++)
    {
        if (dis [n - 1][x] < min)
        {
            min = dis [n-1][x];
        }
    }
    printf ("%d\n", min == INF? -1:min);
    return 0;
}
