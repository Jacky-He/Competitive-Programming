#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll c, d, e;
int main ()
{
    scanf ("%lld%lld%lld", &c, &d, &e);
    if ((c^d) != e)
    {
        printf ("0\n");
        return 0;
    }
    ll result = 1;
    while (e != 0)
    {
        if (e&1)
        {
            result <<= 1;
        }
        e >>= 1;
    }
    printf ("%lld\n", result);
    return 0;
}
