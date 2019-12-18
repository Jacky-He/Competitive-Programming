#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int weight, first, second;
};
vector <Edge> alledges;
int vertices;
int edges;
int k;
int parent [100001];
int sum;
int s1, s2;
int numSets;
int Find (int child)
{
    if (parent [child] == child)
    {
        return child;
    }
    return parent [child] = Find (parent [child]);
}
void Union (int set1, int set2)
{
    parent [set1] = set2;
}
bool compareEdges (Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}
int main ()
{
    scanf ("%d%d", &vertices, &k);
    edges = vertices - 1;
    numSets = vertices;
    for (int x = 1; x <= vertices; x++)
    {
        parent [x] = x;
    }
    for (int x = 1; x <= edges; x++)
    {
        Edge hi;
        scanf ("%d", &hi.weight);
        hi.first = x;
        hi.second = x + 1;
        alledges.push_back (hi);
        if (x + k <= vertices)
        {
            hi.weight = 0;
            hi.first = x;
            hi.second = x + k;
            alledges.push_back (hi);
        }
    }
    sort (alledges.begin(), alledges.end(), compareEdges);
    for (Edge each: alledges)
    {
        s1 = Find (each.first);
        s2 = Find (each.second);
        if (s1 != s2)
        {
            Union (s1, s2);
            numSets--;
            sum += each.weight;
        }
        if (numSets == 1)
        {
            break;
        }
    }
    printf ("%d\n", sum);
    return 0;
}
