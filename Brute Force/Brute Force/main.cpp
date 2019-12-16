#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, q;
int indicator;
int i, change;
int from, to;
int main ()
{
    scanf ("%d%d", &n, &q);
    int arr [n + 1];
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &arr [x]);
    }
    for (int x = 0; x < q; x++)
    {
        scanf ("%d", &indicator);
        if (indicator == 1)
        {
            scanf ("%d%d", &i, &change);
            arr [i] = change;
        }
        else if (indicator == 2)
        {
            ll sum = 0;
            scanf ("%d%d", &from, &to);
            for (int y = from; y <= to; y++)
            {
                sum += arr [y];
            }
            printf ("%lld\n", sum);
        }
    }
    return 0;
}
