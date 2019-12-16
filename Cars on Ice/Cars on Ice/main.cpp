#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define endl "\n"
using namespace std;

class fenwick
{
    pair <int, int>* arr;  //first: numleft, second: min
    public:
    int size;
    fenwick (int size)
    {
        arr = new pair <int, int> [size + 1];
        this -> size = size;
        for (int x = 0; x < size + 1; x++)
        {
            arr [x] = {0, INF};
        }
    }
    int lowbit (int n)
    {
        return n&(-n);
    }
    void update (int index, pair <int, int> ele)
    {
        while (index <= size)
        {
            arr [index].first += ele.first;
            arr [index].second = min (arr [index].second, ele.second);
            index += lowbit (index);
        }
    }
    pair <int, int> query (int index)
    {
        pair <int, int> res = {0, INF};
        while (index > 0)
        {
            res.first += arr [index].first;
            res.second = min (res.second, arr [index].second);
            index -= lowbit (index);
        }
        return res;
    }
    void clear ()
    {
        delete [] arr;
    }
};

int n, m;
int grid [2002][2002];  //1: N, 2: E, 3: S, 4: W
pair <int, int> directions [] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dis [2002][2002];
vector <pair <int, int>> cars;
int types [2002][2002][4];
string line;
fenwick* horizontal [2002];
fenwick* vertical [2002];

bool cmp (pair <int, int> p1, pair <int, int> p2)
{
    return dis [p1.first][p1.second] > dis [p2.first][p2.second];
}

void dfs (pair <int, int> node)
{
    int d = grid [node.first][node.second] - 1;
    pair <int, int> direction = directions [d];
    pair <int, int> temp = {node.first + direction.first, node.second + direction.second};
    bool visited = false;
    
    if (d == 0)  //north
    {
        visited = vertical [node.second + 1] -> query(node.first).first == 0;
    }
    else if (d == 1) //east
    {
        visited = horizontal [node.first + 1] -> query(m).first - horizontal [node.first + 1] -> query (node.second).first == 0;
    }
    else if (d == 2) //south
    {
        visited = vertical [node.second + 1] -> query(n).first - vertical [node.second + 1] -> query (node.first).first == 0;
    }
    else //west
    {
        visited = horizontal [node.first + 1] -> query (node.second).second == 0;
    }
    
    if (!visited)
    {
        for (; temp.first >= 0 && temp.first < n && temp.second >= 0 && temp.second < m; temp.first += direction.first, temp.second += direction.second)
        {
            if (grid [temp.first][temp.second])
            {
                if (dis [temp.first][temp.second] == INF)
                {
                    dis [temp.first][temp.second] = dis [node.first][node.second] + 1;
                    horizontal [temp.first + 1] -> update(temp.second + 1, {-1, dis [temp.first][temp.second]});
                    vertical [temp.second + 1] -> update(temp.first + 1, {-1, dis [temp.first][temp.second]});
                    dfs (temp);
                }
                //dis [node.first][node.second] = min (dis [node.first][node.second], dis [temp.first][temp.second] - 1);
            }
        }
    }
    
    //dis [
}

void init ()
{
    memset (dis, 0x3f, sizeof (dis));
    for (int x = 1; x <= n; x++)
    {
        horizontal [x] = new fenwick (m);
    }
    for (int x = 1; x <= m; x++)
    {
        vertical [x] = new fenwick (n);
    }
    for (pair <int, int> car: cars)
    {
        horizontal [car.first + 1] -> update(car.second + 1, {1, INF});
        vertical [car.second + 1] -> update (car.first + 1, {1, INF});
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
    init ();
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
            dis [each.first][each.second] = 0;
            dfs (each);
        }
    }
    sort (cars.begin(), cars.end(), cmp);
    for (pair <int, int> each: cars)
    {
        cout << "(" << each.first << "," << each.second << ")\n";
    }
    return 0;
}
