#include <bits/stdc++.h>
using namespace std;

int n;
int from, to;
vector <int> adj [100];
int dis [100];
queue<int> q;

int main ()
{
    for (int x = 0; x < 5; x++)
    {
        for (int i = 0; i < 100; i++)
        {
            adj [i].clear();
        }
        memset (dis, 0x3f, sizeof (dis));
        scanf ("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf ("%d%d", &from, &to);
            adj [from].push_back(to);
            adj [to].push_back(from);
        }
        q.push(1);
        dis [1] = 0;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (int each: adj [temp])
            {
                if (dis [each] > dis [temp] + 1)
                {
                    dis [each] = dis [temp] + 1;
                    q.push (each);
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int node : adj [i])
            {
                if (dis [i] == dis [node])
                {
                    cnt++;
                }
            }
        }
        printf ("%d\n", cnt/2);
    }
    return 0;
}
