#include <bits/stdc++.h>
#define endl "\n"
#define MOD 998244353
#define MAXN 103
using namespace std;
typedef long long int ll;

int n, k;
string str;
int from, to;
int colour [MAXN]; //Black is 1, Red is 0
vector <int> adj [MAXN];
ll dp [MAXN][MAXN][3][3]; //the nodes, number of vertices it contains, number of black nodes lacked, number of red nodes lacked. Stores the number of subgraphs with this property.
queue <int> Q;
bool visited [MAXN];

ll solve (int node, int vertices, int lackblack, int lackred, int prev)
{
    ll& ret = dp [node][vertices][lackblack][lackred];
    if (ret != -1)
    {
        return ret;
    }
    memset (dp [node], 0, sizeof (dp [node]));
    ll result [MAXN][3][3];
    memset (result, 0, sizeof (result));
    result [1][2 - colour [node]][2 - (1 - colour [node])] = 1;
    dp [node][1][2 - colour [node]][2 - !colour[node]] = 1;
    for (int each: adj [node])
    {
        if (!visited [each] && each != prev)
        {
            for (int x = 1; x <= k; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    for (int z = 0; z < 3; z++)
                    {
                        ll temp = solve (each, x, y, z, node);
                        //result [x + 1][max(0, y - colour [node])][max (0, z - (1 - colour [node]))] = (result [vertices + 1][max(0, y - colour [node])][max (0, z - (1 - colour [node]))] + temp)%MOD;
                        for (int i = 1; i <= k; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                for (int a = 0; a < 3; a++)
                                {
                                    if (i + x <= k)
                                    {
                                        ll product = (dp [node][i][j][a]*temp)%MOD;
                                        int black = (2 - j) + (2 - y);
                                        int red = (2 - a) + (2 - z);
                                        result [x + i][2 - min (2, black)][2 - min (2, red)] = (result [x + i][2 - min (2, black)][2 - min (2, red)] + product)%MOD;
                                    }
                                }
                            }
                        }
                        
                    }
                }
            }
            for (int x = 0; x < MAXN; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    for (int z = 0; z < 3; z++)
                    {
                        dp [node][x][y][z] = result [x][y][z];
                    }
                }
            }
        }
    }
    for (int x = 0; x < MAXN; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                dp [node][x][y][z] = result [x][y][z];
            }
        }
    }
    return ret;
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie (0); cout.tie (0);
    cin >> n >> k;
    cin >> str;
    memset (dp, -1, sizeof (dp));
    for (int x = 0; x < n; x++)
    {
        colour [x + 1] = str [x] == 'B';
    }
    for (int x = 0; x < n - 1; x++)
    {
        cin >> from >> to;
        adj [from].push_back (to);
        adj [to].push_back(from);
    }
    ll res = 0;
    Q.push (1);
    visited [1] = true;
    res = (res + solve (1, k, 0, 0, 1))%MOD;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                res = (res + solve (each, k, 0, 0, temp))%MOD;
                Q.push(each);
            }
        }
    }
    cout << res << endl;
    return 0;
}








