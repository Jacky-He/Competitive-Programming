#include <bits/stdc++.h>
using namespace std;
int n, m;
int from, to;
int maxdis [100001];
vector <int> adj [100001];
bool visited [100001];
int dfs (int node)
{
    visited [node] = true;
    if (maxdis [node] != -1)
    {
        return maxdis [node];
    }
    int result = 0;
    for (int each: adj [node])
    {
        result = max (result, dfs (each) + 1);
    }
    return maxdis [node] = result;
}
int main ()
{
    scanf ("%d%d", &n, &m);
    memset (maxdis, -1, sizeof (maxdis));
    int result = 0;
    for (int x = 1; x <= m; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back (to);
    }
    for (int x = 1; x <= n; x++)
    {
        if (!visited [x])
        {
            result = max (result, dfs (x));
        }
    }
    printf ("%d\n", result);
    return 0;
}