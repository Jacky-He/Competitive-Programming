#include <bits/stdc++.h>
using namespace std;
int nodes, edges, shops;
int from, to, weight;
int shop, price;
int destination;
vector <pair<int, int>> adj [5001];
queue <int> Q;
int dis [5001];
int prices [5001];
int main ()
{
    scanf ("%d%d", &nodes, &edges);
    for (int x = 0; x < edges; x++)
    {
        scanf ("%d%d%d", &from, &to, &weight);
        adj [from].push_back (make_pair (to, weight));
        adj [to].push_back (make_pair (from, weight));
    }
    memset (dis, -1, sizeof (dis));
    memset (prices, -1, sizeof (prices));
    scanf ("%d", &shops);
    for (int x = 0; x < shops; x++)
    {
        scanf ("%d%d", &shop, &price);
        prices [shop] = price;
    }
    scanf ("%d", &destination);
    Q.push (destination);
    dis [destination] = 0;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (pair <int, int> each: adj [temp])
        {
            if (dis [each.first] == -1 || dis [each.first] > dis [temp] + each.second)
            {
                dis [each.first] = dis [temp] + each.second;
                Q.push (each.first);
            }
        }
    }
    int minCost = 2147483647;
    for (int x = 0; x < 5001; x++)
    {
        if (prices [x] != -1 && dis [x] != -1)
        {
            if (minCost > prices [x] + dis [x])
            {
                minCost = prices [x] + dis [x];
            }
        }
    }
    printf ("%d\n", minCost);
    return 0;
}
