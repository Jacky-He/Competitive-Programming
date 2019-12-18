#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;
typedef long long int ll;

int n, m, k;
int from, to;
ll sum;
vector <pair <int, ll>> adj [MAXN];
bool visited [MAXN];
ll dis [MAXN];
bool flag [MAXN];
queue <int> Q;

int main ()
{
    scanf ("%d%d%d", &n, &m, &k);
    for (int x = 1; x <= m; x++)
    {
        scanf ("%d%d%lld", &from, &to, &sum);
        adj [from].push_back ({to, sum});
        adj [to].push_back ({from, sum});
    }
    for (int x = 1; x <= n; x++)
    {
        if (!visited [x])
        {
            vector <int> flag1;
            vector <int> flag2;
            Q.push(x);
            visited [x] = true;
            dis [x] = 0;
            flag1.push_back (x);
            flag [x] = true;
            while (!Q.empty())
            {
                int temp = Q.front();
                Q.pop();
                flag [temp] ? flag1.push_back(temp) : flag2.push_back(temp);
                for (pair <int, ll> each: adj [temp])
                {
                    if (!visited [each.first])
                    {
                        visited [each.first] = true;
                        dis [each.first] = each.second - dis [temp];
                        flag [each.first] = !flag [temp];
                        Q.push (each.first);
                    }
                    else if (dis [each.first] != each.second - dis [temp])
                    {
                        printf ("%d\n", 0);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
