#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
struct Edge
{
    int to, level;
    ll weight;
};
int stations, connections;
int A, B;
ll C;
vector <Edge> adj [100001];
bool inQueue [100001];
ll dis [100001];
queue <int> Q;
bool okay (int lvl)
{
    while (!Q.empty())
    {
        inQueue [Q.front()] = 0;
        Q.pop();
    }
    Q.push (A);
    inQueue [A] = 1;
    dis [A] = 0;
    while (!Q.empty())
    {
        int temp = Q.front();
        inQueue [temp] = 0;
        Q.pop();
        if (dis [temp] >= C)
        {
            continue;
        }
        for (Edge each: adj [temp])
        {
            if (each.level <= lvl)
            {
                if (dis [each.to] == -1)
                {
                    dis [each.to] = dis [temp] + each.weight;
                    if (dis [each.to] < C && !inQueue [each.to])
                    {
                        Q.push (each.to);
                        inQueue [each.to] = 1;
                    }
                }
                else if (dis [each.to] >= dis [temp] + each.weight)
                {
                    dis [each.to] = dis [temp] + each.weight;
                    if (dis [each.to] < C && !inQueue [each.to])
                    {
                        Q.push (each.to);
                        inQueue [each.to] = 1;
                    }
                }
            }
            if (dis [B] != -1 && dis [B] < C)
            {
                return true;
            }
        }
    }
    return false;
}
int main ()
{
    scanf ("%d%d", &stations, &connections);
    Edge hi;
    int from, to;
    for (int x = 1; x <= connections; x++)
    {
        scanf ("%d%d%lld", &from, &to, &hi.weight);
        hi.to = to;
        hi.level = x;
        adj [from].push_back (hi);
        hi.to = from;
        adj [to].push_back (hi);
    }
    scanf ("%d%d%lld", &A, &B, &C);
    memset (dis, -1, sizeof (dis));
    int high = connections;
    int lo = 1;
    int min = -1;
    while (lo + 1 < high)
    {
        int mid = (lo + high)/2;
        if (okay (mid))
        {
            high = mid;
            memset (dis, -1, sizeof (dis));
        }
        else
        {
            lo = mid;
        }
    }
    if (okay (lo))
    {
        min = lo;
    }
    else
    {
        if (okay (high))
        {
            min = high;
        }
    }
    printf ("%d\n", min);
    return 0;
}
