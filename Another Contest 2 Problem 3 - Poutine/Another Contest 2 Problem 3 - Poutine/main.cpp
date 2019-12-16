#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n, a, b, w, q, s, t;
vector <pair <int, int>> adj [MAXN];
int depth [MAXN];
pair <int, pair <int, int>> sparse [20][MAXN];
queue <int> Q;
bool visited [MAXN];

pair <int, int> newpair (pair <int, int> p1, pair <int, int> p2)
{
    int big = p1.first > p2.first ? p1.first : p2.first;
    int temp = p1.first > p2.first ? p2.first : p1.first;
    return {big, max (temp, max(p1.second, p2.second))};
}

pair <pair <int, int>, pair <int, int>> equality (int i, int j)
{
    if (depth [i] == depth [j]) {return {{i, j}, {0, 0}};}
    int small = depth [i] < depth [j] ? i:j;
    int big = depth [i] < depth [j] ? j:i;
    pair <int, int> maxes = {0, 0};
    for (int k = 0, d = depth [big] - depth [small]; d != 0; d >>= 1, k++)
    {
        maxes = (d&1) ? newpair (maxes, sparse [k][big].second): maxes;
        big = (d&1) ? sparse [k][big].first : big;
    }
    return {{small, big}, maxes};
}

int lca (int i, int j, pair <int, int> maxes)
{
    if (sparse [0][i].first == j || sparse [0][j].first == i) {return -1;}
    if (depth [i] != depth [j])
    {
        pair <pair <int, int>, pair <int, int>> p = equality (i, j);
        return lca (p.first.first, p.first.second, p.second);
    }
    if (i == j)
    {
        return maxes.second;
    }
    for (int k = 19; k >= 0; k--)
    {
        if (sparse [k][i].first != sparse [k][j].first)
        {
            maxes = newpair (maxes, sparse [k][i].second);
            maxes = newpair (maxes, sparse [k][j].second);
            i = sparse [k][i].first;
            j = sparse [k][j].first;
        }
    }
    return newpair (newpair (maxes, sparse [0][i].second), sparse [0][j].second).second;
}

void build ()
{
    Q.push (1);
    visited [1] = true;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (pair <int, int> each: adj [temp])
        {
            if (!visited [each.first])
            {
                visited [each.first] = true;
                sparse [0][each.first].first = temp;
                sparse [0][each.first].second = {each.second, 0};
                depth [each.first] = depth [temp] + 1;
                Q.push (each.first);
            }
        }
    }
    
    for (int k = 1; k < 20; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            int mid = sparse [k - 1][i].first;
            if (mid)
            {
                sparse [k][i].first = sparse [k - 1][mid].first;
                sparse [k][i].second = newpair (sparse [k - 1][i].second, sparse [k - 1][mid].second);
            }
        }
    }
}

int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n - 1; x++)
    {
        scanf ("%d%d%d", &a, &b, &w);
        adj [a].push_back ({b, w});
        adj [b].push_back ({a, w});
    }
    build();
    scanf ("%d", &q);
    for (int x = 0; x < q; x++)
    {
        scanf ("%d%d", &s, &t);
        printf ("%d\n", lca (s, t, {-1, -1}));
    }
    return 0;
}
