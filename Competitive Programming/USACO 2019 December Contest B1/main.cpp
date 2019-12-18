#include <bits/stdc++.h>
#define MAXN 100005
#define endl "\n"
using namespace std;
typedef long long int ll;

int n, m, from, to;
bool H [MAXN];
string line;
string op;
vector <int> adj [MAXN];
queue <int> Q;
int depth [MAXN];
bool visited [MAXN];
pair <int, pair <bool, bool>> sparse [20][MAXN]; //node, true/false H, true/false G


void build ()
{
    Q.push (1);
    visited [1] = true;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                depth [each] = depth [temp] + 1;
                sparse [0][each].first = temp;
                sparse [0][each].second = {H[temp]|H[each], (!H[temp])|(!H[each])};
                Q.push (each);
            }
        }
    }
    
    for (int k = 1; k < 20; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            int mid = sparse [k - 1][i].first;
            if (mid)
            {
                sparse [k][i] = sparse [k - 1][mid];
                sparse [k][i].second = {sparse [k - 1][i].second.first|sparse [k - 1][mid].second.first, sparse [k - 1][i].second.second|sparse [k - 1][mid].second.second};
            }
        }
    }
}

bool query (int from, int to, string op)
{
    if (from == to) return op == "H"? H [from] : !H[from];
    pair <bool, bool> res = {false, false};
    if (depth [from] != depth [to])
    {
        //make from the deeper one;
        if (depth[from] < depth [to])
        {
            int temp = from; from = to; to = temp; //swap;
        }
        int d = depth [from] - depth[to];
        for (int k = 0, diff = d; diff != 0; diff >>= 1, k++)
        {
            if (diff&1)
            {
                res.first |= sparse [k][from].second.first;
                res.second |= sparse [k][from].second.second;
                from = sparse [k][from].first;
            }
        }
    }
    //now they are equal;
    if (from == to) return op == "H" ? res.first : res.second;
    for (int k = 19; k >= 0; k--)
    {
        if (sparse [k][from].first != sparse [k][to].first)
        {
            res.first |= (sparse [k][from].second.first|sparse [k][to].second.first);
            res.second |= (sparse [k][from].second.second|sparse [k][to].second.second);
            from = sparse [k][from].first;
            to = sparse [k][to].first;
        }
    }
    res.first |= (sparse [0][from].second.first|sparse [0][to].second.first);
    res.second |= (sparse[0][from].second.second|sparse[0][to].second.second);
    return op == "H" ? res.first : res.second;
}


int main ()
{
    freopen ("milkvisits.in", "r", stdin);
    freopen ("milkvisits.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> line;
    for (int x = 1; x <= n; x++)
    {
        H [x] = line [x - 1] == 'H';
    }
    for (int x = 0; x < n - 1; x++)
    {
        cin >> from >> to;
        adj [from].push_back (to);
        adj [to].push_back (from);
    }
    build();
    string res = "";
    for (int x = 0; x < m; x++)
    {
        cin >> from >> to >> op;
        if (query (from, to, op)) res += "1";
        else res += "0";
    }
    cout << res << endl;
    return 0;
}

/*
5 5
HHGHG
1 2
2 3
2 4
1 5
1 4 H
1 4 G
1 3 G
1 3 H
5 5 H
 
 */
