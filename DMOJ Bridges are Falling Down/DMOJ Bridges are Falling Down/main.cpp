#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll n, m, from, to;
vector <pair <ll, ll>> edges;
vector <ll> output;
pair <ll, ll> parent [100005]; //first: parent node, second, numnodes
ll total;


pair <ll, ll> Find (ll child)
{
    if (parent [child].first == child)
    {
        return {child, parent [child].second};
    }
    return parent [child] = Find (parent [child].first);
}
void Union (ll s1, ll s2)
{
    parent [s1].first = s2;
    parent [s2].second += parent [s1].second;
}

int main ()
{
    scanf ("%lld%lld", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        parent [x].first = x;
        parent [x].second = 1;
    }
    total = n*(n - 1)/2;
    for (int x = 0; x < m; x++)
    {
        scanf ("%lld%lld", &from, &to);
        edges.push_back ({from, to});
    }
    for (int x = (int)edges.size() - 1; x >= 0; x--)
    {
        pair <ll, ll> s1 = Find (edges [x].first);
        pair <ll, ll> s2 = Find (edges [x].second);
        output.push_back(total);
        if (s1.first != s2.first)
        {
            Union (s1.first, s2.first);
            total -= s1.second*s2.second;
        }
    }
    for (int x = (int)output.size() - 1; x >= 0; x--)
    {
        printf ("%lld\n", output [x]);
    }
    return 0;
}


