#include <bits/stdc++.h>
using namespace std;
int favteam, games;
int a, b, c, d;
int played [5][5];
vector <pair <int, int>> uncertain;
bool letsSee ()
{
    int sum = 0;
    for (int x = 1; x < 5; x++)
    {
        if (x != favteam)
        {
            sum += played [favteam][x];
        }
    }
    for (int x = 1; x < 5; x++)
    {
        int temp = 0;
        if (x != favteam)
        {
            for (int y = 1; y < 5; y++)
            {
                if (x != y)
                {
                    temp += played [x][y];
                }
            }
            if (temp >= sum)
            {
                return false;
            }
        }
    }
    return true;
}
int solve (int index, int state)
{
    if (index != -1)
    {
        if (state == -1)
        {
            played [uncertain [index].first][uncertain [index].second] = 0;
            played [uncertain [index].second][uncertain [index].first] = 3;
        }
        else if (state == 0)
        {
            played [uncertain [index].first][uncertain [index].second] = 1;
            played [uncertain [index].second][uncertain [index].first] = 1;
        }
        else if (state == 1)
        {
            played [uncertain [index].first][uncertain [index].second] = 3;
            played [uncertain [index].second][uncertain [index].first] = 0;
        }
    }
    if (index == (int)uncertain.size() - 1)
    {
        return letsSee ();
    }
    int result = 0;
    for (int x = -1; x < 2; x++)
    {
        result += solve (index + 1, x);
    }
    return result;
}
int main ()
{
    scanf ("%d%d", &favteam, &games);
    for (int x = 0; x < 5; x++)
    {
        memset (played [x], -1, sizeof (played [x]));
    }
    for (int x = 0; x < games; x++)
    {
        scanf ("%d%d%d%d", &a, &b, &c, &d);
        if (c == d)
        {
            played [a][b] = 1;
            played [b][a] = 1;
        }
        else if (c < d)
        {
            played [a][b] = 0;
            played [b][a] = 3;
        }
        else
        {
            played [b][a] = 0;
            played [a][b] = 3;
        }
    }
    for (int x = 1; x < 5; x++)
    {
        for (int y = x + 1; y < 5; y++)
        {
            if (played [x][y] == -1)
            {
                uncertain.push_back ({x, y});
            }
        }
    }
    printf ("%d\n", solve (-1, -1));
    return 0;
}