#include <bits/stdc++.h>
#define MAXN 2005
#define MAXQ 800007
#define endl "\n"
#define complete_unique_sort(a) sort (a.begin(), a.end()); a.erase (unique(a.begin(), a.end()), a.end())
using namespace std;
typedef long long int ll;

struct s {
    int l = 0, r = 0;
    ll maxi = 0, lazy = 0;
};

struct segtree {
    s* pt;
public:
    void push_down (int index)
    {
        if (pt [index].l == pt [index].r)
        {
            pt [index].maxi += pt [index].lazy;
            pt [index].lazy = 0;
            return;
        }
        pt [index*2].lazy += pt [index].lazy;
        pt [index*2 + 1].lazy += pt [index].lazy;
        pt [index].maxi += pt [index].lazy;
        pt [index].lazy = 0;
    }
    
    void push_up (int index)
    {
        if (pt [index].l == pt [index].r) return;
        pt [index].maxi = max (pt [index*2].maxi, pt [index*2 + 1].maxi);
    }
    
    void init (int left, int right, int index)
    {
        pt [index].l = left;
        pt [index].r = right;
        if (left == right) return;
        int mid = (left + right)/2;
        init (left, mid, index*2);
        init (mid + 1, right, index*2 + 1);
    }
    
    ll query (int left, int right, int index)
    {
        push_down (index);
        if (pt [index].l > right || pt [index].r < left)
        {
            return 0;
        }
        if (pt [index].l >= left && pt [index].r <= right)
        {
            return pt [index].maxi;
        }
        return max (query (left, right, index*2), query (left, right, index*2 + 1));
    }
    
    void update (int left, int right, int index, ll delta)
    {
        if (pt [index].l > right || pt [index].r < left)
        {
            push_down(index);
            return;
        }
        if (pt [index].l >= left && pt [index].r <= right)
        {
            pt [index].lazy += delta;
            push_down (index);
            return;
        }
        push_down (index);
        update (left, right, index*2, delta);
        update (left, right, index*2 + 1, delta);
        push_up (index);
    }
};

ll maxX;
ll k, n, q;
ll a, b, c;
pair <pair <ll, ll>, ll> planes [MAXN];
vector <pair <ll, ll>> queries;
vector <ll> compressed [MAXN];
vector<pair <pair <ll, ll>, pair <int, ll>>> updates;
segtree* trees [MAXN];

int getIndex (int item, ll value)
{
    return (int)(lower_bound (compressed [item].begin(), compressed [item].end(), value) - compressed [item].begin());
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> maxX >> k >> n >> q;
    for (int x = 1; x <= n; x++)
    {
        cin >> a >> b >> c;
        planes [x] = {{a, b}, c};
    }
    for (int x = 0; x < q; x++)
    {
        cin >> a >> b;
        queries.push_back ({a, b});
        compressed [a].push_back (b);
        compressed [a].push_back (b + k);
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = x + 1; y <= n; y++)
        {
            if (planes [x].first == planes [y].first) continue;
            pair <ll, ll> range1; //things obscuring the first one
            pair <ll, ll> range2; //things obscuring the second one
            double numerator = double (planes [y].first.first - planes [x].first.first);
            double slope1 = double (planes [x].first.second - planes [x].first.first)/double(maxX);
            double slope2 = double (planes [y].first.second - planes [y].first.first)/double (maxX);
            double denominator = slope1 - slope2;
            if (denominator == 0)
            {
                if (numerator > 0)
                {
                    compressed [x].push_back (0);
                    compressed [x].push_back (maxX);
                    updates.push_back ({{0, maxX}, {x, planes [y].second}});
                }
                else if (numerator < 0)
                {
                    compressed [y].push_back (0);
                    compressed [y].push_back (maxX);
                    updates.push_back ({{0, maxX}, {y, planes [x].second}});
                }
            }
            else
            {
                double interX = numerator/denominator;
                double test = interX + 100000;
                double secondVal = test*slope2 + double(planes [y].first.first);
                double firstVal = test*slope1 + double(planes [x].first.first);
                if (secondVal > firstVal)
                {
                    if (interX == ll(interX))
                    {
                        range1 = {(ll)(interX) + 1, maxX};
                        range2 = {(ll)0, (ll)(interX) - 1};
                    }
                    else
                    {
                        range1 = {(ll)ceil (interX), maxX};
                        range2 = {(ll)0, (ll)floor(interX)};
                    }
                }
                else if (secondVal < firstVal)
                {
                    if (interX == ll(interX))
                    {
                        range1 = {(ll)0, (ll)(interX) - 1};
                        range2 = {(ll)(interX) + 1, maxX};
                    }
                    else
                    {
                        range1 = {(ll)0, (ll)floor(interX)};
                        range2 = {(ll)ceil(interX), maxX};
                    }
                }
                compressed [x].push_back (range1.first);
                compressed [x].push_back (range1.second);
                compressed [y].push_back (range2.first);
                compressed [y].push_back (range2.second);
                updates.push_back ({range1, {x, planes [y].second}});
                updates.push_back ({range2, {y, planes [x].second}});
            }
        }
    }
    for (int x = 1; x <= n; x++)
    {
        complete_unique_sort (compressed [x]);
        trees [x] = new segtree;
        trees [x] -> pt = new s [4*(compressed [x].size() + 10)];
        trees [x] -> init (0, (int)compressed [x].size() - 1, 1);
    }
    for (pair <pair <ll, ll>, pair <int, ll>> each: updates)
    {
        int item = each.second.first;
        int l = getIndex (item, each.first.first);
        int r = getIndex (item, each.first.second);
        if (l > r) continue;
        trees [item] -> update (l, r, 1, each.second.second);
    }
    
    for (pair <int, int> each: queries)
    {
        int item = each.first;
        int l = getIndex (item, each.second);
        int r = getIndex (item, each.second + k);
        cout << trees [item] -> query (l, r, 1) << endl;
    }
    return 0;
}

/*
 1000000 4 2 2
 3 100008 103
 1 100007 234
 1 6
 2 9
 
 
 
 12 4 3 3
 1 4 5
 2 2 3
 3 0 6
 2 0
 1 0
 3 1
 
 
 */
