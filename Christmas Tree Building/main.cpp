#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int nodes, edges, queries;
int a, b, c;
vector <pair <int, int>> adj [100001];
vector <pair <ll, ll>> subtrees;
ll down [100001];
ll up [100001];
pair <ll, ll> maxmaxn [100001]; //first: secondmax, second: numbermax
bool visited [100001];
bool visited2 [100001];
queue<int> Q;
ll dfs (int node)
{
    visited [node] = true;
    ll result = 0, secondmax = 0, nummax = 0;
    for (pair <int, int> each: adj [node])
    {
        if (!visited [each.first])
        {
            ll temp = dfs (each.first);
            if (temp + each.second == result)
            {
                nummax++;
            }
            else if (temp + each.second > result)
            {
                secondmax = result;
                result = temp + each.second;
                nummax = 1;
            }
            else if (temp + each.second > secondmax)
            {
                secondmax = temp + each.second;
            }
        }
    }
    down [node] = result;
    maxmaxn [node] = {secondmax, nummax};
    return result;
}
pair <ll, ll> bfs (int node)
{
    visited2 [node] = true;
    up [node] = 0;
    pair <ll, ll> result = {down [node], down [node]};
    Q.push (node);
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (pair <int, int> each: adj [temp])
        {
            if(!visited2 [each.first])
            {
                visited2 [each.first] = true;
                ll m = maxmaxn [temp].second == 1 && down [each.first] + each.second == down [temp]? maxmaxn [temp].first: down [temp];
                up [each.first] = max (up [temp] + each.second, m + each.second);
                result.first = min (result.first, max (up [each.first], down [each.first]));
                result.second = max (result.second, max (up [each.first], down [each.first]));
                Q.push (each.first);
            }
        }
    }
    return result;
}
void computeRadiusAndDiameter ()
{
    for (int x = 1; x <= nodes; x++)
    {
        if (!visited [x])
        {
            dfs (x);
            subtrees.push_back (bfs (x));
        }
    }
}
ll minimum ()
{
    pair <ll, ll> firstmax = {-1, -1};   int firstindex = -1;
    pair <ll, ll> secondmax = {-1, -1};  int secondindex = -1;
    ll current = 0;
    for (int x = 0; x < (int) subtrees.size(); x++)
    {
        if (firstmax.first < subtrees [x].first)
        {
            secondmax = firstmax;
            secondindex = firstindex;
            firstmax = subtrees [x];
            firstindex = x;
        }
        else if  (secondmax.first < subtrees [x].first)
        {
            secondmax = subtrees [x];
            secondindex = x;
        }
    }
    if (secondmax.first != -1)
    {
        current = max (firstmax.first, secondmax.first + 1);
        for (int x = 0; x < (int) subtrees.size(); x++)
        {
            if (firstindex != x && secondindex != x)
            {
                current = max (current, subtrees [x].first + 1);
            }
        }
        return current;
    }
    return firstmax.first;
}
ll maximum ()
{
    ll current = subtrees [0].second;
    for (int x = 1; x < (int)subtrees.size(); x++)
    {
        current += subtrees [x].second + 1;
    }
    return current;
}
int main ()
{
    scanf ("%d%d%d", &nodes, &edges, &queries);
    for (int x = 0; x < edges; x++)
    {
        scanf ("%d%d%d", &a, &b, &c);
        adj [a].push_back ({b, c});
        adj [b].push_back ({a, c});
    }
    computeRadiusAndDiameter ();
    if (queries == 1)
    {
        printf ("%lld", maximum());
    }
    else
    {
        printf ("%lld", minimum());
    }
    return 0;
}