#include <bits/stdc++.h>
using namespace std;
int rows, cols;
string line;
int graph [104][104];
int dp [104][104][3]; //the previous one was 0: right 1: up 2: down;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> rows >> cols;
    while (rows != 0 && cols != 0)
    {
        for (int x = 1; x <= rows; x++)
        {
            cin >> line;
            for (int y = 1; y <= cols; y++)
            {
                if (line [y - 1] == '.')
                {
                    graph [x][y] = 0;
                }
                else if (line [y - 1] == '*')
                {
                    graph [x][y] = -1;
                }
                else
                {
                    graph [x][y] = line [y - 1] - '0';
                }
            }
        }
        for (int x = 0; x < 104; x++)
        {
            for (int y = 0; y < 104; y++)
            {
                memset (dp [x][y], -1, sizeof (dp [x][y]));
            }
        }
        dp [rows][1][1] = graph [rows][1];
        for (int x = rows - 1; x >= 1; x--)
        {
            if (graph [x][1] != -1)
            {
                dp [x][1][1] = dp [x + 1][1][1] + graph [x][1];
            }
            else
            {
                break;
            }
        }
        for (int y = 2; y <= cols; y++)
        {
            for (int x = rows; x >= 1; x--)
            {
                if (graph [x][y] != -1)
                {
                    if (dp [x][y - 1][1] != -1 || dp [x][y - 1][0] != -1 || dp [x][y - 1][2] != -1)
                    {
                        dp [x][y][0] = max(max (dp [x][y - 1][1], dp [x][y - 1][0]), dp [x][y - 1][2]) + graph [x][y];
                    }
                    if (x != rows)
                    {
                        if (dp [x + 1][y][1] != -1 || dp [x + 1][y][0] != -1)
                        {
                            dp [x][y][1] = max(dp [x + 1][y][1], dp [x + 1][y][0]) + graph [x][y];
                        }
                    }
                }
            }
            for (int x = 1; x <= rows; x++)
            {
                if (graph [x][y] != -1)
                {
                    if (x != 1)
                    {
                        if (dp [x - 1][y][2] != -1 || dp [x - 1][y][0] != -1)
                        {
                            dp [x][y][2] = max (dp [x - 1][y][2], dp [x - 1][y][0]) + graph [x][y];
                        }
                    }
                }
            }
        }
        cout << max (max (dp [rows][cols][0], dp [rows][cols][1]), dp [rows][cols][2]) << endl;
        cin >> rows >> cols;
    }
    return 0;
}
