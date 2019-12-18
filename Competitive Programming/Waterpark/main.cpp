#include <bits/stdc++.h>
using namespace std;
vector <int> adjacencyMatrix [10000];
vector <int> path;
int numPaths [10000];
int dfs (int start, int end)
{
    if (numPaths [start] != 0)
    {
        return numPaths [start];
    }
    for (int each: adjacencyMatrix [start])
    {
        if (each == end)
        {
            numPaths [start]++;
        }
        else
        {
            numPaths [start] += dfs (each, end);
        }
    }
    return numPaths [start];
}
int main ()
{
    int n;
    int start, end;
    scanf ("%d", &n);
    scanf ("%d%d", &start, &end);
    while (start != 0)
    {
        adjacencyMatrix [start].push_back(end);
        scanf ("%d%d", &start, &end);
    }
    cout << dfs (1, n) << endl;
}
