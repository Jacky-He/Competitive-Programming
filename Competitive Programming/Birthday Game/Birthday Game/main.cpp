#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, a;
int matrix [200001];
int adj [200001];
pair <int, int> dis [200001]; //first: distance, second: graph
bool visited [200001];
unordered_set <int> visitedNow;
int main ()
{
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &a);
        adj [x] = a;
        matrix [x] = x;
    }
    int rounds = INF;
    int graph = 0;
    for (int person = 1; person <= n; person++)
    {
        if (!visited [person])
        {
            dis [person].first = 0;
            dis [person].second = graph;
            int current = person;
            int temp = 0;
            while (!visited [current])
            {
                visited [current] = true;
                if (!visited [adj[current]])
                {
                    dis [adj[current]].first = dis [current].first + 1;
                    dis [adj[current]].second = graph;
                }
                else
                {
                    temp = dis [current].first + 1;
                }
                current = adj [current];
            }
            if (dis[current].second == graph)
            {
                rounds = min (rounds, temp - dis[current].first);
            }
            graph++;
        }
    }
    printf ("%d\n", rounds);
}
