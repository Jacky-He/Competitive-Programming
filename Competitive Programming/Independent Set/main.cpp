#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 100005
using namespace std;
typedef long long int ll;

int n, from, to;
vector <int> adj [MAXN];
ll dp [2][MAXN]; //1: black, 0: white;

ll solve (int black, int node, int prev)
{
    if (dp [black][node]) {return dp [black][node];}
    ll res = 1;
    for (int each: adj [node])
    {
        if (each != prev)
        {
            ll temp = (black ? solve (0, each, node) : (solve (0, each, node) + solve (1, each, node))%MOD);
            res = (res*temp)%MOD;
        }
    }
    return dp [black][node] = res;
}

int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n - 1; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back (to);
        adj [to].push_back (from);
    }
    printf ("%lld\n", (solve (0, 1, 1) + solve (1, 1, 1))%MOD);
    return 0;
}
