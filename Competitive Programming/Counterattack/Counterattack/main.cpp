#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
    int from, to, weight;
};
vector <pair<int, int>> adj [5001];
vector <edge> e;
int n, m, a, b, w;
int disfb [5001];
int disfe [5001];
priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair <int, int>>> Q;
edge makeEdge (int from, int to, int weight)
{
    edge ed;
    ed.from = from;
    ed.to = to;
    ed.weight = weight;
    return ed;
}
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d", &a, &b, &w);
        adj [a].push_back ({b, w});
        adj [b].push_back ({a, w});
        e.push_back (makeEdge (a, b, w));
    }
    memset (disfb, 0x3f, sizeof (disfb));
    memset (disfe, 0x3f, sizeof (disfe));
    Q.push ({0, 1}); //distance, node
    disfb [1] = 0;
    while (!Q.empty())
    {
        int d = Q.top().first;
        int node = Q.top().second;
        Q.pop();
        if (disfb [node] < d)
        {
            continue;
        }
        for (pair <int, int> each: adj [node])
        {
            if (disfb [each.first] > disfb [node] + each.second)
            {
                disfb [each.first] = disfb [node] + each.second;
                Q.push ({disfb[each.first], each.first});
            }
        }
    }
    Q.push ({0, n});
    disfe [n] = 0;
    while (!Q.empty())
    {
        int d = Q.top().first;
        int node = Q.top().second;
        Q.pop();
        if (disfe[node] < d)
        {
            continue;
        }
        for (pair <int, int> each: adj [node])
        {
            if (disfe [each.first] > disfe [node] + each.second)
            {
                disfe [each.first] = disfe [node] + each.second;
                Q.push ({disfe[each.first], each.first});
            }
        }
    }
    int min = INF;
    int acmin = disfb [n];
    for (edge each: e)
    {
        if (disfb [each.from] + each.weight + disfe [each.to] > acmin && disfb [each.from] + each.weight + disfe [each.to] < min)
        {
            min = disfb [each.from] + each.weight + disfe [each.to];
        }
        if (disfb [each.to] + each.weight + disfe [each.from] > acmin && disfb [each.to] + each.weight + disfe [each.from] < min)
        {
            min = disfb [each.to] + each.weight + disfe [each.from];
        }
    }
    printf ("%d\n", min);
    return 0;
}
