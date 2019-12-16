#include <bits/stdc++.h>
using namespace std;
int cities, roads, destinations;
int parent [10001];
vector <int> needs;
int some;
struct Edges
{
    int first, second, weight;
};
vector <Edges> allEdges;
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
bool compareEdges (Edges e1, Edges e2) {return e1.weight > e2.weight;}
bool sameset ()
{
    for (int i = 0; i < (int)needs.size() - 1; i++)
    {
        if (Find (needs [i]) != Find (needs [i + 1]))
        {
            return false;
        }
    }
    return true;
}
int main ()
{
    scanf ("%d%d%d", &cities, &roads, &destinations);
    for (int x = 1; x <= cities; x++)
    {
        parent [x] = x;
    }
    Edges hi;
    for (int x = 0; x < roads; x++)
    {
        scanf ("%d", &hi.first);
        scanf ("%d", &hi.second);
        scanf ("%d", &hi.weight);
        allEdges.push_back (hi);
    }
    needs.push_back (1);
    for (int x = 0; x < destinations; x++)
    {
        scanf ("%d", &some);
        needs.push_back (some);
    }
    sort (allEdges.begin(), allEdges.end(), compareEdges);
    int i = 0;
    int output = 0;
    while (true)
    {
        Edges a = allEdges [i];
        int s1 = Find(a.first);
        int s2 = Find(a.second);
        if (s1 != s2)
        {
            Union (s1, s2);
            output = a.weight;
            if (sameset ())
            {
                break;
            }
        }
        i++;
    }
    printf ("%d\n", output);
    return 0;
}
