#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long int ll;
ll n, m;
ll psa [500004];
ll num;
int main ()
{
    scanf ("%lld%lld", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &num);
        psa [x] = psa [x - 1] + num;
    }
    int result = INF;
    int i = 1, j = 1;
    while (j <= n)
    {
        if (psa [j] - psa [i - 1] >= m)
        {
            result = min (result, j - i + 1);
            i++;
        }
        else
        {
            j++;
        }
    }
    printf ("%d\n", result == INF? -1 : result);
    return 0;
}
