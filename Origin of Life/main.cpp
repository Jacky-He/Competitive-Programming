#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int m, n, a, b, c;
string line;
int current;
int dp [1 << 20];
bool possible [1 << 20];
pair <int, int> moves [8] = {{1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};
queue <int> Q;
bool out (pair <int, int> p)
{
    return p.first < 0 || p.second < 0 || p.first >= m || p.second >= n;
}
int surrounding (pair <int, int> coordinate, int curr)
{
    int cnt = 0;
    int x = coordinate.first;
    int y = coordinate.second;
    for (pair <int, int> each : moves)
    {
        if (!out({x + each.first, y + each.second}) && ((curr >> (y + each.second + (x + each.first)*n))&1))
        {
            cnt++;
        }
    }
    return cnt;
}
int nextGen (int curr)
{
    int next = 0;
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < n; y++)
        {
            int live = surrounding ({x, y}, curr);
            int thiscell = ((curr >> (y + x*n))&1);
            if (thiscell) //if alive
            {
                if (live < a || live > b)
                {
                    thiscell = 0;
                }
            }
            else //if dead
            {
                if (live > c)
                {
                    thiscell = 1;
                }
            }
            next += (thiscell << (y + x*n));
        }
    }
    return next;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> m >> n >> a >> b >> c;
    memset (dp, 0x3f, sizeof (dp));
    for (int x = 0; x < m; x++)
    {
        cin >> line;
        for (int y = 0; y < n; y++)
        {
            current += ((line [y] == '*') << (y + x*n));
        }
    }
    for (int x = 0; x < (1 << n*m); x++)
    {
        int nextthing = nextGen (x);
        possible [nextthing] = true;
    }
    for (int x = 0; x < (1 << n*m); x++)
    {
        if (!possible [x])
        {
            Q.push (x);
            dp [x] = 0;
        }
    }
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        int next = nextGen (temp);
        if (dp [next] > dp [temp] + 1)
        {
            dp [next] = dp [temp] + 1;
            Q.push (next);
        }
    }
    cout << (dp [current] == INF? -1 : dp [current]) << endl;
    return 0;
}



/*
4 5 2 3 2
.****
.****
.****
.****



 */
