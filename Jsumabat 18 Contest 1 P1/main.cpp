#include <bits/stdc++.h>
using namespace std;
int n, k, a, b;
vector <int> adj [100001];
int dis [100001];
bool visited [100001];
queue <int> Q;
int main ()
{
    scanf("%d%d", &n, &k);
    for (int x = 0; x < n - 1; x++)
    {
        scanf("%d%d", &a, &b);
        adj [a].push_back (b);
        adj [b].push_back (a);
    }
    Q.push (1);
    dis [1] = 1;
    int last = 1;
    visited [1] = 1;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        last = temp;
        for (int each: adj [temp])
        {
            if (!visited [each])
            {
                visited [each] = true;
                dis [each] = dis [temp] + 1;
                Q.push (each);
            }
        }
    }
    memset (visited, 0, sizeof (visited));
    Q.push (last);
    dis [last] = 1;
    visited [last] = true;
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
                Q.push (each);
            }
        }
    }
    for (int x = 1; x <= n; x++)
    {
        if (dis [x] > k)
        {
            printf ("NO U\n");
            return 0;
        }
    }
    printf ("Graph Theory!\n");
    return 0;
}
