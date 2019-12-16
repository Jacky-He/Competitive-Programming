#include <bits/stdc++.h>
using namespace std;
char graph [1001][1001];
int n, m;
bool visited [1001][1001];
int dis [1001][1001];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    string line;
    getline (cin, line);
    for (int  x= 0; x < 1001; x++)
    {
        memset (graph [x], 'X', sizeof (graph[x]));
        memset (dis [x], -1, sizeof (dis [x]));
    }
    pair <int, int> source;
    pair <int, int> destination;
    for (int x = 1; x <= n; x++)
    {
        getline (cin, line);
        for(int y = 1; y <= m; y++)
        {
            graph [x][y] = line [y - 1];
            if (line [y - 1] == 's')
            {
                source = make_pair (x, y);
            }
            else if (line [y - 1] == 'e')
            {
                destination = make_pair (x, y);
            }
        }
    }
    for (int x = 0; x < 1001; x++)
    {
        for (int y = 0; y < 1001; y++)
        {
            if (graph [x][y] == 'X')
            {
                visited [x][y] = true;
            }
        }
    }
    queue <pair<int, int>> Q;
    dis [source.first][source.second] = 0;
    Q.push (source);
    while (!Q.empty())
    {
        pair <int, int> temp = Q.front();
        Q.pop();
        vector <pair <int, int>> need;
        need.push_back (make_pair(temp.first + 1, temp.second));
        need.push_back (make_pair (temp.first - 1, temp.second));
        need.push_back (make_pair (temp.first, temp.second + 1));
        need.push_back (make_pair (temp.first,temp.second - 1));
        for (pair <int, int> each: need)
        {
            if (!visited [each.first][each.second])
            {
                visited [each.first][each.second] = 1;
                dis [each.first][each.second] = 1 + dis [temp.first][temp.second];
                Q.push (each);
            }
        }
    }
    printf ("%d\n", dis [destination.first][destination.second] == -1? -1:dis [destination.first][destination.second] - 1);
    return 0;
}
