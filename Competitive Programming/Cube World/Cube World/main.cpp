#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, num;
int result = 0;
int grid [25][25];
bool visited [25][25];

pair <int, int> moves [4] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool withinbound (pair <int, int> node)
{
    return node.first >= 1 && node.second >= 1 && node.first <= n && node.second <= m;
}
bool onTheEdge (pair <int, int> node)
{
    return !withinbound (node);
}
vector <pair <int, int>> adj (pair <int, int> node)
{
    vector <pair <int, int>> v;
    for (pair <int, int> move: moves)
    {
        if (withinbound({node.first + move.first, node.second + move.second}))
        {
            v.push_back ({node.first + move.first, node.second + move.second});
        }
    }
    return v;
}

int dfs (pair <int, int> node)
{
    visited [node.first][node.second] = true;
    if (onTheEdge (node))
    {
        return grid [node.first][node.second];
    }
    int result = grid [node.first][node.second];
    int result2 = INF;
    int result3 = INF;
    for (pair <int, int> each : adj (node))
    {
        if (!visited [each.first][each.second])
        {
            result2 = min (result2, grid [node.first + 1][node.second]);
            result3 = min (result3, dfs (each));
        }
    }
    result = max (result, result2);
    return result3 == INF? result : max (result, result3);
}

int main ()
{
    for (int i = 0; i < 5; i++)
    {
        result = 0;
        for (int x = 0; x < 25; x++)
        {
            memset (grid [x], 0, sizeof (grid [x]));
        }
        scanf ("%d%d", &n, &m);
        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= m; y++)
            {
                scanf ("%d", &num);
                grid [x][y] = num;
            }
        }

        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= m; y++)
            {
                int res = INF;
                if (onTheEdge({x, y}))
                {
                    res = grid [x][y];
                }
                else
                {
                    for (pair <int, int> each : adj ({x, y}))
                    {
                        memset (visited, false, sizeof (visited));
                        visited [x][y] = true;
                        res = min (res, dfs ({each.first, each.second}));
                    }
                    res = max (grid [x][y], res);
                }
                result += res - grid [x][y];
                cout << res << " ";
            }
            cout << endl;
        }
        printf ("%d\n", result);
    }
    
    return 0;
}

/*
 3 6
 3 3 4 4 4 2
 3 1 3 2 1 4
 7 3 1 6 4 1
 
 
 5 5
 3 3 3 3 3
 3 4 5 4 3
 3 5 6 5 3
 3 4 5 4 3
 3 3 3 3 3
 
 
 5 5
 1 3 7 3 3
 3 4 3 4 3
 3 5 6 5 3
 3 4 5 4 3
 3 3 7 3 9
 
 5 5
 3 3 3 3 3
 3 2 2 2 3
 3 2 1 2 3
 3 2 2 2 3
 3 3 4 3 3
 
 
 */
