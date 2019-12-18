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

template <class T> class fenwick {private:T* pt;ll size;ll lowbit (ll n){return n&(-n);}public:void update (ll index, T delta){while (index <= size){pt [index] += delta;index += lowbit (index);}}T query (ll index){T sum = 0;while (index > 0){sum += pt [index];index -= lowbit (index);}return sum;}void init (T* arr, ll size) /*arr is 0-indexed*/{pt = new T [size + 1];for(int x = 0; x <= size; x++){pt [x] = 0;}this -> size = size;for (int x= 1; x <= size; x++){update (x, arr [x - 1]);}}fenwick (T* arr, ll size){init (arr, size);}fenwick(ll size){pt = new T [size + 1]; for (int x = 0; x <= size; x++){pt[x]=0;}}};
template <class T> class monodeque {private:deque <pair <T, ll>> mono; bool increase = true; /*false: mindeque, true: maxdeque*/public: void push (T val, ll index){while (!mono.empty() && (increase? (val > mono.back().first): (val < mono.back().first))){mono.pop_back();}mono.pb (mp(val, index));}pair <T, ll> getVal(){return mono.front();}bool empty(){return mono.empty();} void pop (){mono.pop_front();}monodeque (string maxdeque){increase = (maxdeque == "max");}};


mt19937 g1((unsigned int)time(0));

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<ll>(a, b)(g1);}

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int n;
string str;
pair <string, int> v [100005];

char toChar (int i) {return i + 'a';}



int main ()
{
    fastio;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> str;
        v [x].first = str;
    }
    string res = "";
    for (int x = 25; x >= 0; x--)
    {
        bool found = true;
        int minnum = INFINT;
        for (int y = 0; y < n; y++)
        {
            unsigned long first = v [y].first.find(toChar(x));
            if (first == string::npos)
            {
                found = false;
                break;
            }
            int cnt = 0;
            for (int z = 0; z < (int)v[y].first.size(); z++)
            {
                if (v[y].first[z] == toChar(x))
                {
                    v [y].second = z;
                    cnt++;
                }
            }
            minnum = min (minnum, cnt);
        }
        if (found)
        {
            int copymin = minnum;
            while (copymin--)
            {
                res += toChar(x);
            }
            for (int y = 0; y < n; y++)
            {
                int cpy = minnum;
                int index = 0;
                while (index <(int)v[y].first.size() && cpy > 0)
                {
                    if (v[y].first[index] == toChar(x))
                    {
                        cpy--;
                    }
                    index++;
                }
                v[y].first.erase(0, index);
            }
        }
    }
    cout << (res == "" ? to_string(-1) : res) << endl;
    return 0;
}

/*
4
dfas
fasdfa
asdfasf
asdfasd


*/
