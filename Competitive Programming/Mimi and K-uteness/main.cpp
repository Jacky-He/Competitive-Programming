#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
ll num;
ll psa [200003];
ll minus [200003];
int main ()
{
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &num);
        psa [x] = psa [x - 1] + num;
    }
    ll curr = psa [n];
    ll minus = 0;
    for (int x = 1, multiplier = 1; x <= n; minus += psa [x] + psa [n] - psa [n - x], x++, multiplier++)
    {
        printf("%lld\n", curr*multiplier - minus);
    }
    return 0;
}
