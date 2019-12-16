#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;

int n;
ll student;
ll maxes = 0;
ll psa [100005];

int main ()
{
    scanf ("%d", &n);
    psa [0] = 1;
    ll closestmax = 0;
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &student);
        if (student >= maxes)
        {
            closestmax = x;
        }
        if(x == n)
        {
            printf ("%lld\n", psa [closestmax-1]);
            return 0;
        }
        maxes = max (student, maxes);
        psa [x] = (psa [closestmax-1]+psa [x - 1])%MOD;
    }
    return 0;
}
