#include <bits/stdc++.h>
using namespace std;
struct edge {int from, to, weight;};
int pens, temp, corner, curr, first, cost;

vector <int> connect [1001][1001];
int costs [1001][1001];
int parent [101];
vector <pair <int, int>> pensedges [1001];
vector <edge> allEdges;
bool cmp (edge e1, edge e2) {return e1.weight < e2.weight;}
edge makeedge (int n1, int n2, int n3) {edge e; e.from = n1; e.to = n2; e.weight = n3; return e;}
void Union (int s1, int s2)
{
    parent [s1] = s2;
}
int Find (int child)
{
    if (parent [child] == child)
    {
        return child;
    }
    return parent [child] = Find (parent [child]);
}
int main ()
{
    scanf ("%d", &pens);
    for (int x = 1; x <= pens; x++)
    {
        scanf ("%d", &temp);
        scanf ("%d", &first);
        curr = first;
        for (int y = 1; y < temp; y++)
        {
            scanf ("%d", &corner);
            pensedges [x].push_back ({curr, corner});
            curr = corner;
        }
        pensedges [x].push_back ({corner, first});
        for (int y = 0; y < temp; y++)
        {
            scanf ("%d", &cost);
            costs [pensedges [x][y].first][pensedges [x][y].second] = cost;
            costs [pensedges [x][y].second][pensedges [x][y].first] = cost;
            connect [pensedges [x][y].first][pensedges [x][y].second].push_back (x);
            connect [pensedges [x][y].second][pensedges [x][y].first].push_back (x);
        }
    }
    for (int x = 0; x < 101; x++)
    {
        parent [x] = x;
    }
    for (int x = 0; x < 1001; x++)
    {
        for (int y = 0; y < 1001; y++)
        {
            if (connect [x][y].size() == 1)
            {
                allEdges.push_back (makeedge (0, connect[x][y][0], costs [x][y]));
            }
            else if (connect [x][y].size() > 1)
            {
                for (int i = 0; i < connect [x][y].size(); i++)
                {
                    for (int j = i + 1; j < connect [x][y].size(); j++)
                    {
                        allEdges.push_back (makeedge (connect [x][y][i], connect [x][y][j], costs [x][y]));
                    }
                }
            }
        }
    }
    sort (allEdges.begin(), allEdges.end(), cmp);
    int cnt = 0;
    int minweight = 0;
    for (edge each: allEdges)
    {
        if (each.from != 0 && each.to != 0)
        {
            int s1 = Find (each.from);
            int s2 = Find (each.to);
            if (s1 != s2)
            {
                cnt++;
                Union (s1, s2);
                minweight += each.weight;
            }
            if (cnt == pens - 1)
            {
                break;
            }
        }
    }
    for (int x = 0; x < 101; x++)
    {
        parent [x] = x;
    }
    cnt = 0;
    int secondweight = 0;
    for (edge each: allEdges)
    {
        int s1 = Find (each.from);
        int s2 = Find (each.to);
        if (s1 != s2)
        {
            cnt++;
            Union (s1, s2);
            secondweight += each.weight;
        }
        if (cnt == pens)
        {
            break;
        }
    }
    printf ("%d\n", min (minweight, secondweight));
    return 0;
}