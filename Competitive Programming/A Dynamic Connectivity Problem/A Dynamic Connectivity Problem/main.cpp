#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INFINT 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 400004
#define MAXM 200004
#define endl "\n"
#define readln(x) getline (cin, x)
#define fastio ios_base::sync_with_stdio(0); cin.tie (0); cout.tie (0);
#define all(a) a.begin(), a.end()
#define MOD1 10000007
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

int n, m, k, num;
int from, to;
vector <int> adj [MAXN];
unordered_set <int> nodestoberemoved;
vector <int> removenodes;
vector <pair <int, int>> edges;
int parent [MAXN];
int numgraphs = 0;

int Find (int child)
{
    if (parent [child] == child)
    {
        return child;
    }
    return parent [child] = Find (parent [child]);
}
void Union (int s1, int s2)
{
    parent [s1] = s2;
}
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].pb (to);
        adj [to].pb (from);
        edges.pb ({from, to});
    }
    scanf ("%d", &k);
    for (int x = 0; x < k; x++)
    {
        scanf ("%d", &num);
        nodestoberemoved.insert (num);
        removenodes.pb (num);
    }
    for (int x = 0; x < n; x++)
    {
        parent [x] = x;
    }
    numgraphs = n - k;
    for (pair <int, int> each: edges)
    {
        if (!nodestoberemoved.count(each.first) && !nodestoberemoved.count (each.second))
        {
            int s1 = Find (each.first);
            int s2 = Find (each.second);
            if (s1 != s2)
            {
                Union (s1, s2);
                numgraphs--;
            }
        }
    }
    vector <int> output;
    output.pb (numgraphs);
    for (int x = (int) removenodes.size() - 1; x >= 0; x--)
    {
        int cnt = 0;
        for (int each: adj [removenodes[x]])
        {
            if (!nodestoberemoved.count (each))
            {
                int s1 = Find (removenodes[x]);
                int s2 = Find (each);
                if (s1 != s2)
                {
                    Union (s1, s2);
                    if (cnt > 0)
                    {
                        numgraphs--;
                    }
                    cnt++;
                }
            }
        }
        if (cnt == 0)
        {
            numgraphs++;
        }
        nodestoberemoved.erase(removenodes [x]);
        output.pb (numgraphs);
    }
    for (int x = (int) output.size() - 1; x >= 0; x--)
    {
        printf ("%d\n", output [x]);
    }
    return 0;
}


