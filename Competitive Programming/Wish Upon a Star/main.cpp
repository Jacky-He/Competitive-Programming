#include <bits/stdc++.h>
using namespace std;
int n, m;
int from, to;
vector <int> adj [200005];
int cnt;
bool visited [200005];
queue <pair <int, int>> Q;
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back (to);
        adj [to].push_back (from);
    }
    for (int x = 1; x <= n; x++)
    {
        if (!visited [x])
        {
            Q.push ({x, 0});
            visited [x] = true;
            while (!Q.empty())
            {
                pair <int, int> temp = Q.front();
                Q.pop();
                for (int each: adj [temp.first])
                {
                    if (!visited [each])
                    {
                        visited [each] = true;
                        Q.push ({each, temp.first});
                    }
                    else if (each != temp.second)
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    if (cnt > 2)
    {
        printf ("NO\n");
    }
    else
    {
        printf ("YES\n");
    }
    return 0;
}
