#include <bits/stdc++.h>
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define INF 0x3f3f3f3f
#define MAXN 200005
using namespace std;
typedef long long int ll;

int n, lk, rk, lc, rc, a, b;
string str;
vector <int> adj [MAXN];
bool croissant [MAXN];
int subsum [MAXN];
bool blocked [MAXN];

vector <pair <int, int>> numpaths [MAXN]; //index: first, pair first: second, pair second: numpaths
vector <pair <int, int>> numpaths2 [MAXN];
vector <int> allkeys2;
vector <pair <int, int>> allpaths;
vector <int> allkeys;
vector <pair <int, int>> temppaths;

void computeallpaths (int node, int prev, pair <int, int> cnt, int root)
{
    if (node != root)
    {
        allpaths.push_back (cnt);
    }
    for (int each: adj [node])
    {
        if (each != prev && !blocked [each])
        {
            computeallpaths (each, node, {cnt.first + croissant [each], cnt.second + !croissant [each]}, root);
        }
    }
}

void computepaths (int node, int prev, pair <int, int> cnt)
{
    temppaths.push_back (cnt);
    for (int each: adj [node])
    {
        if (each != prev && !blocked [each])
        {
            computepaths (each, node, {cnt.first + croissant [each], cnt.second + !croissant [each]});
        }
    }
}

ll queryallpaths (pair <int, int> p)
{
    int key = (int) (upper_bound (allkeys.begin(), allkeys.end(), p.first) - allkeys.begin() - 1);
    if (key == -1) {return 0;}
    int index = (int) (upper_bound (numpaths [allkeys [key]].begin(), numpaths [allkeys [key]].end(), make_pair(p.second, INF)) - numpaths [allkeys [key]].begin() - 1);
    if (index == -1) {return 0;}
    return numpaths [allkeys[key]][index].second;
}

ll querypaths (pair <int, int> p)
{
    int key = (int) (upper_bound (allkeys2.begin(), allkeys2.end(), p.first) - allkeys2.begin() - 1);
    if (key == -1) {return 0;}
    int index = (int) (upper_bound (numpaths2 [allkeys2 [key]].begin(), numpaths2 [allkeys2 [key]].end(), make_pair(p.second, INF)) - numpaths2 [allkeys2 [key]].begin() - 1);
    if (index == -1) {return 0;}
    return numpaths2 [allkeys2 [key]][index].second;
}

void complete_unique_pairs (vector <pair <int, int>> &v)
{
    vector <pair <int, int>> v2;
    for (int i = (int)v.size() - 1; i >= 0; i--)
    {
        if (v2.empty() || v2 [v2.size() - 1].first != v [i].first)
        {
            v2.push_back (v[i]);
        }
    }
    v.clear();
    for (int i = (int)v2.size() - 1; i >= 0; i--)
    {
        v.push_back(v2[i]);
    }
}

