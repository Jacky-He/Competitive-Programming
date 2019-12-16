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
/*typedef __int8_t byte;
typedef __int128_t bigint;*/

template <class T> class fenwick {private:T* pt;ll size;ll lowbit (ll n){return n&(-n);}public:void add (ll index, T delta){while (index <= size){pt [index] += delta;index += lowbit (index);}}T query (ll index){T sum = 0;while (index > 0){sum += pt [index];index -= lowbit (index);}return sum;}void init (T* arr, ll size) /*arr is 0-indexed*/{pt = new T [size + 1];for(int x = 0; x <= size; x++){pt [x] = 0;}this -> size = size;for (int x= 1; x <= size; x++){add (x, arr [x - 1]);}}fenwick (T* arr, ll size){init (arr, size);}};
template <class T> class monodeque {private:deque <pair <T, ll>> mono; bool increase = true; /*false: mindeque, true: maxdeque*/public: void push (T val, ll index){while (!mono.empty() && (increase? (val > mono.back().first): (val < mono.back().first))){mono.pop_back();}mono.pb (mp(val, index));}pair <T, ll> getVal(){return mono.front();}bool empty(){return mono.empty();} void pop (){mono.pop_front();}monodeque (string maxdeque){increase = (maxdeque == "max");}};

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return i*fpow(j,mod-2,mod)%mod;}

unordered_set <string> picked;
string str1, str2;
int n;
int main ()
{
    fastio;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> str1 >> str2;
        picked.insert (str1 + " " + str2);
    }
    cout << picked.size() << endl;
    return 0;
}
