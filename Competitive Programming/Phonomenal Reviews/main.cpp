#include <bits/stdc++.h>
using namespace std;
int nodes, phos, pw, from, to;
vector <int> adj [100001];
bool visited [100001];
bool isPho [100001];
int dis [100001];
int far, farn, cnt;
bool dfs (int node, int parent)
{
    bool connectPho = false;
    for (int each: adj [node])
    {
        if (each != parent)
        {
            dis [each] = dis [node] + 1;
            bool temp = dfs (each, node);
            connectPho = connectPho | temp;
            if (dis [each] > far && temp)
            {
                far = dis [each];
                farn = each;
            }
        }
    }
    if (isPho [node])
    {
        connectPho = true;
    }
    visited [node] = connectPho;
    return connectPho;
}
int main ()
{
    scanf ("%d%d", &nodes, &phos);
    int start = -1;
    for (int x = 0; x < phos; x++)
    {
        scanf ("%d", &pw);
        start = pw;
        isPho [pw] = true;
    }
    for (int x = 0; x < nodes - 1; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back (to);
        adj [to].push_back (from);
    }
    dfs (start, -1);
    for (int x = 0; x < nodes; x++)
    {
        cnt += visited [x];
    }
    memset (dis, 0, sizeof (dis));
    int something = farn;
    far = 0; farn = -1;
    dfs (something, -1);
    printf ("%d\n", (cnt - 1)*2 - far);
    return 0;
}