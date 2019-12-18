#include <bits/stdc++.h>
using namespace std;
int numNodes, numEdges;
int from, to;
vector <int> adjacencyMatrix [1000001];
double probability [1000001];
int main ()
{
    scanf ("%d%d", &numNodes, &numEdges);
    for (int x = 0; x < numEdges; x++)
    {
        scanf ("%d%d", &from, &to);
        adjacencyMatrix [from].push_back(to);
    }
    probability [1] = 1;
    for (int n = 1; n <= numNodes; n++)
    {
        if (adjacencyMatrix [n].empty())
        {
            printf ("%.9g\n", probability [n]);
        }
        else
        {
            for (int each: adjacencyMatrix [n])
            {
                probability [each] += probability [n]/(double)adjacencyMatrix [n].size();
            }
        }
    }
    return 0;
}
