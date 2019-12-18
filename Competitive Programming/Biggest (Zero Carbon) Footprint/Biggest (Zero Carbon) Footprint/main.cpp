#include <bits/stdc++.h>
using namespace std;

int n, m, t;
bool grid [10004][10004]; //if there is a tree or not.
int X, Y;
int compressed [20004];
stack <pair <int, int>> monostack;

int push (int height, int index)  //index % 2 == 0 (even) means line, otherwise rectangle
{
    int res = 0;
    while (!monostack.empty() && monostack.top().first >= height)
    {
        pair <int, int> temp = monostack.top();
        monostack.pop();
        int h = temp.first;
        int w = (index - (monostack.empty()? 0 : monostack.top().second))/2;
        res = max (res, h*w);
    }
    monostack.push({height, index});
    return res;
}

int main ()
{
    scanf ("%d%d%d", &n, &m, &t);
    for (int x = 0; x < t; x++)
    {
        scanf ("%d%d", &X, &Y);
        grid [X][Y] = true;
    }
    for (int x = 0; x <= (n << 1); x++)
    {
        compressed [x] = 1;
    }
    int res = 0;
    for (int y = 1; y <= m; y++)
    {
        for (int x = 0; x <= (n << 1); x++)
        {
            if (x == (n << 1))
            {
                res = max (res, push (0, x));
            }
            else
            {
                res = max (res, push (compressed [x], x));
            }
            if (x % 2 == 0) //if this is a line
            {
                if (grid [x/2][y]) //if there is a tree
                {
                    compressed [x] = 1;
                }
                else
                {
                    compressed [x]++;
                }
            }
            else //if this is a rectangle
            {
                compressed [x]++;
            }
        }
        while (!monostack.empty())
        {
            monostack.pop();
        }
    }
    printf ("%d\n", res);
    return 0;
}
