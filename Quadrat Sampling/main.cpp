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
#define complete_unique_sort(a) sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()),a.end())
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
typedef pair <pll, ll> triplet;
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

//type: -1: substract, 0: add, 1: goose;
struct s {int rc; int type; pair <int, int> range;};
s makes (int rc, int type, pair <int, int> range) {s s; s.rc = rc; s.type = type; s.range = range; return s;}
bool cmp (s s1, s s2) {return s1.rc < s2.rc || (s1.rc == s2.rc && s1.type < s2.type);}
struct node {int l; int r; int maxi; int lazy;};

int n, m, k, q, t;
int a, b, c, d;
vector <s> verticalcoords;
vector <int> rownums;
vector <s> horizontalcoords;
vector <int> colnums;
int maxval [100005];
node tree [4*400005];

int getindexrow (int coords) {return (int) (lower_bound (all (rownums), coords) - rownums.begin());}
int getindexcol (int coords) {return (int) (lower_bound (all (colnums), coords) - colnums.begin());}

void push_up (int index)
{
    if (tree [index].l == tree [index].r) {return;}
    tree [index].maxi = max (tree [index*2].maxi, tree [index*2 + 1].maxi);
}

void push_down (int index)
{
    if (tree [index].l == tree [index].r)
    {
        tree [index].maxi += tree [index].lazy;
        tree [index].lazy = 0;
        return;
    }
    tree [index*2].lazy += tree [index].lazy;
    tree [index*2 + 1].lazy += tree [index].lazy;
    tree [index].maxi += tree [index].lazy;
    tree [index].lazy = 0;
}

void update (int index, int left, int right, int delta)
{
    if (tree [index].l > right || tree [index].r < left)
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
    push_down(index);
    update (index*2, left, right, delta);
    update (index*2 + 1, left, right, delta);
    push_up (index);
}

int query (int index, int left, int right)
{
    if (tree [index].l > right || tree [index].r < left)
    {
        push_down (index);
        return 0;
    }
    if (tree [index].r <= right && tree [index].l >= left)
    {
        push_down (index);
        return tree [index].maxi;
    }
    push_down (index);
    return max (query (index*2, left, right), query (index*2 + 1, left, right));
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
    cin >> n >> m >> k >> q >> t;
    for (int x = 0; x < k; x++)
    {
        cin >> a >> b;
        verticalcoords.pb (makes(a, 1, {b, x}));
        rownums.pb (b - t);
        rownums.pb (b + t);
        horizontalcoords.pb (makes (b, 1, {a, x}));
        colnums.pb (a - t);
        colnums.pb (a + t);
    }
    for (int x = 0; x < q; x++)
    {
        cin >> a >> b >> c >> d;
        verticalcoords.pb (makes (a, 0, {b, d}));
        verticalcoords.pb (makes (c + 1, -1, {b, d}));
        rownums.pb (b); rownums.pb (d);
        horizontalcoords.pb (makes (b, 0, {a, c}));
        horizontalcoords.pb (makes (d + 1, -1, {a, c}));
        colnums.pb (a); colnums.pb (c);
    }
    complete_unique_sort (rownums);
    complete_unique_sort (colnums);
    sort (all (verticalcoords), cmp);
    sort (all (horizontalcoords), cmp);
    init (1, 0, (int)(max (rownums.size(), colnums.size()) - 1));
    for (s each: verticalcoords)
    {
        if (each.type == 0)
        {
            update (1, getindexrow (each.range.first), getindexrow (each.range.second), 1);
        }
        else if (each.type == -1)
        {
            update (1, getindexrow (each.range.first), getindexrow (each.range.second), -1);
        }
        else if (each.type == 1)
        {
            maxval [each.range.second] = max (maxval [each.range.second], query(1, getindexrow(each.range.first - t), getindexrow(each.range.first + t)));
        }
    }
    for (int x = 0; x < 4*400005; x++)
    {
        tree [x].maxi = 0;
        tree [x].lazy = 0;
    }
    for (s each: horizontalcoords)
    {
        if (each.type == 0)
        {
            update (1, getindexcol (each.range.first), getindexcol (each.range.second), 1);
        }
        else if (each.type == -1)
        {
            update (1, getindexcol (each.range.first), getindexcol (each.range.second), -1);
        }
        else if (each.type == 1)
        {
            maxval [each.range.second] = max (maxval [each.range.second], query (1, getindexcol(each.range.first - t), getindexcol(each.range.first + t)));
        }
    }
    ll res = 0;
    for (int x = 0; x < k; x++)
    {
        res += maxval [x];
    }
    cout << res << endl;
    return 0;
}


