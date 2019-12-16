#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long int ll;

struct triplet {
    ll first; ll second; ll third;
};

int n;
ll dis [1004][1004];
bool vis [1004][1004];
triplet steps [1004][1004];

string line;
queue <pair <pair <ll, ll>, triplet>> Q;

ll cost (triplet p)
{
    return p.first*p.first + p.second*p.second + p.third*p.third;
}

triplet maketriplet (ll a, ll b, ll c)
{
    triplet t;
    t.first = a; t.second = b; t.third = c; return t;
}

bool visited (pair <int, int> p)
{
    return vis[p.first][p.second];
}

bool inbound (pair <int, int> p)
{
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < n;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> line;
        for (int y = 0; y < n; y++)
        {
            steps [x][y] = maketriplet(INF, INF, INF);
            if (line [y] == '#')
            {
                vis [x][y] = true;
            }
        }
    }
    memset (dis, 0x3f, sizeof (dis));
    dis [0][0] = 0;
    triplet st = maketriplet(0, 0, 0);
    Q.push({{0, 0}, st});
    while (!Q.empty())
    {
        pair <pair <ll, ll>, triplet> temp = Q.front();
        Q.pop();
        pair <pair <ll, ll>, triplet> left = {{temp.first.first, temp.first.second - 1}, maketriplet(temp.second.first + 1, temp.second.second, temp.second.third)};
        pair <pair <ll, ll>, triplet> right = {{temp.first.first, temp.first.second + 1}, maketriplet(temp.second.first, temp.second.second + 1, temp.second.third)};
        pair <pair <ll, ll>, triplet> down = {{temp.first.first + 1, temp.first.second}, maketriplet(temp.second.first, temp.second.second, temp.second.third + 1)};
        if (inbound(right.first) && !visited (right.first))
        {
            if (right.second.second < steps [right.first.first][right.first.second].second)
            {
                dis[right.first.first][right.first.second] = cost (right.second);
                steps [right.first.first][right.first.second] = right.second;
                Q.push (right);
            }
        }
        if (inbound(left.first) && !visited (left.first))
        {
            if (left.second.second < steps [left.first.first][left.first.second].second)
            {
                dis [left.first.first][left.first.second] = cost (left.second);
                steps [left.first.first][left.first.second] = left.second;
                Q.push (left);
            }
        }
        if (inbound(down.first) && !visited (down.first))
        {
            if (down.second.second < steps [down.first.first][down.first.second].second)
            {
                dis [down.first.first][down.first.second] = cost(down.second);
                steps [down.first.first][down.first.second] = down.second;
                Q.push (down);
            }
        }
    }
    cout << (dis [n - 1][n - 1] == INF? -1 : dis [n - 1][n - 1]) << endl;
    return 0;
}
