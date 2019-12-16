#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int from, to, weight;
};
vector <pair <int, int>> adj [20001];
int disfirst [20001];
int dissecond [20001];
int n, m, a, b, w;
priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> Q;
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d", &a, &b, &w);
        adj [a].push_back ({b, w});
    }
    memset (disfirst, -1, sizeof (disfirst));
    memset (dissecond, -1, sizeof (dissecond));
    Q.push ({0, 1}); //dis, node
    disfirst [1] = 0;
    while (!Q.empty())
    {
        int d = Q.top().first;
        int node = Q.top().second;
        Q.pop();
        for (pair <int, int> each: adj [node])
        {
            if (disfirst [each.first] == -1 || disfirst [each.first] > d + each.second)
            {
                dissecond [each.first] = disfirst [each.first];
                disfirst [each.first] = d + each.second;
                Q.push ({disfirst [each.first], each.first});
            }
            else if (disfirst [each.first] != d + each.second && (dissecond [each.first] == -1 || dissecond [each.first] > d + each.second))
            {
                dissecond [each.first] = d + each.second;
                Q.push ({dissecond [each.first], each.first});
            }
        }
    }
    printf ("%d\n", dissecond [n]);
    return 0;
}
