#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int parent [100001];
int n, m, d;
struct Edge
{
    int from, to, weight, priority;
};
vector <Edge> allEdges;
bool compareEdges (Edge e1, Edge e2) {return (e1.weight < e2.weight) || (e1.weight == e2.weight && e1.priority < e2.priority);}
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
int main ()
{
    scanf ("%d%d%d", &n, &m, &d);
    Edge hi;
    for (int x = 1; x <= n; x++)
    {
        parent [x] = x;
    }
    pair <int, int> p;
    for (int x = 1; x <= m; x++)
    {
        scanf ("%d%d%d", &hi.from, &hi.to, &hi.weight);
        if (x < n)
        {
            hi.priority = 1;
        }
        else
        {
            hi.priority = 2;
        }
        allEdges.push_back (hi);
    }
    sort (allEdges.begin(), allEdges.end(), compareEdges);
    int counter = 0;
    int cnt = 0;
    int maxweight = 0;
    for (Edge each: allEdges)
    {
        int s1 = Find (each.from);
        int s2 = Find (each.to);
        if (s1 != s2)
        {
            cnt++;
            if (maxweight < each.weight)
            {
                maxweight = each.weight;
            }
            Union(s1, s2);
            if (each.priority == 2)
            {
                counter++;
            }
        }
        if (cnt == n - 1)
        {
            break;
        }
    }
    for (int x = 1; x <= n; x++)
    {
        parent [x] = x;
    }
    for (Edge each: allEdges)
    {
        int s1 = Find (each.from);
        int s2 = Find (each.to);
        if (s1 != s2)
        {
            if (each.weight < maxweight)
            {
                Union (s1, s2);
            }
            else if (each.weight == maxweight)
            {
                if (each.priority == 1)
                {
                    Union (s1, s2);
                }
            }
            else
            {
                if (each.priority == 1 && each.weight <= d)
                {
                    counter--;
                    break;
                }
            }
        }
    }
    printf ("%d\n", counter);
    return 0;
}
