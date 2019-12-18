#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define INFINT 0x3f3f3f3f
typedef long long int ll;
using namespace std;
int cities, edges, hubs, queries;
vector <pair <int, int>> adj [20001];
ll dis [201][20001];
bool yesHub [20001];
unordered_map <int, int> lookup; //key: hub, value: index of dis;
int from, to, weight;
int hub;
priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater <pair <ll, int>>> Q;
vector <ll> finalDis;
void dijkstra (int node, int index)
{
    Q.push ({0, node});
    dis [index][node] = 0;
    while (!Q.empty())
    {
        ll d = Q.top().first;
        int n = Q.top().second;
        Q.pop();
        if (d > dis [index][n])
        {
            continue;
        }
        for (pair <int, int> each: adj [n])
        {
            if (d + each.second < dis [index][each.first])
            {
                dis [index][each.first] = d + each.second;
                Q.push ({dis [index][each.first], each.first});
            }
        }
    }
}
int main ()
{
    scanf ("%d%d%d%d", &cities, &edges, &hubs, &queries);
    for (int x = 0; x < 201; x++)
    {
        memset (dis [x], 0x3f, sizeof (dis [x]));
    }
    for (int x = 0; x < edges; x++)
    {
        scanf ("%d%d%d", &from, &to, &weight);
        adj [from].push_back ({to, weight});
    }
    for (int x = 0; x < hubs; x++)
    {
        scanf ("%d", &hub);
        yesHub [hub] = true;
        lookup [hub] = x;
        dijkstra (hub, x);
    }
    for (int x = 0; x < queries; x++)
    {
        scanf ("%d%d", &from, &to);
        if (from == to)
        {
            finalDis.push_back (0);
        }
        else
        {
            if (yesHub [from])
            {
                if (dis [lookup [from]][to] != INF)
                {
                    finalDis.push_back (dis [lookup[from]][to]);
                }
            }
            else
            {
                ll min = INF;
                for (pair <int, int> each: adj [from])
                {
                    if (yesHub [each.first] && dis [lookup [each.first]][to] != INF)
                    {
                        if (dis [lookup[each.first]][to] + each.second < min)
                        {
                            min = dis [lookup[each.first]][to] + each.second;
                        }
                    }
                }
                if (min != INF)
                {
                    finalDis.push_back (min);
                }
            }
        }
    }
    printf ("%d\n", (int)finalDis.size());
    if (finalDis.size() == 0)
    {
        return 0;
    }
    ll sum = 0;
    for (ll each: finalDis)
    {
        sum += each;
    }
    printf ("%lld\n", sum);
    return 0;
}
