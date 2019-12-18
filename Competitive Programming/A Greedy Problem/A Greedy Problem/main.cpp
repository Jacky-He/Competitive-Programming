#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int ll;

int n, t, q, num;
ll dp [2002];
int nums [2002];

int a, b, ti;

//thanks to Riolku for the idea
void process (int item)
{
    for (int i = t; i >= item; i--)
    {
        dp [i] = (dp [i] + dp [i - item])%MOD;
    }
}

void unprocess (int item)
{
    for (int i = item; i <= t; i++)
    {
        dp [i] = (dp [i] - dp [i - item] + MOD)%MOD;
    }
}

int main ()
{
    scanf ("%d%d%d", &n, &t, &q);
    
    for (int x = 0; x <= t; x++)
    {
        dp [x] = 1;
    }
    
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &num);
        nums [x] = num;
        process (num);
    }
    
    for (int x = 0; x < q; x++)
    {
        scanf ("%d%d%d", &a, &b, &ti);
        if (ti - nums [a] - nums [b] < 0) {printf ("%d\n", 0); continue;}
        unprocess (nums [a]);
        unprocess (nums [b]);
        printf ("%lld\n", dp [ti - nums [a] - nums [b]]);
        process (nums [a]);
        process (nums [b]);
    }
    return 0;
}
