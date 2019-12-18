#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int arr [1001];
int dis [1001][1001];
int n;
queue <pair <int ,int>> Q;
int main ()
{
    for (auto &di : dis)
    {
        memset (di, 0x3f, sizeof di);
    }
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &arr [x]);
    }
    dis [1][0] = 0;
    dis [2][1] = arr [2];
    Q.push ({2, 1}); //first: node, second: preceding steps;
    while (!Q.empty())
    {
        pair <int, int> temp = Q.front();
        Q.pop();
        if (temp.first - temp.second > 0 && dis [temp.first - temp.second][temp.second] > dis [temp.first][temp.second] + arr [temp.first - temp.second])
        {
            dis [temp.first - temp.second][temp.second] = dis [temp.first][temp.second] + arr [temp.first - temp.second];
            Q.push ({temp.first - temp.second, temp.second});
        }
        if (temp.first + temp.second + 1 <= n && dis [temp.first + temp.second + 1][temp.second + 1] > dis [temp.first][temp.second] + arr [temp.first + temp.second + 1])
        {
            dis [temp.first + temp.second + 1][temp.second + 1] = dis [temp.first][temp.second] + arr [temp.first + temp.second + 1];
            Q.push ({temp.first + temp.second + 1, temp.second + 1});
        }
    }
    int result = INF;
    for (int x = 0; x < 1001; x++)
    {
        result = min (result, dis [n][x]);
    }
    printf ("%d\n", result);
    return 0;
}