#include <bits/stdc++.h>
using namespace std;
struct triplet {int first, second, third;};
int nodes, edges, cost;
int* from; int* to; int* t;
bool visited [100001];
bool visited2 [100001];
int down [100001]; //first: down length
int up [100001];
pair <int, int> maxmaxn [100001]; //first: secondmax, second: maxn third: maximum
vector <pair <int, int>> adj [100001];
vector <pair <int, int>> subtrees; //first: radius, second: diameter
queue <int> Q;
int dfs (int node)
{
    visited [node] = true;
    int result = 0;     //parent
    int secondmax = 0;  //children
    int maxnumber = 0;  //children
    for (pair <int, int> each: adj [node])
    {
        if (!visited [each.first])
        {
            int temp = dfs (each.first);
            if (temp + each.second == result)
            {
                maxnumber++;
            }
            if (temp + each.second > result)
            {
                maxnumber = 1;
                secondmax = result;
                result = temp + each.second;
            }
            else if (temp + each.second > secondmax)
            {
                secondmax = temp + each.second;
            }
        }
    }
    down [node] = result;
    maxmaxn [node].first = secondmax;
    maxmaxn [node].second = maxnumber;
    return result;
}
pair <int, int> bfs (int node)
{
    Q.push (node);
    up [node] = 0;
    visited2 [node] = true;
    pair <int, int> raddia = {down [node], down [node]};
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (pair <int, int> each: adj [temp])
        {
            if (!visited2 [each.first])
            {
                visited2 [each.first] = true;
                int maxnum = 0;
                if (maxmaxn [temp].second == 1 && down [each.first] + each.second == down [temp])
                {
                    maxnum = maxmaxn [temp].first;
                }
                else
                {
                    maxnum = down [temp];
                }
                up [each.first] = max (up [temp] + each.second, maxnum + each.second);
               //cout << each.first << " " << up [temp] + each.second << " " << maxnum + each.second << endl;
                raddia.first = min (raddia.first, max (up [each.first], down [each.first]));
                raddia.second = max (raddia.second, max (up [each.first], down [each.first]));
                Q.push (each.first);
            }
        }
    }
    return raddia;
}
void getRadiusAndDiameter()
{
    for (int x = 0; x < nodes; x++)
    {
        if(!visited [x])
        {
            dfs (x);
            subtrees.push_back (bfs (x));
        }
    }
}
void computeAdj ()
{
    for (int x = 0; x < edges; x++)
    {
        adj [from[x]].push_back ({to[x], t[x]});
        adj [to[x]].push_back ({from[x], t[x]});
    }
}
int solve ()
{
    int maximum = -1; int secondmax = -1; int firstdia = -1, seconddia = -1;
    int maxindex = -1; int secondmaxindex = -1;
    for (int x = 0; x < (int)subtrees.size(); x++)
    {
        if (subtrees [x].first > maximum)
        {
            secondmax = maximum;
            secondmaxindex = maxindex;
            seconddia = firstdia;
            maximum = subtrees [x].first;
            maxindex = x;
            firstdia = subtrees[x].second;
        }
        else if (subtrees [x].first > secondmax)
        {
            seconddia = subtrees [x].second;
            secondmax = subtrees [x].first;
            secondmaxindex = x;
        }
    }
    if (secondmaxindex != -1)
    {
        int current = max(max (maximum + secondmax + cost, firstdia), seconddia);
        for (int x = 0; x < (int) subtrees.size(); x++)
        {
            if (x != maxindex && x != secondmaxindex)
            {
                current = max(subtrees[x].second, max(current, secondmax + subtrees[x].first + 2 * cost));
            }
        }
        return current;
    }
    return firstdia;
}
int travelTime (int N, int M, int L, int A[], int B[], int T[])
{
    nodes = N; edges = M; cost = L; from = A; to = B; t = T;
    computeAdj ();
    getRadiusAndDiameter ();
    return solve ();
}
/*int main ()
{
    int A [] = {0, 8, 2, 5, 5, 1, 1, 10};
    int B [] = {8, 2, 7, 11, 1, 3, 9, 6};
    int T [] = {4, 2, 4, 3, 7, 1, 5, 3};
    cout << travelTime (12, 8, 2, A, B, T);
    return 0;
}*/