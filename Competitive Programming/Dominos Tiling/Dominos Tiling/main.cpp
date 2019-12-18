#include <bits/stdc++.h>
#define MOD 1000000
using namespace std;
typedef long long int ll;
int num;
ll dp [16];
int main ()
{
    dp [1] = 3;
    for (int x = 2; x < 16; x++)
    {
        dp [x] = ((dp [x - 1]*3)%MOD + 2)%MOD;
        for (int y = 1; y < x - 1; y++)
        {
            dp [x] = (dp [x] + (dp [y]*2)%MOD)%MOD;
        }
    }
    for (int x = 0; x < 5; x++)
    {
        scanf ("%d", &num);
        printf ("%lld\n", num%2 == 0? dp [num/2]:0);
    }
    return 0;
}
