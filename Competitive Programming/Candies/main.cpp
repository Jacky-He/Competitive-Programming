#include <iostream>
#include <cstdio>
#include <utility>
#define MOD 1000000007
typedef long long int ll;
using namespace std;
int n, k, children;
ll* dp1 = new ll [100003];
ll* dp2 = new ll [100003];
int main ()
{
    scanf ("%d%d", &n, &k);
    for (int x = 1; x <= k + 1; x++)
    {
        dp1 [x] = 1;
    }
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &children);
        for (int y = 1; y <= k + 1; y++)
        {
            if (y - children > 1)
            {
                dp2 [y] = ((dp1 [y] - dp1 [y - children - 1])%MOD + dp2 [y - 1])%MOD;
            }
            else
            {
                dp2 [y] = (dp1 [y] + dp2 [y - 1])%MOD;
            }
        }
        ll* temp = dp1;
        dp1 = dp2;
        dp2 = temp;
    }
    printf ("%lld\n", ((dp1 [k + 1] - dp1 [k])%MOD + MOD)%MOD);
    return 0;
}
