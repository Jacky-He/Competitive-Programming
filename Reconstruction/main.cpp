#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int parent [100001];
int n, m, k;
int a, b;
ll c;
int temp;
vector <int> crucial;
struct Edge
{
    int from, to;
    ll weight;
};
vector <Edge> allEdges;
bool compareEdges (Edge e1, Edge e2) {return (e1.weight < e2.weight);}
int Find (int child)
{
    if (parent [child] == child)
    {
        return child;
    }
    return parent [child] = Find (parent [child]);
}
void Union (int s1, int s2)
{
    parent [s1] = s2;
}
bool allin ()
{
    for (int x = 0; x < (int)crucial.size() - 1; x++)
    {
        if (Find (crucial [x]) != Find (crucial [x + 1]))
        {
            return false;
        }
    }
    return true;
}
int main ()
{
    scanf ("%d%d%d", &n, &m, &k);
    for (int x = 0; x < k; x++)
    {
        scanf ("%d", &temp);
        crucial.push_back (temp);
    }
    for (int x = 0; x < n; x++)
    {
        parent [x] = x;
    }
    for (int x = 0; x < n - 1; x++)
    {
        scanf ("%d%d%lld", &a, &b, &c);
        Edge hi;
        hi.from = a;
        hi.to = b;
        hi.weight = c;
        allEdges.push_back (hi);
    }
    sort (allEdges.begin(), allEdges.end(), compareEdges);
    ll cost = 0;
    for (Edge each: allEdges)
    {
        if (allin())
        {
            break;
        }
        int s1 = Find (each.from);
        int s2 = Find (each.to);
        if (s1 != s2)
        {
            Union (s1, s2);
            cost += each.weight;
        }
    }
    printf ("%lld\n", cost);
    return 0;
}
