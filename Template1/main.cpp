//MARK: Macros
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
#define complete_unique_sort(a) sort (a.begin(), a.end()); a.erase (unique(a.begin(), a.end()), a.end())
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

//MARK: types and functions
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

//1-indexed
template <class T> class fenwick {private:T* pt;ll size;ll lowbit (ll n){return n&(-n);}public:void update (ll index, T delta){while (index <= size){pt [index] += delta;index += lowbit (index);}}T query (ll index){T sum = 0;while (index > 0){sum += pt [index];index -= lowbit (index);}return sum;}void init (T* arr, ll size) /*arr is 0-indexed*/{pt = new T [size + 1];for(int x = 0; x <= size; x++){pt [x] = 0;}this -> size = size;for (int x= 1; x <= size; x++){update (x, arr [x - 1]);}}fenwick (T* arr, ll size){init (arr, size);}fenwick(ll size){pt = new T [size + 1]; for (int x = 0; x <= size; x++){pt[x]=0;}}};
template <class T> class monodeque {private:deque <pair <T, ll>> mono; bool increase = true; /*false: mindeque, true: maxdeque*/public: void push (T val, ll index){while (!mono.empty() && (increase? (val > mono.back().first): (val < mono.back().first))){mono.pop_back();}mono.pb (mp(val, index));}pair <T, ll> getVal(){return mono.front();}bool empty(){return mono.empty();} void pop (){mono.pop_front();}monodeque (string maxdeque){increase = (maxdeque == "max");}};
//0-indexed
template <class T> class sparsetable{pair <T, T>** pt;int size;public:sparsetable (T* arr, int size){int temp = (int)log2(size)+3;pt = new pair <T, T>* [size+1];for (int x = 0; x <= size; x++){pt [x] = new pair <T,T> [temp];pt [x][0].first = pt [x][0].second = arr [x];}for (int x = 1; (1 << x) <= size; x++){for (int y = 0; y + (1 << x) <= size; y++){pt [y][x].first = max (pt [y][x - 1].first, pt [y + (1 << (x - 1))][x - 1].first);pt [y][x].second = min (pt [y][x - 1].second, pt [y + (1 << (x - 1))][x - 1].second);}}}T getmax (int from, int to){int k = (int)log2 (to - from + 1);return max (pt [from][k].first, pt [to - (1 << k) + 1][k].first);}T getmin (int from, int to){int k = (int)log2 (to - from + 1);return min (pt [from][k].second, pt [to - (1 << k) + 1][k].second);}};

/*struct node
{
    node* pls; // <
    node* prb; // >=
    int key;
    int priority;
    int sz;
    node (int key, int priority)
    {
        pls = prb = nullptr;
        this -> key = key;
        this -> priority = priority;
        this -> sz = 1;
    }
};

struct treap
{
    node* root = nullptr;

    void insert (int key)
    {
        if (root == nullptr)
        {
            root = new node (key, rand());
            return;
        }
        root = insert (key, root);
    }
    node* insert (int key, node* curr)
    {
        curr -> sz ++;
        if (key < curr -> key)
        {
            if (curr -> pls)
            {
                curr -> pls = insert (key, curr -> pls);
            }
            else
            {
                curr -> pls = new node (key, rand());
            }
            if (curr -> pls -> priority <= curr -> priority)
            {
                return rightrotation (curr);
            }
            return curr;
        }
        if (curr -> prb)
        {
            curr -> prb = insert (key, curr -> prb);
        }
        else
        {
            curr -> prb = new node (key, rand());
        }
        if (curr -> prb -> priority <= curr -> priority)
        {
            if (curr -> prb -> key == curr -> key)
            {
                int temp = curr -> key;
                curr -> key = curr -> prb -> key;
                curr -> prb -> key = temp;
                return curr;
            }
            return leftrotation (curr);
        }
        return curr;
    }
    
    node* rightrotation (node* curr)
    {
        node* temp = curr -> pls;
        int rs = curr -> pls -> prb ? curr -> pls -> prb -> sz : 0;
        curr -> sz += (rs - curr -> pls -> sz);
        curr -> pls -> sz += (curr -> sz - rs);
        //pointers
        curr -> pls = curr -> pls -> prb;
        temp -> prb = curr;
        return temp;
    }
    
    node* leftrotation (node* curr)
    {
        node* temp = curr -> prb;
        //sizes
        int ls = curr -> prb -> pls ? curr -> prb -> pls -> sz : 0;
        curr -> sz += (ls - curr -> prb -> sz);
        curr -> prb -> sz += (curr -> sz - ls);
        //pointers
        curr -> prb = curr -> prb -> pls;
        temp -> pls = curr;
        return temp;
    }
    
    int find (int ele) //returns index;
    {
        int res = find (ele, root);
        return res < 0 ? -1 : res + 1;
    }
    
    int find (int key, node* curr)
    {
        if (curr == nullptr) {return -INFINT;}
        if (curr -> key == key)
        {
            return curr -> pls ? curr -> pls -> sz : 0;
        }
        if (curr -> key > key && curr -> pls)
        {
            return find (key, curr -> pls);
        }
        if (curr -> key <= key && curr -> prb)
        {
            return (curr -> pls ? curr -> pls -> sz : 0) + 1 + find (key, curr -> prb);
        }
        return -INFINT;
    }
    
    void erase (int key)
    {
        if (find (key) != -1)
        {
            root = erase (key, root);
        }
    }
    
    node* meld (node* t1, node* t2)
    {
        if (t1 == nullptr) {return t2;}
        if (t2 == nullptr) {return t1;}
        node* smaller; node* bigger;
        if (t1 -> priority < t2 -> priority)
        {
            smaller = t1;
            bigger = t2;
        }
        else
        {
            smaller = t2;
            bigger = t1;
        }
        if (smaller -> key < bigger -> key)
        {
            bigger -> sz += smaller -> sz;
            smaller -> sz += bigger -> pls ? bigger -> pls -> sz : 0;
            smaller -> prb = meld (smaller -> prb, bigger -> pls);
            bigger -> pls = smaller;
        }
        else
        {
            bigger -> sz += smaller -> sz;
            smaller -> sz += bigger -> prb ? bigger -> prb -> sz : 0;
            smaller -> pls = meld (smaller -> pls, bigger -> prb);
            bigger -> prb = smaller;
        }
        return bigger;
    }
    
    node* erase (int key, node* curr)
    {
        if (curr == nullptr) {return nullptr;}
        curr -> sz --;
        if (curr -> key == key)
        {
            return meld (curr -> pls, curr -> prb);
        }
        if (key < curr -> key)
        {
            curr -> pls = erase (key, curr -> pls);
        }
        else
        {
            curr -> prb = erase (key, curr -> prb);
        }
        return curr;
    }
    
    int kth (int k)
    {
        return kth (k, root);
    }
    
    int kth (int k, node* curr)
    {
        int currsz = curr -> pls ? curr -> pls -> sz : 0;
        if (currsz + 1 == k)
        {
            return curr -> key;
        }
        if (currsz + 1 > k)
        {
            return kth (k, curr -> pls);
        }
        return kth (k - currsz -1, curr -> prb);
    }
    
    int size ()
    {
        return root ? root -> sz : 0;
    }
};*/
mt19937 g1((unsigned int)time(0));

