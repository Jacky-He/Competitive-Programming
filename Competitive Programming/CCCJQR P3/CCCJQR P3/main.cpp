#include <bits/stdc++.h>
#define MOD 420024900269696969699001
typedef long long int ll;
using namespace std;
ll a, b, c;
int main ()
{
    scanf ("%lld%lld%lld", &a, &b, &c);
    printf ("%lld\n", a%MOD+b%MOD+c%MOD);
    return 0;
}
