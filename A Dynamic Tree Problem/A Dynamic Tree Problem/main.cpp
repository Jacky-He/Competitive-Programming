#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n, m, k, junction;
vector <int> adj [MAXN];
int dis [MAXN];
bool longest [MAXN];
bool visited [MAXN];
queue <int> Q;
vector <int> results;

bool cmp (int a, int b)
{
    return a > b;
}

void dfs (int node, int prev)
{
    int res = 0;
    for (int each: adj [node])
    {
        if (each != prev)
        {
            dfs (each, node);
            res = max (res, dis [each]);
        }
    }
    dis [node] = res + 1;
}
void dfs2 (int node, int prev)
{
    for (int each: adj[node])
    {
        if (each != prev)
        {
            if (dis [each] == dis [node] - 1)
            {
                longest [each] = true;
            }
            dfs2 (each, node);
        }
    }
}

int main ()
{
    scanf ("%d%d%d", &n, &m, &k);
    for (int x = 2; x <= n; x++)
    {
        scanf ("%d", &junction);
        adj [x].push_back (junction);
        adj [junction].push_back (x);
    }
    dfs (1, 1);
    longest [1] = true;
    dfs2 (1, 1);
    
    results.push_back (dis [1]);
    Q.push (1);
    visited [1] = true;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        bool flag = false;
        for (int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                if (!longest [each])
                {
                    results.push_back (dis [each]);
                }
                else
                {
                    if (flag)
                    {
                        results.push_back (dis [each]);
                    }
                    flag = true;
                }
                Q.push (each);
            }
        }
    }
    sort (results.begin(), results.end(), cmp);
    int size = (int)results.size();
    for (int x = 0; x < m - 1; x++)
    {
        int temp = x%k;
        printf ("%d ", temp < size? results [temp] : 0);
    }
    int temp = (m - 1)%k;
    printf ("%d\n", temp < size? results [temp]:0);
    return 0;
}

/*
 15 15 20
 1 1 3 4 4 3 2 8 8 10 6 7 8 14
 
 
 */
