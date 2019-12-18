#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define INF2 0x3f3f3f3f
typedef long long int ll;
using namespace std;
struct edge
{
    int from, to, weight;
};
edge makeEdge (int from, int to, int weight)
{
    edge e;
    e.from = from;
    e.to = to;
    e.weight = weight;
    return e;
}
ll dis1 [251];
ll dis2 [251];
int adj [251][251];
int n, m;
int from, to, weight;
bool visited [251];
vector <edge> allEdges;
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < 251; x++)
    {
        memset (adj [x], INF2, sizeof (adj [x]));
    }
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d", &from, &to, &weight);
        adj [from][to] = weight;
        adj [to][from] = weight;
        allEdges.push_back (makeEdge (from, to, weight));
    }
    memset (dis1, 0x3f, sizeof (dis1));
    dis1 [1] = 0;
    for (int x = 1; x <= n; x++)
    {
        int node = -1;
        ll min = INF;
        for (int y = 1; y <= n; y++)
        {
            if (!visited [y] && dis1 [y] < min)
            {
                min = dis1 [y];
                node = y;
            }
        }
        if (node == -1)
        {
            break;
        }
        visited [node] = 1;
        for (int y = 1; y <= n; y++)
        {
            if (!visited [y] && dis1[y] > dis1[node] + adj [node][y])
            {
                dis1 [y] = dis1[node] + adj [node][y];
            }
        }
    }
    ll shortest = dis1 [n];
    ll longest = 0;
    for (edge each: allEdges)
    {
        if (dis1 [each.from] != INF && dis2 [each.to] != INF)
        {
            memset (visited, 0, sizeof (visited));
            adj [each.from][each.to] *= 2;
            adj [each.to][each.from] *= 2;
            memset (dis1, 0x3f, sizeof (dis1));
            dis1 [1] = 0;
            for (int x = 1; x <= n; x++)
            {
                int node = -1;
                ll min = INF;
                for (int y = 1; y <= n; y++)
                {
                    if (!visited [y] && dis1 [y] < min)
                    {
                        min = dis1 [y];
                        node = y;
                    }
                }
                if (node == -1)
                {
                    break;
                }
                visited [node] = 1;
                for (int y = 1; y <= n; y++)
                {
                    if (!visited [y] && dis1[y] > min + adj [node][y])
                    {
                        dis1 [y] = min + adj [node][y];
                    }
                }
            }
            adj [each.from][each.to] /= 2;
            adj [each.to][each.from] /= 2;
            if (dis1 [n] > longest)
            {
                longest = dis1[n];
            }
        }
    }
    printf ("%lld\n", longest - shortest);
    return 0;
}
