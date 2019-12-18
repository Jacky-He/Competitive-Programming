#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
ll num;
queue <ll> q;

int main ()
{
    scanf ("%d", &n);
    q.push (0);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &num);
        q.push (num*x);
    }
    while (q.size() > 1)
    {
        ll first = q.front();
        q.pop();
        ll second = q.front();
        printf ("%lld ", second - first);
    }
    return 0;
}
