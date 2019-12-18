#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long int ll;

int n, m;
ll num;
vector <ll> small;
vector <ll> large;

bool check (ll maxdiff)
{
    int i = 0, j = 0;
    while (i < (int)small.size() && j < (int) large.size())
    {
        while (small [i] - maxdiff > large [j] && j < large.size())
        {
            j++;
        }
        if (abs (small [i] - large [j]) > maxdiff) {return false;}
        i++;
        j++;
    }
    if (i < (int) small.size())
    {
        return false;
    }
    return true;
}

int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < n; x++)
    {
        scanf ("%lld", &num);
        n < m ? small.push_back (num) : large.push_back(num);
    }
    for (int x = 0; x < m; x++)
    {
        scanf ("%lld", &num);
        n < m ? large.push_back(num) : small.push_back(num);
    }
    sort (small.begin(), small.end());
    sort (large.begin(), large.end());
    ll lo = 0;
    ll hi = 1e10;
    ll res = 0;
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi)/2;
        if (check (mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    if (check (lo))
    {
        res = lo;
    }
    else if (check (hi))
    {
        res = hi;
    }
    printf ("%lld\n", res);
}
