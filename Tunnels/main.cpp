#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

vector <pair <int, int>> adj [200004];
int n, t, from, to, weight;
int up [200004], down [200004];
bool visited [200004];
pair <int, int> maxmaxn [200004]; //first: second minimum second: minimum number
queue <int> Q;
int dfs (int node)
{
    visited [node] = true;
    int result = 0;
    int secondmax = 0;
    int nummax = 0;
    for (pair <int, int> each : adj [node])
    {
        if (!visited [each.first])
        {
            int temp = dfs (each.first) + each.second;
            if (result < temp)
            {
                secondmax = result;
                result = temp;
                nummax = 1;
            }
            else if (result == temp)
            {
                nummax++;
            }
            else if (secondmax < temp)
            {
                secondmax = temp;
            }
        }
    }
    maxmaxn [node] = {secondmax, nummax};
    return down [node] = result;
}

void solve ()
{
    dfs (1);
    memset (visited, false, sizeof (visited));
    up [1] = 0;
    visited [1] = true;
    Q.push (1);
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (pair <int, int> each: adj [temp])
        {
            if (!visited [each.first])
            {
                visited [each.first] = true;
                int something = 0;
                if (maxmaxn [temp].second == 1 && down [each.first] + each.second == down [temp])
                {
                    something = maxmaxn [temp].first;
                }
                else
                {
                    something = down [temp];
                }
                up [each.first] = max (up [temp] + each.second, something + each.second);
                Q.push (each.first);
            }
        }
    }
}

int main()
{
    scanf ("%d %d", &n, &t);
    int sum = 0;
    for (int x = 0; x < n - 1; x++)
    {
        scanf ("%d %d %d", &from, &to, &weight);
        adj [from].push_back ({to, weight});
        adj [to].push_back ({from, weight});
        sum += weight;
    }
    solve ();
    for (int x = 1; x <= n; x++)
    {
        if (adj [x].size() == t)
        {
            printf ("%d %d\n", x, 2*sum - max (up [x], down [x]));
        }
    }
    return 0;
}