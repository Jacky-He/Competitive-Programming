#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair <int, int> point;
bool visited [101][101];
int dis [101][101];
int testcases;
int rows, cols, pr, pc, kr, kc;
queue <point> Q;
bool in (point p)
{
    return p.first >= 1 && p.first <= rows && p.second >= 1 && p.second <= cols;
}
vector <point> adj (point curr)
{
    vector <point> v;
    if (in ({curr.first - 2, curr.second + 1}))
    {
        v.push_back ({curr.first - 2, curr.second + 1});
    }
    if (in ({curr.first - 1, curr.second + 2}))
    {
        v.push_back ({curr.first - 1, curr.second + 2});
    }
    if (in ({curr.first + 1, curr.second + 2}))
    {
        v.push_back ({curr.first + 1, curr.second + 2});
    }
    if (in ({curr.first + 2, curr.second + 1}))
    {
        v.push_back ({curr.first + 2, curr.second + 1});
    }
    if (in ({curr.first + 2, curr.second - 1}))
    {
        v.push_back ({curr.first + 2, curr.second - 1});
    }
    if (in ({curr.first + 1, curr.second - 2}))
    {
        v.push_back ({curr.first + 1, curr.second - 2});
    }
    if (in ({curr.first - 1, curr.second - 2}))
    {
        v.push_back ({curr.first - 1, curr.second - 2});
    }
    if (in ({curr.first - 2, curr.second - 1}))
    {
        v.push_back ({curr.first - 2, curr.second - 1});
    }
    return v;
}

int main ()
{
    scanf ("%d", &testcases);
    while (testcases--)
    {
        scanf ("%d%d%d%d%d%d", &rows, &cols, &pr, &pc, &kr, &kc);
        for (int x = 0; x < 101; x++)
        {
            memset (visited [x], false, sizeof (visited [x]));
            memset (dis [x], 0x3f, sizeof (dis [x]));
        }
        visited [kr][kc] = true;
        dis [kr][kc] = 0;
        bool yes = false;
        Q.push ({kr, kc});
        while (!Q.empty())
        {
            point temp = Q.front();
            Q.pop();
            for (point each: adj (temp))
            {
                if (!visited [each.first][each.second])
                {
                    yes = true;
                    visited [each.first][each.second] = true;
                    dis [each.first][each.second] = dis [temp.first][temp.second] + 1;
                    Q.push (each);
                }
            }
        }
        int win = INF, stalemate = INF;
        for (int x = pr ; x < rows; x++)
        {
            if (x - pr >= dis [x][pr] && (x - pr - dis [x][pr])%2 == 0)
            {
                win = min (win, x - pr);
            }
            if (x - pr >= dis [x + 1][pr] && (x - pr - dis [x + 1][pr])%2 == 0)
            {
                stalemate = min (stalemate, x - pr);
            }
        }
        if (win != INF)
        {
            printf ("Win in %d knight move(s).\n", win);
        }
        else if (stalemate != INF)
        {
            printf ("Stalemate in %d knight move(s).\n", stalemate);
        }
        else if (pr == rows || !yes)
        {
            printf ("Loss in %d knight move(s).\n", 0);
        }
        else
        {
            printf ("Loss in %d knight move(s).\n", rows - pr - 1);
        }
    }
    return 0;
}

