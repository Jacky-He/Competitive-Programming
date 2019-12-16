#include <bits/stdc++.h>
using namespace std;
int houses, roads, date, queries;
int from, to, weight;
int h;
pair <int, int> p;
vector <pair<int, int>> adjacencyList [2001];
int dis [2001];
queue <int> Q;
int main ()
{
    scanf ("%d%d%d%d", &houses, &roads, &date, &queries);
    for (int x = 0; x < roads; x++)
    {
        scanf ("%d%d%d", &from, &to, &weight);
        p.first = to;
        p.second = weight;
        adjacencyList [from].push_back (p);
        p.first = from;
        adjacencyList [to].push_back (p);
    }
    memset (dis, -1, sizeof (dis));
    Q.push (date);
    dis [date] = 0;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (pair <int, int> each: adjacencyList [temp])
        {
            if (dis [each.first] == -1)
            {
                dis [each.first] = each.second + dis [temp];
                Q.push (each.first);
            }
            else if (dis [each.first] > dis [temp] + each.second)
            {
                dis [each.first] = dis [temp] + each.second;
                Q.push (each.first);
            }
        }
    }
    for (int x = 0; x < queries; x++)
    {
        scanf ("%d", &h);
        printf ("%d\n", dis [h]);
    }
    return 0;
}
