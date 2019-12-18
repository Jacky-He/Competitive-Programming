#include <bits/stdc++.h>
using namespace std;

int r, s;
int grid [1002][1002];
bool cool [1002][1002];
int compressed [1002];
stack<pair <int, int>> monostack; //first: height, second: index

int push (int height, int index)
{
    int res = 0;
    while (!monostack.empty() && height <= monostack.top().first)
    {
        pair <int, int> temp = monostack.top();
        monostack.pop();
        int width = (index - (monostack.empty()? 0 : monostack.top().second + 1));
        res = max (res, (width + 1)*(temp.first + 1));
    }
    monostack.push({height, index});
    return res;
}

int main ()
{
    scanf ("%d%d", &r, &s);
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < s; y++)
        {
            scanf ("%d", &grid [x][y]);
        }
    }
    for (int x = 0; x < r - 1; x++)
    {
        for (int y = 0; y < s - 1; y++)
        {
            cool [x][y] = (grid [x][y] + grid [x + 1][y + 1] <= grid [x + 1][y] + grid [x][y + 1]);
        }
    }
    int res = 0;
    for (int x = 0; x < r - 1; x++)
    {
        for (int y = 0; y < s - 1; y++)
        {
            if (!cool [x][y])
            {
                compressed [y] = 0;
            }
            compressed [y] += cool [x][y];
            res = max (res, push (compressed [y], y));
        }
        res = max (res, push (0, s - 1));
        while (!monostack.empty())
        {
            monostack.pop();
        }
    }
    printf ("%d\n", res);
    return 0;
}
