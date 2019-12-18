#include <bits/stdc++.h>
using namespace std;
int startx, starty;
int finishx, finishy;
int dis [12][12];
bool visited [12][12]; //cols, rows
queue<pair<int, int>> Q;
vector <pair<int, int>> getAdj (pair<int, int> p)
{
    vector <pair<int,int>> v;
    v.push_back ({p.first + 2, p.second + 1});
    v.push_back ({p.first + 1, p.second + 2});
    v.push_back ({p.first + 2, p.second - 1});
    v.push_back ({p.first + 1, p.second - 2});
    v.push_back ({p.first - 2, p.second + 1});
    v.push_back ({p.first - 1, p.second + 2});
    v.push_back ({p.first - 2, p.second - 1});
    v.push_back ({p.first - 1, p.second - 2});
    return v;
}
int main ()
{
    scanf ("%d%d%d%d", &startx, &starty, &finishx, &finishy);
    memset (visited [0], 1, sizeof (visited [0]));
    memset (visited [1], 1, sizeof (visited [1]));
    memset (visited [10], 1, sizeof (visited [10]));
    memset (visited [11], 1, sizeof (visited [11]));
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 12; y++)
        {
            visited [y][x] = 1;
        }
    }
    for (int x = 10; x < 12; x++)
    {
        for (int y = 0; y < 12; y++)
        {
            visited [y][x] = 1;
        }
    }
    for (int x = 0; x < 12; x++)
    {
        memset (dis [x], 0x3f, sizeof (dis[x]));
    }
    Q.push ({startx + 1, starty + 1});
    dis [startx + 1][starty + 1] = 0;
    visited [startx + 1][starty + 1] = 1;
    while (!Q.empty())
    {
        pair <int, int> temp = Q.front();
        Q.pop();
        vector <pair<int, int>> adj = getAdj (temp);
        for (pair <int, int> each: adj)
        {
            if (!visited [each.first][each.second])
            {
                visited [each.first][each.second] = 1;;
                dis [each.first][each.second] = dis [temp.first][temp.second] + 1;
                Q.push (each);
            }
        }
    }
    printf ("%d\n", dis [finishx + 1][finishy + 1]);
    return 0;
}
