#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INFINT 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 1005
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

int n;
bool visited [MAXN][2*MAXN];
bool grid [MAXN][2*MAXN]; //true: black, false: white;
string line;
queue <pii> q;

bool inbound (pii p) {return p.first >= 2 && p.first <= n - 1 && p.second >= 2 && p.second <= 2*n - 1;}
pii directions [8] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};



void markasvisited (pii p)
{
    q.push (p);
    visited [p.first][p.second] = true;
    while (!q.empty())
    {
        pii temp = q.front();
        q.pop();
        for (pii direction : directions)
        {
            pii newplace = {temp.first + direction.first, temp.second + direction.second};
            if (inbound (newplace) && !visited [newplace.first][newplace.second] && grid [newplace.first][newplace.second])
            {
                visited [newplace.first][newplace.second] = true;
                q.push (newplace);
            }
        }
    }
}

bool checkforpumpkin (pii p)
{
    //check for longest horizontal
    int col = p.second;
    int cnt = 0; //max horizontal
    while (grid [p.first][col])
    {
        cnt++;
        col++;
    }
    if ((cnt - 3)%2 != 0 || (cnt - 3)/2 <= 0)
    {
        markasvisited (p);
        return false;
    }
    
    int size = (cnt - 3)/2;
    
    //check for last row blank spaces
    for (int i = -1; i <= cnt; i++)
    {
        pii newpair = {p.first + 1, p.second + cnt};
        if (!inbound (newpair) || grid [newpair.first][newpair.second])
        {
            markasvisited(p);
            return false;
        }
    }
    
    //goes up and checks each row;
    for (int j = 0; j < 1 + int(ceil (2.0*double(size)/3.0)); j++)
    {
        pii newpair = {p.first - j, p.second - 1};
        if (!inbound (newpair) || grid [newpair.first][newpair.second])
        {
            markasvisited (p);
            return false;
        }
        newpair.second = p.second + cnt;
        if (!inbound (newpair) || grid [newpair.first][newpair.second])
        {
            markasvisited(p);
            return false;
        }
        for (int i = 0; i < cnt; i++)
        {
            newpair.second = p.second + i;
            if (!inbound (newpair) || !grid [newpair.first][newpair.second])
            {
                markasvisited (p);
                return false;
            }
        }
    }
    
    pii currpos = {p.first - 1 - int(ceil(2.0*double(size)/3.0)), p.second};
    for (int i = -1; i <= size; i++)
    {
        currpos.second = p.second + i;
        if (!inbound (currpos) || grid [currpos.first][currpos.second])
        {
            markasvisited(p);
            return false;
        }
    }
    
    currpos.second = p.second + size + 1;
    if (!inbound (currpos) || !grid [currpos.first][currpos.second])
    {
        markasvisited(p);
        return false;
    }
    
    for (int i = size + 2; i < 2*size + 4; i++)
    {
        currpos.second = p.second + i;
        if (!inbound (currpos) || grid [currpos.first][currpos.second])
        {
            markasvisited(p);
            return false;
        }
    }
    
    currpos.second = p.second + size + 1;
    currpos.first--;
    
    for (int i = 0; i < int(floor(double(size)/5.0)); i++)
    {
        if(!inbound (currpos) || !grid [currpos.first][currpos.second])
        {
            markasvisited(p);
            return false;
        }
        if (!inbound (mp (currpos.first, currpos.second - 1)) || grid [currpos.first][currpos.second - 1])
        {
            markasvisited(p);
            return false;
        }
        if (!inbound (mp (currpos.first, currpos.second + 1)) || grid [currpos.first][currpos.second + 1])
        {
            markasvisited(p);
            return false;
        }
        currpos.first--;
    }
    
    for (int i = -1; i <= 1; i++)
    {
        if (!inbound (mp(currpos.first, currpos.second + i)) || grid [currpos.first][currpos.second + i])
        {
            markasvisited(p);
            return false;
        }
    }
    
    markasvisited (p);
    return true;
}

int main ()
{
    fastio;
    cin >> n;
    for (int x = 1; x <= n; x++)
    {
        cin >> line;
        for (int y = 1; y <= 2*n; y++)
        {
            grid [x][y] = (line [y - 1] == '#');
        }
    }
    
    int cnt = 0;
    for (int x = n - 1; x >= 2; x--)
    {
        for (int y = 2; y <= 2*n - 1; y++)
        {
            if (!visited [x][y] && grid [x][y])
            {
                cnt += checkforpumpkin(mp(x, y));
            }
        }
    }
    cout << cnt << endl;
    return 0;
}


