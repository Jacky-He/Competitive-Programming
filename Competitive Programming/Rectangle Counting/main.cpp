#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INFINT 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 1000005
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


struct s {int l; int r; int mini; int lazy;};
struct rect {int op; int left; int right; int row;};
rect makerect (int op, int left, int right, int row) {rect r; r.op = op; r.left = left; r.right = right; r.row = row;return r;}
bool cmp (rect r1, rect r2)
{
    return r1.row < r2.row || (r1.row == r2.row && r1.op > r2.op); //op: 1: add 1, 0: query, -1: minues 1, -2: query 2height
}

int n, a, b, c, d;
s tree [4*MAXN];
vector <rect> v;


void push_up (int index)
{
    if (tree [index].l == tree [index].r) {return;}
    tree [index].mini = min (tree [index*2].mini, tree [index*2 + 1].mini);
}

void push_down (int index)
{
    if(tree [index].l == tree [index].r) {return;}
    tree [index*2].lazy += tree [index].lazy;
    tree [index*2 + 1].lazy += tree [index].lazy;
    tree [index].mini += tree [index].lazy;
    tree [index].lazy = 0;
}

void update (int index, int left, int right, int delta)
{
    if (tree[index].l > right || tree [index].r < left)
    {
        push_down (index);
        return;
    }
    if (tree [index].r <= right && tree [index].l >= left)
    {
        tree [index].lazy += delta;
        push_down (index);
        return;
    }
    push_down (index);
    update (index*2, left, right, delta);
    update (index*2 + 1, left, right, delta);
    push_up(index);
}

void query (int index, int left, int right)
{
    if (tree [index].l > right || tree [index].r < left)
    {
        return 0;
    }
    if (tree [index])
}

void init (int index, int left, int right)
{
    tree [index].l = left;
    tree [index].r = right;
    if (left == right) {return;}
    int mid = (left + right)/2;
    init (index*2, left, mid);
    init (index*2 + 1, mid + 1, right);
}


int main ()
{
    fastio;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b >> c >> d;
        v.pb (makerect(1, b, d, a));
        v.pb (makerect(-1, b, d, c));
        if (c - a == 1)
        {
            v.pb (makerect (-2, b, d, a));
        }
        else
        {
            v.pb (makerect (0, b, d, a + 1));
        }
    }
    init (1, 1, MAXN);
    sort (all (v), cmp);
    for (rect each: v)
    {
        
    }
    return 0;
}


