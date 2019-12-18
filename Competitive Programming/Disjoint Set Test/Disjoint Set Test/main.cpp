#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int weight, first, second;
};
int vertices, edges;
int parent [1000001];
set <int> output;
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
int main ()
{
    scanf ("%d%d", &vertices, &edges);
    Edge hi;
    int numSets = vertices;
    bool connected = false;
    for (int x = 1; x <= vertices; x++)
    {
        parent [x] = x;
    }
    for (int x = 1; x <= edges; x++)
    {
        hi.weight = x;
        scanf ("%d", &hi.first);
        scanf ("%d", &hi.second);
        int s1 = Find (hi.first);
        int s2 = Find (hi.second);
        if (s1 != s2)
        {
            Union (s1, s2);
            numSets--;
            output.insert (hi.weight);
        }
        if (numSets == 1)
        {
            connected = true;
            break;
        }
    }
    if (!connected)
    {
        printf ("Disconnected Graph\n");
    }
    else
    {
        for (int each: output)
        {
            printf ("%d\n", each);
        }
    }
    return 0;
}

