#include <bits/stdc++.h>
#define endl "\n"
#define MAXN 100005
using namespace std;
typedef long long int ll;

struct fenwick {
    ll arr [2*MAXN];
    ll size = 2*MAXN;

    int lowbit (int n) {return n&(-n);}
    void update (int index, int delta)
    {
        while (index <= size)
        {
            arr [index] += delta;
            index += lowbit(index);
        }
    }
    
    ll query (int index)
    {
        ll res = 0;
        while (index > 0)
        {
            res += arr [index];
            index -= lowbit(index);
        }
        return res;
    }
    
    void clear ()
    {
        for (int x = 0; x <= size; x++)
        {
            arr [x] = 0;
        }
    }
};

int n, from, to;
ll num;
ll k;
ll weights [MAXN];
vector <int> adj [MAXN];
int subsum [MAXN];
bool blocked [MAXN];

fenwick decreasing;
fenwick increasing;
fenwick constant;

vector <ll> sums;

vector <pair <ll, int>> pathsums;

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

void getSums (int node, int prev, ll sum, int root)
{
    sum += weights [node];
    sums.push_back (0 - (sum-weights[root]));
    sums.push_back (sum);
    for (int each: adj [node])
    {
        if (!blocked [each] && each != prev)
        {
            getSums (each, node, sum, root);
        }
    }
    sum -= weights [node];
}

void computepaths (int node, int prev, ll sum, int trend)
{
    if (trend > 0) {pathsums.push_back ({sum, 1});}
    else if (trend < 0) {pathsums.push_back({sum, -1});}
    else {pathsums.push_back({sum, 0});}
    for (int each: adj [node])
    {
        if (!blocked [each] && each != prev)
        {
            int temptrend = 0;
            if (weights [each] > weights [node])
            {
                temptrend = 1; //increasing
            }
            else if (weights [each] < weights [node])
            {
                temptrend = -1; //decreasing
            }
            if ((temptrend == 1 && trend == -1) || (temptrend == -1 && trend == 1))
            {
                continue;
            }
            if (temptrend == 0)
            {
                temptrend = trend;
            }
            computepaths (each, node, sum + weights [each], temptrend);
        }
    }
}

ll solveTree (int root)
{
    sums.clear();
    getSums (root, root, 0, root);
    sort (sums.begin(), sums.end());
    increasing.size = constant.size = decreasing.size = sums.size();
    increasing.clear();
    constant.clear();
    decreasing.clear();
    ll res = weights [root] <= 0? 1 : 0;
    for (int each: adj [root])
    {
        if (!blocked [each])
        {
            pathsums.clear();
            int trend = 0; //everything is equal;
            if (weights[root] > weights [each])
            {
                trend = -1; //decreasing
            }
            else if (weights [root] < weights [each])
            {
                trend = 1; //increasing
            }
            computepaths (each, root, weights [root] + weights [each], trend);
            for (pair <ll, int> each: pathsums)
            {
                if (each.first <= 0)
                {
                    res++;
                }
                int target = (int)(lower_bound (sums.begin(), sums.end(), 0 - (each.first - weights [root])) - sums.begin() + 1);
                res += constant.query (target);
                if (each.second == 0)
                {
                    res += increasing.query (target);
                    res += decreasing.query (target);
                }
                else if (each.second == 1)
                {
                    res += decreasing.query (target);
                }
                else if (each.second == -1)
                {
                    res += increasing.query(target);
                }
            }
            for (pair <ll, int> each: pathsums)
            {
                int target = (int)(lower_bound (sums.begin(), sums.end(), each.first) - sums.begin() + 1);
                if (each.second == 1)
                {
                    increasing.update(target, 1);
                }
                else if (each.second == 0)
                {
                    constant.update(target, 1);
                }
                else if (each.second == -1)
                {
                    decreasing.update(target, 1);
                }
            }
        }
    }
    return res;
}

ll solve (int entry)
{
    computesum (entry, entry);
    int cent = centroid (entry, entry, subsum [entry]);
    ll res = solveTree (cent);
    blocked [cent] = true;
    for (int each: adj [cent])
    {
        if (!blocked [each])
        {
            res += solve (each);
        }
    }
    return res;
}

//int testcases;
int main ()
{
    scanf ("%d%lld", &n, &k);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &num);
        weights [x] = num - k;
    }
    for (int x = 0; x < n - 1; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back (to);
        adj [to].push_back (from);
    }
    //ll result = solve (1);
    printf ("%lld\n", solve(1));
    /*
    string dir = "/Users/jackyhe/Desktop/C++/DMOJ/UTSOpen/P4TestData";
    
    vector <ll> ultimateResults;
    for (int temp = 1; temp <= 111; temp++)
    {
        freopen((dir+"/input" + to_string(temp) + ".txt").c_str(), "r", stdin);
        memset (weights, 0, sizeof (weights));
        memset (subsum, 0, sizeof (subsum));
        for (int x = 0; x < MAXN; x++)
        {
            adj [x].clear();
        }
        memset (blocked, false, sizeof(blocked));
        
        scanf ("%d%lld", &n, &k);
        for (int x = 1; x <= n; x++)
        {
            scanf ("%lld", &num);
            weights [x] = num - k;
        }
        for (int x = 0; x < n - 1; x++)
        {
            scanf ("%d%d", &from, &to);
            adj [from].push_back (to);
            adj [to].push_back (from);
        }
        ll result = solve (1);
        printf ("%lld\n", result);
        ultimateResults.push_back (result);
        fclose(stdin);
    }
    
    for (int x = 0; x < (int)ultimateResults.size(); x++)
    {
        ofstream file;
        file.open (dir + "/output" + to_string (x+1) + ".txt");
        file << ultimateResults [x] << endl;
        file.close();
    }
    */
    return 0;
}

