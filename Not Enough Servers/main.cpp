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

int n, m;
int dp [1 << 22];
int previ [1 << 22];
int prevcase [1 << 22];
int cases [55];
string line;
int result = 0;

int main ()
{
    fastio;
    memset (dp, 0x3f, sizeof (dp));
    dp [0] = 0;
    cin >> n >> m;
    for (int x = 0; x < n; x++)
    {
        cin >> line;
        for (int y = 0; y < m; y++)
        {
            cases [y] += ((line [y] == 'X') << x);
        }
    }
    for (int x = 0; x < m; x++)
    {
        result |= cases [x];
        for (int y = 0; y < (1 << n) + 1; y++)
        {
            if (dp [y] + 1 < dp [y|cases [x]])
            {
                dp [y|cases [x]] = dp [y] + 1;
                previ [y|cases [x]] = y;
                prevcase [y|cases [x]] = x;
            }
        }
    }
    if (dp [result] == 0)
    {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    cout << dp [result] << endl;
    while (result != 0)
    {
        cout << prevcase [result] + 1 << " ";
        result = previ [result];
    }
    cout << endl;
    return 0;
}
