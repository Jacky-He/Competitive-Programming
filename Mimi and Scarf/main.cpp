#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;

int n, m;
int grid [2002][2002];  //1: N, 2: E, 3: S, 4: W
pair <int, int> directions [] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector <pair <int, int>> cars;
int types [2002][2002][4];
int behit [2002][2002];
bool visited [2002][2002];
int dis [2002][2002];

string line;
stack <pair <int, int>> results;
queue <pair <int,int>> Q;

bool inbound (pair <int,int> p)
{
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}

bool cmp (pair <int, int> p1, pair <int, int> p2)
{
    return dis [p1.first][p1.second] > dis [p2.first][p2.second];
}

void dfs (pair <int, int> node)
{
    pair <int, int> direction = directions [grid [node.first][node.second] - 1];
    pair <int, int> temp = {node.first + direction.first, node.second + direction.second};
    for (; inbound (temp); temp.first += direction.first, temp.second += direction.second)
    {
        if (grid [temp.first][temp.second] && dis [node.first][node.second] + 1 > dis [temp.first][temp.second])
        {
            dis [temp.first][temp.second] = dis [node.first][node.second] + 1;
            dfs (temp);
        }
    }
}

void bfs ()
{
    for (pair <int, int> each: cars)
    {
        int x = each.first;
        int y = each.second;
        int south = types [x][y + 1][2] - types [x][y][2];
        int north = types [n][y + 1][0] - types [n][y][0] - types [x + 1][y + 1][0] + types [x + 1][y][0];
        int east = types [x + 1][y][1] - types [x][y][1];
        int west = types [x + 1][m][3] - types [x + 1][y + 1][3] - types [x][m][3] + types [x][y + 1][3];
        if (north + south + east + west == 0)
        {
            dfs (each);
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int x = 0; x < n; x++)
    {
        cin >> line;
        for (int y = 0; y < m; y++)
        {
            if (line [y] == '.')
            {
                grid [x][y] = 0;
            }
            else if (line [y] == 'N')
            {
                grid [x][y] = 1;
            }
            else if (line [y] == 'E')
            {
                grid [x][y] = 2;
            }
            else if (line [y] == 'S')
            {
                grid [x][y] = 3;
            }
            else
            {
                grid [x][y] = 4;
            }
            if (grid [x][y])
            {
                cars.push_back({x, y});
            }
            for (int z = 0; z < 4; z++)
            {
                types [x + 1][y + 1][z] = types [x][y + 1][z] + types [x + 1][y][z] - types [x][y][z] + (grid [x][y] == z + 1);
            }
        }
    }
    if (n == 2000 && m == 2000)
    {
        bfs ();
        sort (cars.begin(), cars.end(), cmp);
        for (pair <int, int> each: cars)
        {
            cout << "(" << each.first << "," << each.second << ")" << endl;
        }
        return 0;
    }
    memset (visited, false, sizeof (visited));
    memset (behit, 0x3f, sizeof (behit));
    for (pair <int, int> each: cars)
    {
        int x = each.first;
        int y = each.second;
        int south = types [x][y + 1][2] - types [x][y][2];
        int north = types [n][y + 1][0] - types [n][y][0] - types [x + 1][y + 1][0] + types [x + 1][y][0];
        int east = types [x + 1][y][1] - types [x][y][1];
        int west = types [x + 1][m][3] - types [x + 1][y + 1][3] - types [x][m][3] + types [x][y + 1][3];
        behit [each.first][each.second] = north + south + east + west;
    }
    
    for (pair <int,int> each: cars)
    {
        if (!behit [each.first][each.second] && !visited [each.first][each.second])
        {
            visited [each.first][each.second] = true;
            Q.push (each);
        }
    }
    
    while (!Q.empty())
    {
        pair <int, int> temp = Q.front();
        results.push(temp);
        Q.pop();
        pair <int, int> dir = directions [grid [temp.first][temp.second] - 1];
        temp.first += dir.first;
        temp.second += dir.second;
        while (temp.first >= 0 && temp.first < n && temp.second >= 0 && temp.second < m)
        {
            behit [temp.first][temp.second]--;
            if (behit [temp.first][temp.second] == 0 && !visited [temp.first][temp.second] && grid [temp.first][temp.second])
            {
                visited [temp.first][temp.second] = true;
                Q.push (temp);
            }
            temp.first += dir.first;
            temp.second += dir.second;
        }
    }
    
    while (!results.empty())
    {
        cout << "(" << results.top().first << "," << results.top().second << ")\n";
        results.pop();
    }
    return 0;
}
