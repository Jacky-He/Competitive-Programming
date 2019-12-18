#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int from, to, weight;
vector <pair <int, int>> adj [20];
int dis [20][524288];

void dfs (int node, int mask)
{
    int cost = dis [node][mask];

    for (pair <int, int> each: adj [node])
    {
        if (!((mask >> each.first)&1))
        {
            int nextmask = (1 << each.first)|mask;
            if (cost + each.second > dis [each.first][nextmask])
            {
                dis [each.first][nextmask] = cost + each.second;
                dfs (each.first, nextmask);
            }
        }
    }
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d", &from, &to, &weight);
        adj [from].push_back ({to, weight});
    }
    dfs (0, 1);
    int result = 0;
    for (int x = 0; x < (1 << n); x++)
    {
        result = max (result, dis [n - 1][x]);
    }
    printf ("%d\n", result);
    return 0;
}


