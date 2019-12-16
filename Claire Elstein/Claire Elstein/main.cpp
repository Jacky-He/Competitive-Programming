#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INFINT 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100004
#define endl "\n"
#define readln(x) getline (cin, x)
#define fastio ios_base::sync_with_stdio(0); cin.tie (0); cout.tie (0);
#define all(a) a.begin(), a.end()
#define MOD1 1000000007
#define MOD2 1000000009
#define seed1 31
#define seed2 131
#define pb push_back
#define mp make_pair
#define fill(a, x) memset (a, x, sizeof (a))
#define For(a, b, c, d) for (auto a = b; a < c; a += d)

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef pair <ll, pll> triplet;
typedef pair <string, ll> psl;
typedef pair <ll, string> pls;
typedef pair <double, string> pds;
typedef pair <string, double> psd;
typedef pair <string, string> pss;
typedef unordered_map <double, double> umdd;
typedef unordered_map <ll, ll> umll;
typedef unordered_map <string, string> umss;
typedef unordered_map <string, ll> umsl;
typedef unordered_map <string, double> umsd;
typedef unordered_map <ll, string> umls;
typedef unordered_map <double, string> umds;
typedef map <double, double> mdd;
typedef map <ll, ll> mll;
typedef map <string, string> mss;
typedef map <string, ll> msl;
typedef map <string, double> msd;
typedef map <ll, string> mls;
typedef map <double, string> mds;
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> PQS;
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>> PQX;
typedef __int8_t byte;
typedef __int128_t bigint;

int n, m;
int from, to;
vector <int> adj [MAXN];
vector <int> adjbackwards [MAXN];
pll dp [MAXN]; //first: number of paths, second: sum of paths
ll result = 0;
pll dfs (int node)
{
    if (dp [node].first != 0)
    {
        return dp [node];
    }
    pll result = {0, 0};
    for (int each: adj [node])
    {
        pll temp = dfs (each);
        result.first = ((result.first + temp.first)%MOD1)%MOD1;
        result.second = (result.second + (temp.second + temp.first)%MOD1)%MOD1;
    }
    if (result.first == 0)
    {
        result.first = 1;
    }
    return dp [node] = result;
}
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].pb(to);
        adjbackwards [to].pb(from);
    }
    for (int x = 1; x <= n; x++)
    {
        if (!adj [x].empty() && adjbackwards [x].empty())
        {
            result = (result + dfs (x).second)%MOD1;
        }
    }
    printf ("%lld", result);
    return 0;
}




