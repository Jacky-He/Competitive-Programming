#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INFINT 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 250000
#define endl "\n"
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define readln(x) getline (cin, x)
#define fastio ios_base::sync_with_stdio(0); cin.tie (0); cout.tie (0);
#define all(a) a.begin(), a.end()
#define MOD1 1e9+7
#define MOD2 1e9+9
#define seed1 31
#define seed2 131
#define pb push_back
#define mp make_pair
#define fill(a, x) memset (a, x, sizeof (a))
#define For(a, b, c, d) for (auto a = b; a < c; a += d)
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}
template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)

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
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return i*fpow(j,mod-2,mod)%mod;}

ll n, m, q;
ll d, p;

vector <pll> prices; //first: price, second: quantity;
vector <pll> changes1;
vector <pll> changes;

int main ()
{
    fastio;
    cin >> n >> m >> q;
    changes1.pb (mp (n, 1000000));
    for (int x = 0; x < q; x++)
    {
        cin >> d >> p;
        changes1.pb (mp (d, p));
    }
    changes1.pb (mp (0, 0));
    for (int x = 0; x < changes1.size() - 1; x++)
    {
        changes.pb (changes1 [x]);
        changes.pb ({changes1 [x + 1].first, changes1 [x].second});
    }
    int x = 0;
    while (x < (int)changes.size() - 1)
    {
        if (changes [x].first != changes [x + 1].first)
        {
            prices.pb (mp (changes [x].second, changes [x].first - changes [x + 1].first));
        }
        else
        {
            //cout << changes [x].first << " " << changes [x].second << " " << changes [x + 1].first << " " << changes [x + 1].second << endl;
            ll mini = changes [x].second;
            while (changes [x].first == changes [x + 1].first)
            {
                mini = min (mini, changes [x].second, changes [x + 1].second);
                x++;
            }
            prices.pb (mp (mini, 1));
            prices.pb (mp (changes [x].second, changes [x].first - 1 - changes [x + 1].first));
        }
        x++;
    }
    sort (all (prices));
    ll res = 0;
    for (pll each: prices)
    {
        //cout << each.first << " " << each.second << endl;
        
        if (m >= each.second)
        {
            res += each.second*each.first;
            m -= each.second;
        }
        else
        {
            res += each.first*m;
            break;
        }
    }
    cout << res << endl;
    return 0;
}


