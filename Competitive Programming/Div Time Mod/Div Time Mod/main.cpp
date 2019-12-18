#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, k;
int main ()
{
    scanf ("%d%d", &n, &k);
    int minx = INF;
    for (int q = 1; q <= n; q++)
    {
        if (n%q == 0)
        {
            int result2 = n/q;
            if (result2 + q*k < minx && (((result2 + q*k)%k) * ((result2 + q*k)/k)) == n)
            {
                minx = result2 + q*k;
            }
        }
    }
    printf ("%d\n", minx);
    return 0;
  /*  scanf ("%d%d", &n, &k);
    int x = 1;
    while ((x/k) * (x%k) != n)
    {
        x++;
    }
    printf ("%d\n", x);
    return 0;*/
    
}
