#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
#define MAXN 200005
using namespace std;

int n, k;
vector <pair <int, int>> adj [MAXN];
int subtreesum [MAXN];
bool blocked [MAXN];
map <int, int> lengthmin;
vector <pair <int, int>> pathlengths;

void computeSum (int node, int prev)
{
    subtreesum [node] = 1;
    for (pair <int, int> each: adj [node])
    {
        if (!blocked [each.first] && each.first != prev)
        {
            computeSum (each.first, node);
            subtreesum [node] += subtreesum [each.first];
        }
    }
}

int centroid (int node, int prev, int total)
{
    for (pair <int, int> each: adj [node])
    {
        if (!blocked [each.first] && each.first != prev && 2*subtreesum [each.first] > total)
        {
            return centroid (each.first, node, total);
        }
    }
    return node;
}

void computePaths (int node, int prev, int sum, int highways)
{
    pathlengths.push_back ({sum, highways});
    for (pair <int, int> each: adj [node])
    {
        if (!blocked [each.first] && each.first != prev)
        {
            computePaths (each.first, node, sum + each.second, highways + 1);
        }
    }
}

int solveTree (int root)
{
    lengthmin.clear();
    int res = INF;
    for (pair <int, int> each: adj [root])
    {
        if (!blocked [each.first])
        {
            pathlengths.clear();
            computePaths (each.first, root, each.second, 1);
            for (pair <int, int> path: pathlengths)
            {
                if (path.first == k)
                {
                    res = min (res, path.second);
                }
                else if (path.first < k)
                {
                    if (lengthmin.count (k - path.first))
                    {
                        res = min (res, lengthmin [k - path.first] + path.second);
                    }
                }
            }
            for (pair <int, int> path: pathlengths)
            {
                lengthmin [path.first] = lengthmin [path.first] == 0? path.second : min (lengthmin [path.first], path.second);
            }
        }
    }
    return res;
}

int solve (int entry)
{
    computeSum (entry, entry);
    int cent = centroid (entry, entry, subtreesum [entry]);
    int mini = solveTree (cent);
    blocked [cent] = true;
    for (pair <int, int> each: adj [cent])
    {
        if (!blocked [each.first])
        {
            mini = min (mini, solve (each.first));
        }
    }
    return mini;
}


int best_path (int N, int K, int H[][2], int L[])
{
    n = N; k = K;
    for (int x = 0; x < n - 1; x++)
    {
        adj [H[x][0]].pb ({H[x][1], L[x]});
        adj [H[x][1]].pb ({H[x][0], L[x]});
    }
    int res = solve (0);
    return res == INF? -1: res;
}
