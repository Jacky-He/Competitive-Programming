#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll l, r, a, k;
int main ()
{
    scanf ("%lld%lld%lld%lld", &l, &r, &a, &k);
    ll classroom = 0;
    l = l - a;
    r = r - a;
    ll rdis = abs(r/k);
    ll ldis = abs(l/k);
    if (rdis == ldis)
    {
        classroom = a - ldis*k;
    }
    else if (ldis < rdis)
    {
        classroom = a + (ldis + 1)*k;
    }
    else
    {
        classroom = a - rdis*k;
    }
    printf ("%lld\n", classroom);
    return 0;
}
