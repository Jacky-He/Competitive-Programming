#include <bits/stdc++.h>
using namespace std;
int n, m, q, from, to, temp;
vector <int> adj [100001];
queue <int> Q;
int ranklist [100001];
int visited [100001];
bool bfsable (int constrain)
{
    memset (visited, 0, sizeof (visited));
    while (!Q.empty())
    {
        Q.pop();
    }
    Q.push (1);
    visited [1] = 1;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (int each: adj [temp])
        {
            if (!visited [each] && ranklist [each] > constrain)
            {
                visited [each] = true;
                if (each == n)
                {
                    return true;
                }
                Q.push (each);
            }
        }
    }
    return false;
}
int main ()
{
    scanf ("%d%d%d", &n, &m, &q);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back (to);
        adj [to].push_back (from);
    }
    for (int x = 1; x <= q; x++)
    {
        scanf ("%d", &temp);
        if (ranklist [temp] == 0)
        {
            ranklist [temp] = x;
        }
        else
        {
            ranklist [temp] = min (ranklist [temp], x);
        }
    }
    int lo = 1;
    int hi = q;
    int ans = 0;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi)/2;
        if (bfsable (mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    if (bfsable (hi))
    {
        ans = hi;
    }
    else if (bfsable (lo))
    {
        ans = lo;
    }
    else
    {
        ans = 0;
    }
    for (int x = 0; x < ans; x++)
    {
        printf ("YES\n");
    }
    for (int x = ans; x < q; x++)
    {
        printf ("NO\n");
    }
}
