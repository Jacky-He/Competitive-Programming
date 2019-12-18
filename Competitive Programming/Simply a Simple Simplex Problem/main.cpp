#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

int t;
ll m;
int main ()
{
    scanf ("%d", &t);
    for (int x = 0; x < t; x++)
    {
        scanf ("%llud", &m);
        ll res = (ll)(ceil(((ll)1 + sqrtl ((ll)1 + 8*m))/(double(2))));
        printf ("%lld\n", res);
    }
    return 0;
}
