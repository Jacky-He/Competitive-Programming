#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long int ll;
using namespace std;
vector <pair <int, int>> adj [100001];
int n, m;
int from, to, weight;
priority_queue <pair <int, int>, vector<pair<int, int>>, greater <pair<int, int>>> Q;
ll disFromS [100001];
ll disFromD [100001];
int main ()
{
    scanf ("%d%d", &n, &m);
    memset (disFromS, 0x3f, sizeof (disFromS));
    memset (disFromD, 0x3f, sizeof (disFromD));
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d", &from, &to,&weight);
        adj [from].push_back (make_pair (to,weight));
        adj [to].push_back (make_pair (from, weight));
    }
    disFromS [0] = 0;
    Q.push ({0, 0});
    while (!Q.empty())
    {
        int weight = Q.top().first;
        int vertice = Q.top().second;
        Q.pop();
        if (weight > disFromS [vertice])
        {
            continue;
        }
        for (pair <int, int> each: adj [vertice])
        {
            if (disFromS [each.first] > weight + each.second)
            {
                disFromS [each.first] = weight + each.second;
                Q.push ({disFromS[each.first], each.first});
            }
        }
    }
    disFromD [n - 1] = 0;
    Q.push ({0, n - 1});
    while (!Q.empty())
    {
        int weight = Q.top().first;
        int vertice = Q.top().second;
        Q.pop();
        if (weight > disFromD [vertice])
        {
            continue;
        }
        for (pair <int, int> each: adj [vertice])
        {
            if (disFromD [each.first] > weight + each.second)
            {
                disFromD [each.first] = weight + each.second;
                Q.push ({disFromD[each.first], each.first});
            }
        }
    }
    ll m = 0;
    for (int x = 0; x < 100001; x++)
    {
        if (disFromD [x] != INF && disFromS [x] != INF)
        {
            m = max (m, disFromD [x] + disFromS [x]);
        }
    }
    printf ("%lld\n", m);
    return 0;
}
