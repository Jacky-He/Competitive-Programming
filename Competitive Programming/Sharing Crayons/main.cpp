#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
ll m;
ll num;

map <ll, ll> cnt;

int main ()
{
    scanf ("%d%lld", &n, &m);
    ll sum = 0;
    for (int x = 0; x < n; x++)
    {
        scanf ("%lld", &num);
        sum += num;
        sum %= m;
        cnt [sum]++;
    }
    ll tot = 0;
    for (auto const& each: cnt)
    {
        tot += each.second*(each.second - 1)/2;
    }
    tot += cnt [0];
    printf ("%lld\n", tot);
    return 0;
}
