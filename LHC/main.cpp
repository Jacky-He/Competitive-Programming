#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct triplet
{
    ll secondmax, maxn, secondmaxn;
};
int nodes, a, b;
vector <int> adj [400001];
pair <ll, ll> down [400001];  //first: maxdis, second: numleaves
pair <ll, ll> up [400001]; //first: maxdis, second: numleaves
triplet maxmaxn [400001];
bool visited [400001];
ll cnt, cntmax;
queue <int> Q;
pair <ll, ll> dfs (int node)
{
    visited [node] = true;
    ll maxdis = 0, numleaves = 0, secondmax = 0, secondmaxn = 0;
    bool visit = false;
    for (int each: adj [node])
    {
        if (!visited [each])
        {
            visit = true;
            visited [node] = true;
            pair <ll, ll> temp = dfs (each);
            if (temp.first > maxdis)
            {
                secondmax = maxdis;
                secondmaxn = numleaves;
                maxdis = temp.first;
                numleaves = temp.second;
            }
            else if (temp.first == maxdis)
            {
                numleaves += temp.second;
            }
            else if (temp.first > secondmax)
            {
                secondmax = temp.first;
                secondmaxn = temp.second;
            }
            else if (temp.first == secondmax)
            {
                secondmaxn += temp.second;
            }
        }
    }
    if (!visit)
    {
        numleaves = 1;
    }
    down [node] = {maxdis + 1, numleaves};
    maxmaxn [node].maxn = numleaves;
    maxmaxn [node].secondmax = secondmax;
    maxmaxn [node].secondmaxn = secondmaxn;
    return down [node];
}
void bfs (int node)
{
    visited [node] = true;
    Q.push (node);
    up [node] = {1, 1};
    cntmax = down [node].first;
    cnt = down [node].second;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                pair <ll, ll> some = {0, 0};
                if (maxmaxn [temp].maxn == down [each].second && down [each].first == down [temp].first - 1)
                {
                    some.first = maxmaxn [temp].secondmax;
                    some.second = maxmaxn [temp].secondmaxn;
                }
                else if (down [each].first == down [temp].first - 1)
                {
                    some.first = down [temp].first - 1;
                    some.second = down [temp].second - down [each].second;
                }
                else
                {
                    some.first = down [temp].first - 1;
                    some.second = down [temp].second;
                }
                if (up [temp].first + 1 == some.first + 2)
                {
                    up [each].first = up [temp].first + 1;
                    up [each].second = up [temp].second + some.second;
                }
                else if (up [temp].first + 1 > some.first + 2)
                {
                    up [each] = up [temp];
                    up [each].first++;
                }
                else
                {
                    up [each] = some;
                    up [each].first += 2;
                }
                pair <ll, ll> cmpmax;
                if (up [each].first == down [each].first)
                {
                    cmpmax.first = up [each].first;
                    cmpmax.second = up [each].second + down [each].second;
                }
                else if (up [each].first < down [each].first)
                {
                    cmpmax = down [each];
                }
                else
                {
                    cmpmax = up [each];
                }
                if (cmpmax.first > cntmax)
                {
                    cntmax = cmpmax.first;
                    cnt = cmpmax.second;
                }
                else if (cmpmax.first == cntmax)
                {
                    cnt += cmpmax.second;
                }
                Q.push (each);
            }
        }
    }
}
int main ()
{
    scanf ("%d", &nodes);
    for (int x = 1; x < nodes; x++)
    {
        scanf ("%d%d", &a, &b);
        adj [a].push_back (b);
        adj [b].push_back (a);
    }
    dfs (1);
    memset (visited, 0, sizeof (visited));
    bfs (1);
    printf("%lld %lld\n", cntmax, cnt/2);
    return 0;
}