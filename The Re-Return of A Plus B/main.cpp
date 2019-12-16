#include <bits/stdc++.h>
#define seed 20
#define a 22695477
#define c 1
using namespace std;
typedef long long int ll;
ll MOD = ((ll)1 << 32);

ll pre = seed;
ll rando ()
{
    ll next = (a*pre + c)%MOD;
    pre = next;
    return (ll)((((double)next)/(MOD))*10 + 1);
}

int num;
int main ()
{
    scanf ("%d", &num);
    if (num == 1)
    {
        for (int x = 0; x < 1000000; x++)
        {
            printf ("%lld\n", rando() + rando());
        }
    }
    else
    {
        printf ("hello\n");
    }
}
