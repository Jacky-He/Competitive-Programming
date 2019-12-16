#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n, m, k, from, to;
vector <int> adj [MAXN];
bool visited [MAXN];
queue <int> Q;

int main ()
{
    scanf ("%d%d%d", &n, &m, &k);
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back (to);
        adj [to].push_back (from);
    }
    int numgraphs = 0;
    for (int x = 1; x <= n; x++)
    {
        if (!visited [x])
        {
            visited [x] = true;
            Q.push (x);
            while (!Q.empty())
            {
                int temp = Q.front();
                Q.pop();
                for (int each: adj [temp])
                {
                    if (!visited [each])
                    {
                        visited [each] = true;
                        Q.push (each);
                    }
                }
            }
            numgraphs++;
        }
    }
    
    int cost = numgraphs - 1;
    int technically = max((n - 1) - m, 0);
    int moveable = min((cost - technically), k);
    printf ("%d\n", max(cost - moveable, 0));
    
   
    return 0;
}




