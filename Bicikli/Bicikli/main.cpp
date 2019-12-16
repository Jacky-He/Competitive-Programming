#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INFINT 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 250000
#define endl "\n"
#define readln(x) getline (cin, x)
#define fastio ios_base::sync_with_stdio(0); cin.tie (0); cout.tie (0);
#define all(a) a.begin(), a.end()
#define MOD1 1000000000
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
vector <int> adj [10004];
vector <int> adjb [10004];
bool visited [10004];
ll dis [10004];
bool repeat [10004];
queue <int> Q;
bool leadingzeros = false;
ll dfs (int node)
{
    if (node == 2)
    {
        return dis [node] = 1;
    }
    if (dis [node] != -1)
    {
        return dis [node];
    }
    visited [node] = true;
    int result = 0;
    for (int each: adj [node])
    {
        if (!visited [each])
        {
            ll temp = dfs (each);
            if (temp + result >= 1000000000)
            {
                leadingzeros = true;
            }
            result = (result + temp)%MOD1;
        }
        else
        {
            repeat [each] = true;
        }
    }
    visited [node] = false;
    return dis [node] = result;
}
bool bfs (int node)
{
    Q.push (node);
    visited [node] = true;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (int each: adjb [temp])
        {
            if (!visited [each])
            {
                if (repeat [each])
                {
                    return true;
                }
                visited [each] = true;
                Q.push (each);
            }
        }
    }
    return false;
}
int main ()
{
    scanf ("%d%d", &n, &m);
    memset (dis, -1, sizeof (dis));
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].pb(to);
        adjb [to].pb (from);
    }
    ll possible = dfs (1);
    if (bfs (2))
    {
        printf ("inf\n");
        return 0;
    }
    if (leadingzeros)
    {
        string output = to_string (possible);
        while (output.length() < 9)
        {
            output = "0" + output;
        }
        printf ("%s\n", output.c_str());
        return 0;
    }
    printf ("%lld\n", possible);
    return 0;
}


