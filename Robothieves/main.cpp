#include <bits/stdc++.h>
using namespace std;
bool visited [101][101];
int n, m;
int dis [101][101];
char graph [101][101];
string line;
int initx, inity;
queue <pair <int, int>> Q;
bool conveyor (pair <int, int> p)
{
    int x = p.first; int y = p.second;
    return graph [x][y] == 'L' || graph [x][y] == 'R' || graph [x][y] == 'U' || graph [x][y] == 'D';
}
vector <pair <int, int>> adj (pair <int, int> p)
{
    vector <pair <int, int>> v;
    int x = p.first; int y = p.second;
    if (conveyor (p))
    {
        if (graph [x][y] == 'L' && !visited [x][y - 1])
        {
            v.push_back ({x, y - 1});
        }
        else if (graph [x][y] == 'R' && !visited [x][y + 1])
        {
            v.push_back ({x, y + 1});
        }
        else if (graph [x][y] == 'U' && !visited [x - 1][y])
        {
            v.push_back ({x - 1, y});
        }
        else if (graph [x][y] == 'D' && !visited [x + 1][y])
        {
            v.push_back ({x + 1, y});
        }
        return v;
    }
    if (!visited [x][y + 1])
    {
        v.push_back ({x, y + 1});
    }
    if (!visited [x + 1][y])
    {
        v.push_back ({x + 1, y});
    }
    if (!visited [x - 1][y])
    {
        v.push_back ({x - 1, y});
    }
    if (!visited [x][y - 1])
    {
        v.push_back ({x, y - 1});
    }
    return v;
}
bool canbeseen (pair <int, int> p)
{
    int x = p.first; int y = p.second;
    if (conveyor (p))
    {
        return false;
    }
    for (int i = x; i <= n; i++)
    {
        if (graph [i][y] == 'W')
        {
            break;
        }
        else if (graph [i][y] == 'C')
        {
            return true;
        }
    }
    for (int i = x; i >= 1; i--)
    {
        if (graph [i][y] == 'W')
        {
            break;
        }
        else if (graph [i][y] == 'C')
        {
            return true;
        }
    }
    for (int i = y; i <= m; i++)
    {
        if (graph [x][i] == 'W')
        {
            break;
        }
        else if (graph [x][i] == 'C')
        {
            return true;
        }
    }
    for (int i = y; i >= 1; i--)
    {
        if (graph [x][i] == 'W')
        {
            break;
        }
        else if (graph [x][i] == 'C')
        {
            return true;
        }
    }
    return false;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int x = 0; x < 101; x++)
    {
        memset (dis [x], -1, sizeof (dis [x]));
    }
    for (int x = 1; x <= n; x++)
    {
        cin >> line;
        for (int y = 1; y <= m; y++)
        {
            graph [x][y] = line [y - 1];
            if (graph [x][y] == 'S')
            {
                initx = x; inity = y;
            }
            else if (graph [x][y] == 'W' || graph [x][y] == 'C')
            {
                visited [x][y] = true;
            }
        }
    }
    if (!canbeseen ({initx, inity}))
    {
        dis [initx][inity] = 0;
        Q.push ({initx, inity});
        while (!Q.empty())
        {
            pair <int, int> temp = Q.front();
            Q.pop();
            for (pair <int, int> each: adj(temp))
            {
                if (!canbeseen (each)) //can't be seen
                {
                    if (conveyor (temp))
                    {
                        if (dis [each.first][each.second] == -1 || dis [each.first][each.second] > dis [temp.first][temp.second])
                        {
                            dis [each.first][each.second] = dis [temp.first][temp.second];
                            Q.push (each);
                        }
                    }
                    else
                    {
                        if (dis [each.first][each.second] == -1 || dis [each.first][each.second] > dis [temp.first][temp.second] + 1)
                        {
                            dis [each.first][each.second] = dis [temp.first][temp.second] + 1;
                            Q.push (each);
                        }
                    }
                }
            }
        }
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            if (graph [x][y] == '.')
            {
                cout << dis [x][y] << endl;
            }
        }
    }
    return 0;
}
