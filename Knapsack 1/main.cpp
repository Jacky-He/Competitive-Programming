#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int n, w;
ll value, weight;
ll dp [100001];
pair <int, int> items [101];
int main ()
{
    scanf ("%d%d", &n, &w);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld%lld", &weight, &value);
        for (int y = w; y >= weight; y--)
        {
            dp [y] = max (dp [y], dp [y - weight] + value);
        }
    }
    printf ("%lld\n", dp [w]);
    return 0;
}
