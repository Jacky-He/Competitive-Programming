#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <utility>
typedef long long int ll;
using namespace std;
struct s {ll numnodes, sum, total;};
int n, from, to;
ll values [200003];
vector <int> adj [200003];
s dp [200003];
bool visited [200003];
ll something = 0;
void dfs (int node)
{
    visited [node] = true;
    ll numnodes = 1, sum = values [node], total = 0;
    ll altersum = 0;
    int cnt = 0;
    bool yeah = false;
    for (int each: adj [node])
    {
        if (!visited [each])
        {
            yeah = true;
            cnt++;
            dfs (each);
            total += altersum*dp [each].numnodes + (numnodes - 1)*dp [each].sum + (numnodes - 1)*dp [each].numnodes*values [node] + dp [each].total;
            if (node == 7)
            {
                cout << altersum << " " << numnodes - 1 << " " << total << " liwi" << endl;
            }
            altersum += dp [each].sum;
            numnodes += dp [each].numnodes;
            sum += dp [each].sum + dp [each].numnodes*values [node];
        }
    }
    if (yeah)
    {
        something += values [node];
    }
    total += sum;
    dp [node].numnodes = numnodes;
    dp [node].sum = sum;
    dp [node].total = total;
}

int main ()
{
    ll sum = 0;
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &values [x]);
        sum += values [x];
    }
    for (int x = 1; x < n; x++)
    {
        scanf ("%d%d", &from, &to);
        adj [from].push_back (to);
        adj [to].push_back (from);
    }
    dfs (1);
    for (int x = 1; x <= n; x++)
    {
        cout << x << ": " << dp [x].numnodes << " " << dp [x].sum << " " << dp [x].total << endl;
    }
    printf ("%lld\n", dp [1].total - sum);
    return 0;
}

/*
8
1 2 9 5 4 7 3 8
1 4
2 4
3 4
6 5
5 7
4 7
7 8
*/