ll solveTree (int root)
{
    ll resrepeat = 0;
    ll resnotrepeat = 0;
    computeallpaths (root, root, {croissant [root], !croissant [root]}, root); //first: croissant, second: kinako bread
    sort (allpaths.begin(), allpaths.end());
    int lastfirst = -1;
    int previous = -1;
    for (pair <int, int> path: allpaths)
    {
        allkeys.push_back (path.first);
        if (path.first != previous)
        {
            lastfirst = previous;
            previous = path.first;
        }
        if (!path.first || lastfirst == -1)
        {
            numpaths [path.first].push_back ({path.second, (int)numpaths [path.first].size() + 1});
            continue;
        }
        pair <int, int> newpair;
        newpair.first = path.second;
        newpair.second = (int)numpaths [path.first].size() + 1;
        int index = (int)(upper_bound (numpaths [lastfirst].begin(), numpaths [lastfirst].end(), make_pair(path.second, INF)) - numpaths [lastfirst].begin()) - 1;
        if (index != -1)
        {
            newpair.second += numpaths [lastfirst][index].second;
        }
        numpaths [path.first].push_back (newpair);
    }
    complete_unique (allkeys);
    for (int key: allkeys)
    {
        complete_unique_pairs (numpaths [key]);
        cout << key << endl;
        for (pair <int, int> each: numpaths [key])
        {
            cout << each.first << " " << each.second << endl;
        }
    }
    
    for (int node: adj [root])
    {
        if (!blocked [node])
        {
            computepaths (node, root, {croissant [node] + croissant [root], !croissant [node] + !croissant [root]});
            sort (temppaths.begin(), temppaths.end());
            lastfirst = -1;
            previous = -1;
            for (pair <int, int> path: temppaths)
            {
                allkeys2.push_back (path.first);
                if (path.first != previous)
                {
                    lastfirst = previous;
                    previous = path.first;
                }
                if (!path.first || lastfirst == -1)
                {
                    numpaths2 [path.first].push_back ({path.second, (int)numpaths2 [path.first].size() + 1});
                    continue;
                }
                pair <int, int> newpair;
                newpair.first = path.second;
                newpair.second = (int)numpaths2 [path.first].size() + 1;
                int index = (int)(upper_bound (numpaths2 [lastfirst].begin(), numpaths2 [lastfirst].end(), make_pair(path.second, INF)) - numpaths2 [lastfirst].begin()) - 1;
                if (index != -1)
                {
                    newpair.second += numpaths2 [lastfirst][index].second;
                }
                numpaths2 [path.first].push_back (newpair);
            }
            complete_unique(allkeys2);
            for (int key: allkeys2)
            {
                complete_unique_pairs (numpaths2 [key]);
                cout << "node: " << node << endl;
                cout << key << endl;
                for (pair <int, int> each: numpaths2 [key])
                {
                    cout << each.first << " " << each.second << endl;
                }
            }
            
            for (pair <int, int> each: temppaths)
            {
                cout << each.first << " " << each.second << endl;
                if (each.first > rc || each.second > rk)
                {
                    continue;
                }
                if (each.first >= lc && each.first <= rc && each.second >= lk && each.second <= rk)
                {
                    resnotrepeat++;
                }
                pair <int, int> upper = {rc - each.first + croissant [root], rk - each.second + !croissant [root]};
                pair <int, int> minus1 = {rc - each.first + croissant [root], lk - each.second - 1 + !croissant [root]};
                pair <int, int> minus2 = {lc - each.first - 1 + croissant [root], rk - each.second + !croissant [root]};
                pair <int, int> add = {lc - each.first - 1 + croissant [root], lk - each.second - 1 + !croissant [root]};
                ll num1 = queryallpaths(upper) - queryallpaths(minus1) - queryallpaths(minus2) + queryallpaths(add);
                ll num2 = querypaths(upper) - querypaths(minus1) - querypaths (minus2) + querypaths (add);
                cout << node << " " << num1 << " " << num2 << endl;
                resrepeat += num1 - num2;
            }
            for (int key: allkeys2) {numpaths2 [key].clear();}
            temppaths.clear();
            allkeys2.clear();
        }
    }
    for (int key: allkeys) {numpaths [key].clear();}
    allpaths.clear();
    allkeys.clear();
    pair <int, int> temp = {croissant [root], !croissant [root]};
    resnotrepeat += (temp.first >= lc && temp.first <= rc && temp.second >= lk && temp.second <= rk);
    cout << resrepeat << " " << resnotrepeat << endl;
    return resrepeat/2 + resnotrepeat;
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

ll solve (int entry)
{
    computesum (entry, entry);
    int cent = centroid (entry, entry, subsum [entry]);
    ll res = solveTree (cent);
    //cout << cent << " " << res << endl;
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

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> lk >> rk >> lc >> rc;
    cin >> str;
    for (int x = 0; x < n; x++)
    {
        croissant [x + 1] = (str [x] == 'C');
    }
    for (int x = 1; x <= n - 1; x++)
    {
        cin >> a >> b;
        adj [a].push_back (b);
        adj [b].push_back (a);
    }
    //cout << solve (1) << endl;
    blocked [1] = true;
    cout << solveTree (14) << endl;
    //cout << solveTree (1) << endl;
    return 0;
}

/*
10 0 9 0 2
KCCKCKKCKK
1 2
1 3
2 4
1 5
3 6
3 7
6 8
5 9
5 10

 
 10 1 4 0 10
 KKKKKKKKKK
 1 2
 2 3
 3 4
 4 5
 5 6
 6 7
 7 8
 8 9
 9 10
 
 
 16 0 16 0 16
 CKCCKKCKCKCCKKKC
 1 2
 1 3
 1 14
 14 16
 14 15
 2 6
 2 7
 6 12
 7 8
 8 13
 7 9
 3 4
 3 5
 4 11
 5 10
 
 

*/
