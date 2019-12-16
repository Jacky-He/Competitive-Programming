#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m, a, b, fini;
pair <int, int> paths [1000001];
pair <int, int> dp [1000001];
struct cmp {bool operator () (const int& n1, const int& n2){return dp [n1].first > dp [n2].first;}};
priority_queue <int, vector <int>, cmp> adj [1000001];
stack <int> pathsreversed;
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 1; x <= m; x++)
    {
        scanf ("%d%d", &a, &b);
        paths [x] = {a, b};
        if (x == 1)
        {
            adj [a].push(0);
        }
        int result = INF;
        int second = 0;
        if (!adj [a].empty())
        {
            result = dp [adj [a].top()].first;
            second = adj [a].top();
        }
        dp [x].first = result == INF? 1 : result + 1;
        dp [x].second = second;
        adj [b].push (x);
        if (x == m)
        {
            fini = paths [x].second;
        }
    }
    int out = INF;
    int current = 0;
    for (int x = 1; x <= m; x++)
    {
        if (paths [x].second == fini)
        {
            if (out > dp [x].first)
            {
                out = dp [x].first;
                current = x;
            }
        }
    }
    printf ("%d\n", out);
    while (current != 0)
    {
        pathsreversed.push(current);
        current = dp [current].second;
    }
    for (int x = (int) pathsreversed.size() - 1; x >= 0; x--)
    {
        int temp = pathsreversed.top();
        pathsreversed.pop();
        printf ("%d %d\n", paths [temp].first, paths [temp].second);
    }
    return 0;
}
