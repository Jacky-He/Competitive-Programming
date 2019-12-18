#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long int ll;
typedef __int128_t bigint;

ll n, t;
ll a, b;
ll maxhap = 0;
vector <pair <ll, ll>> v;

bool check (ll hap)
{
    ll orders = 0;
    for (pair <ll, ll> each: v)
    {
        ll dif = each.first - hap;
        if (dif > 0)
        {
            orders += dif/each.second + (dif%each.second == 0 ? 0 : 1);
        }
    }
    return orders > t;
}

int main ()
{
    scanf ("%lld%lld", &n, &t);
    for (int x = 0; x < n; x++)
    {
        scanf("%lld%lld", &a, &b);
        v.push_back ({a, b});
        maxhap = max (maxhap, a);
    }
    ll lo = 0;
    ll hi = maxhap;
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi)/2;
        if (check (mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    if (!check (lo))
    {
        maxhap = lo;
    }
    else if (!check (hi))
    {
        maxhap = hi;
    }
    
    bigint res = 0;
    ll orders = 0;
    for (pair <ll, ll> each: v)
    {
        bigint dif = each.first - maxhap;
        if (dif > 0)
        {
            bigint numterms = dif/each.second + (dif%each.second == 0 ? 0 : 1);
            orders += numterms;
            ll mini = each.first - each.second*(numterms - 1);
            bigint temp = each.first + mini;
            each.first = each.first - each.second*numterms;
            if (numterms%2 == 0)
            {
                numterms /= 2;
            }
            else if (temp%2 == 0)
            {
                temp /= 2;
            }
            bigint sum = (temp%MOD*numterms)%MOD;
            res = (res + sum)%MOD;
        }
    }
    res = (res + ((t - orders)*maxhap)%MOD)%MOD;
    printf ("%lld\n", (ll)res);
    return 0;
}

/*
 3 2
 10 1
 10 1
 10 1
 
 
 */
