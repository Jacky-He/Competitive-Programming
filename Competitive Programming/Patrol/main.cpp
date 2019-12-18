#include <bits/stdc++.h>
#define MAXN 100005
#define pb push_back
using namespace std;

int n, k, from, to;
vector <int> adj [MAXN];
bool visited [MAXN];
int dis [MAXN];
int previ [MAXN];
queue <int> Q;

pair <int, int> dfs (int node, int prev)
{
    pair <int, int> maxdis = {node, dis [node]};
    for (int each: adj [node])
    {
        if (each != prev && !visited [each])
        {
            dis [each] = dis [node] + 1;
            pair <int, int> temp = dfs (each, node);
            if (temp.second > maxdis.second)
            {
                maxdis = temp;
            }
        }
    }
    return maxdis;
}

pair <int, int> diameter (int root)
{
    dis [root] = 0;
    pair <int, int> maxdis = dfs (root, root);
    visited [root] = false;
    Q.push (maxdis.first);
    visited [maxdis.first] = true;
    dis [maxdis.first] = 0;
    int maxn = 0;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                dis [each] = dis [temp] + 1;
                maxn = max (maxn, dis [each]);
                Q.push (each);
            }
        }
    }
    return {maxn, maxdis.second};
}

int solve (int node)
{
    dis [node] = 0;
    pair <int, int> maxdis = dfs (node, node);
    visited [maxdis.first] = true;
    dis [maxdis.first] = 0;
    Q.push (maxdis.first);
    pair <int, int> maxn = {maxdis.first, 0}; //first: node, second: dis
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                dis [each] = dis [temp] + 1;
                previ [each] = temp;
                if (dis [each] > maxn.second)
                {
                    maxn = {each, dis [each]};
                }
                Q.push (each);
            }
        }
    }
    memset (visited, false, sizeof (visited));
    vector <int> diameterpath;
    vector <int> radii;
    int curr = maxn.first;
    while (curr != maxdis.first)
    {
        diameterpath.pb (curr);
        curr = previ [curr];
        visited [curr] = true;
    }
    diameterpath.pb (curr);
    visited [curr] = true;
    int res = 0;
    for (int each: diameterpath)
    {
        pair <int, int> ret = diameter (each);
        radii.pb (ret.second);
        res = max (ret.first, res);
    }
    int maxi = 0;
    int maximaxi = 0;
    for (int each: radii)
    {
        maximaxi = max (maximaxi, maxi - 1 + each);
        maxi = max(maxi - 1, each);
    }
    return maxn.second + max (res, maximaxi);
}

int main ()
{
    scanf ("%d%d", &n, &k);
    for (int x = 0; x < n - 1; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].pb (to);
        adj [to].pb (from);
    }
    if (k == 1)
    {
        printf ("%d\n", 2*(n - 1) - diameter (1).first + 1);
    }
    else if (k == 2)
    {
        printf ("%d\n", 2*(n - 1) - solve (1) + 2);
    }
    return 0;
}

/*
 
 10 2
 1 2
 2 3
 3 4
 4 5
 5 6
 3 7
 7 8
 4 9
 9 10
 
 
 */




