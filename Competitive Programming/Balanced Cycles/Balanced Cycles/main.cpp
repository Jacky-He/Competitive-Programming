#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long int ll;


int n, from, to;
char type;
vector <pair <int, bool>> adj [MAXN]; //r: 1, b: 0 r: 1, b: -1
int subsum [MAXN];
int pathcnt [MAXN*2];
bool blocked [MAXN];
const int offset = MAXN;
vector <pair <int, int>> pathlengths; //first: value, second: length

int centroid (int node, int prev, int total)
{
    for (pair <int, bool> each: adj [node])
    {
        if (!blocked [each.first] && each.first != prev && subsum [each.first]*2 > total)
        {
            return centroid (each.first, node, total);
        }
    }
    return node;
}

void computesum (int node, int prev)
{
    subsum [node] = 1;
    for (pair <int, bool> each: adj [node])
    {
        if (!blocked [each.first] && each.first != prev)
        {
            computesum (each.first, node);
            subsum [node] += subsum [each.first];
        }
    }
}

void computepaths (int node, int prev, int sum, int length)
{
    pathlengths.push_back ({sum, length});
    for (pair <int, bool> each: adj [node])
    {
        if (!blocked [each.first] && each.first != prev)
        {
            computepaths (each.first, node, sum + (each.second? 1:-1), length + 1);
        }
    }
}

ll solveTree (int root)
{
    for (int x = offset - subsum [root]; x <= offset + subsum [root]; x++)
    {
        pathcnt [x] = 0;
    }
    ll res = 0;
    for (pair <int, bool> each: adj [root])
    {
        if (!blocked [each.first])
        {
            pathlengths.clear();
            computepaths (each.first, root, each.second? 1:-1, 1);
            for (pair <int, int> path: pathlengths)
            {
                if (abs(path.first) == 1 && path.second != 1)
                {
                    res++;
                }
                res += pathcnt [1 - path.first + offset];
                res += pathcnt [-1 - path.first + offset];
            }
            for (pair <int, int> path: pathlengths)
            {
                pathcnt [path.first + offset]++;
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
    for (pair <int, bool> each: adj [cent])
    {
        if (!blocked [each.first])
        {
            res += solve (each.first);
        }
    }
    return res;
}

int main ()
{
    scanf ("%d\n", &n);
    for (int x = 0; x < n - 1; x++)
    {
        scanf ("%d %d %c", &from, &to, &type);
        adj [from].push_back ({to, type == 'r'});
        adj [to].push_back ({from, type == 'r'});
    }
    printf ("%lld\n", solve (1));
    return 0;
}



