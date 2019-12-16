#include <bits/stdc++.h>
using namespace std;
vector <int> adj [500001];
int dis1 [500001];
int top [500001];
queue <int> Q;
int n, from, to;
bool visited [500001];
pair <int, int> maxmaxn [500001]; //first: maxn, second: secondmax;
void dfs (int node)
{
    visited [node] = true;
    int result = 0;
    int counter = 0;
    int secondmax = 0;
    for (int each: adj [node])
    {
        if (!visited [each])
        {
            dfs (each);
            if (dis1 [each] == result)
            {
                counter++;
            }
            else if (dis1 [each] > result)
            {
                counter = 1;
                secondmax = result;
                result = dis1 [each];
            }
            else if (dis1 [each] > secondmax)
            {
                secondmax = dis1 [each];
            }
        }
    }
    maxmaxn [node].first = counter;
    maxmaxn [node].second = secondmax;
    dis1 [node] = result + 1;
}
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n - 1; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back(to);
        adj [to].push_back(from);
    }
    dfs (1);
    memset (visited, 0, sizeof (visited));
    top [1] = 1;
    Q.push (1);
    visited [1] = true;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                int maxdis = 0;
                if (dis1 [each] == dis1 [temp] - 1 && maxmaxn [temp].first == 1) //if this is the maximum and the only maximum
                {
                    maxdis = maxmaxn [temp].second;
                }
                else
                {
                    maxdis = dis1 [temp] - 1;
                }
                top [each] = max (top [temp] + 1, maxdis + 2);
                Q.push (each);
            }
        }
    }
    for (int x = 1; x <= n; x++)
    {
        printf ("%d\n", max (dis1 [x], top[x]));
    }
    return 0;
}