/*int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<ll>(a, b)(g1);}*/
ll randlong (ll from, ll to) {return random()%(to - from + 1) + from;}
int randint (int from, int to) {return rand()%(to - from + 1) + from;}

//MARK: Treap Template
template<typename T>
struct node{
    T val; int sz; ll prior;
    node *l,*r;
    node(T v){
        val = v, sz = 1;
        prior = randlong(1,1e18);
        l = r = 0;
    }
};

template<typename T>
struct SMTreap{
    node<T> *rt;
    inline int gsz(node<T> *&n){return n?n->sz:0;}
    inline void upd_sz(node<T> *&n){if(n) n->sz=gsz(n->l)+gsz(n->r)+1;}
    void split(node<T> *n, T key, node<T> *&l, node<T> *&r){
        if(!n) l = r = 0;
        else if(key < n->val) split(n->l,key,l,n->l), r = n;
        else split(n->r,key,n->r,r), l = n;
        upd_sz(n);
    }
    void merge(node<T> *&n, node<T> *l, node<T> *r){
        if(!l || !r) n = l?l:r;
        else if(l->prior > r->prior) merge(l->r,l->r,r), n = l;
        else merge(r->l,l,r->l), n = r;
        upd_sz(n);
    }
    void insert(node<T> *&n, node<T> *v){
        if(!n) n = v;
        else if(v->prior > n->prior) split(n,v->val,v->l,v->r), n = v;
        else insert(v->val<n->val?n->l:n->r,v);
        upd_sz(n);
    }
    void erase(node<T> *&n, T v){
        if(!n) return;
        if(n->val == v) merge(n,n->l,n->r);
        else erase(v<n->val?n->l:n->r,v);
        upd_sz(n);
    }
    T find_by_order(node<T> *&n, int idx){
        if(gsz(n->l)+1 == idx) return n->val;
        else if(gsz(n->l) >= idx) return find_by_order(n->l,idx);
        return find_by_order(n->r,idx-gsz(n->l)-1);
    }
    bool contains(node<T> *&n, T v){
        if(!n) return false;
        if(n->val == v) return true;
        if(n->val < v) return contains(n->r,v);
        return contains(n->l,v);
    }
    int num_less(node<T> *&n, T v){
        if(!n) return 0;
        if(n->val < v) return gsz(n->l)+1+num_less(n->r,v);
        return num_less(n->l,v);
    }
    void print(){
        for(int i=1; i<=gsz(rt); i++)
            printf("%d ",find_by_order(rt,i));
        printf("\n");
    }
};

ll gcf (ll a, ll b) {if (b > a) {return gcf (b, a);} return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return (i*fpow(j,mod-2,mod)%mod)%mod;}

int n, q, from, to;
int arr [50005];

//MARK: template centroid

int subsum [MAXN];
bool blocked [MAXN];
vector <int> adj [MAXN]; //doesn't need to be int

ll solveTree (int root)
{
    ll res = 0;
    //solve the subtree
    return res;
}

void computesum (int node, int prev)
{
    subsum [node] = 1;
    for (int each: adj [node])
    {
        if (!blocked [each] && each != prev)
        {
            computesum (each, node);
            subsum [node] += subsum [each];
        }
    }
}

int centroid (int node, int prev, int total)
{
    for (int each: adj [node])
    {
        if (!blocked [each] && each != prev && subsum [each]*2 > total)
        {
            return centroid (each, node, total);
        }
    }
    return node;
}

ll solve (int entry)
{
    computesum (entry, entry);
    int cent = centroid (entry, entry, subsum [entry]);
    ll res = solveTree (cent);
    blocked [cent] = true;
    for (int each: adj [cent]) //doesn't need to be int
    {
        if (!blocked [each])
        {
            res += solve (each); //do something problem requires
        }
    }
    return res;
}

int main ()
{
    fastio;
    
    return 0;
}

