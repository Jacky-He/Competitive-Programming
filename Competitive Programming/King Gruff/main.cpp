#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct edge {int to, length, cost, number;};
struct e {int from, to, length, cost;};
edge makeEdge (int to, int length, int cost, int number) {edge e; e.to = to; e.length = length; e.cost = cost; e.number = number; return e;}
e newEdge (int from, int to, int length, int cost){e e; e.from = from; e.to = to; e.length = length; e.cost = cost; return e;}
int n, m, a, b, queries, maximum;
int from, to, length, cost;
vector <edge> adjforward [100001];
vector <edge> adjbackward [100001];
priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> Q;
int disa [100001];
int disb [100001];
e allEdges [100001]; //stores the cost for each edge
vector <pair <int, int>> results;
int main ()
{
    scanf ("%d%d%d%d", &n, &m, &a, &b);
    for (int x = 1; x <= m; x++)
    {
        scanf ("%d%d%d%d", &from, &to, &length, &cost);
        adjforward [from].push_back (makeEdge(to, length, cost, x));
        adjbackward [to].push_back (makeEdge(from, length, cost, x));
        allEdges [x] = newEdge (from, to, length, cost);
    }
    scanf ("%d", &queries);
    Q.push ({0, a});
    memset (disa, 0x3f, sizeof (disa));
    memset (disb, 0x3f, sizeof (disb));
    disa [a] = 0;
    while (!Q.empty())
    {
        int thenode = Q.top().second;
        int thedis = Q.top().first;
        Q.pop();
        if (thedis > disa [thenode])
        {
            continue;
        }
        for (edge each: adjforward [thenode])
        {
            if (thedis + each.length < disa [each.to])
            {
                disa [each.to] = thedis + each.length;
                Q.push ({disa [each.to], each.to});
            }
        }
    }
    Q.push ({0, b});
    disb [b] = 0;
    while (!Q.empty())
    {
        int thenode = Q.top().second;
        int thedis = Q.top().first;
        Q.pop();
        if (thedis > disb [thenode])
        {
            continue;
        }
        for (edge each: adjbackward [thenode])
        {
            if (thedis + each.length < disb [each.to])
            {
                disb [each.to] = thedis + each.length;
                Q.push ({disb [each.to], each.to});
            }
        }
    }
    for (int x = 1; x <= m; x++)
    {
        if (disa [allEdges [x].from] != INF && disb [allEdges [x].to] != INF)
        {
            int distance = disa [allEdges [x].from] + allEdges [x].length + disb [allEdges [x].to];
            int cost = allEdges [x].cost;
            results.push_back ({distance, cost});
        }
    }
    sort (results.begin(), results.end());
    for (int x = 1; x < (int) results.size(); x++)
    {
        results [x].second += results [x - 1].second;
    }
    for (int x = 1; x <= queries; x++)
    {
        scanf ("%d", &maximum);
        int value = (int)(upper_bound (results.begin(), results.end(), make_pair(maximum, INF)) - results.begin() - 1);
        if (value == -1)
        {
            printf ("%d\n", 0);
        }
        else
        {
            printf ("%d\n", results [value].second);
        }
    }
    return 0;
}
