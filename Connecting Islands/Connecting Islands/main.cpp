#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;


int n, m;
bool land [55][55];
bool visited [55][55];
int dis [3][55][55];
pii arr [] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string str;
vector <pii> islands [3];
queue <pii> Q;
vector <int> imlazy;

bool inbound (pii point)
{
    return point.first < n && point.first >= 0 && point.second < m && point.second >= 0;
}

vector <pii> adj (pii point)
{
    vector <pii> v;
    for (pii each: arr)
    {
        pii next = {point.first + each.first, point.second + each.second};
        if (inbound (next))
        {
            v.push_back (next);
        }
    }
    return v;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> n >> m;
    for (int x = 0; x < n; x++)
    {
        cin >> str;
        for (int y = 0; y < m; y++)
        {
            land [x][y] = str [y] == 'X';
        }
    }
    int icnt = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (!visited [x][y] && land [x][y])
            {
                visited [x][y] = true;
                pii p = {x, y};
                Q.push (p);
                islands [icnt].push_back (p);
                while (!Q.empty())
                {
                    pii temp = Q.front();
                    Q.pop();
                    for (pii each: adj (temp))
                    {
                        if (!visited [each.first][each.second] && land [each.first][each.second])
                        {
                            visited [each.first][each.second] = true;
                            islands [icnt].push_back (each);
                            Q.push (each);
                        }
                    }
                }
                icnt++;
            }
        }
    }
    memset (dis, 0x3f, sizeof (dis));
    for (int i = 0; i < 3; i++)
    {
        pii p = islands [i][0];
        dis [i][p.first][p.second] = 0;
        Q.push (p);
        while (!Q.empty())
        {
            pii temp = Q.front();
            Q.pop();
            for (pii each: adj (temp))
            {
                if (land [each.first][each.second])
                {
                    if (dis [i][each.first][each.second] > dis [i][temp.first][temp.second])
                    {
                        dis [i][each.first][each.second] = dis [i][temp.first][temp.second];
                        Q.push (each);
                    }
                }
                else
                {
                    if (dis [i][each.first][each.second] > dis [i][temp.first][temp.second] + 1)
                    {
                        dis [i][each.first][each.second] = dis [i][temp.first][temp.second] + 1;
                        Q.push (each);
                    }
                }
            }
        }
    }
    imlazy.push_back (dis [0][islands [1][0].first][islands [1][0].second]);
    imlazy.push_back (dis [0][islands [2][0].first][islands [2][0].second]);
    imlazy.push_back (dis [1][islands [2][0].first][islands [2][0].second]);
    sort (imlazy.begin(), imlazy.end());
    printf ("%d\n", imlazy [0] + imlazy [1]);
    return 0;
}




