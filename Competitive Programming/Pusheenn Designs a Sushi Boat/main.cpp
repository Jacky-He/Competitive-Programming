#include <bits/stdc++.h>
#define MOD 998244353
typedef long long int ll;
using namespace std;
int n, k, piece;
ll dp [1001][1001]; //first: value, second, reference;
ll weight [1001];
int main ()
{
    scanf ("%d%d", &n, &k);
    int max = 0;
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &piece);
        if (piece > max)
        {
            max = piece;
        }
        weight [piece]++;
    }
    for (int x = 0; x <= max; x++)
    {
        dp [x][0] = 1;
    }
    for (int x = 1; x <= max; x++)
    {
        for (int y = 1; y <= k; y++)
        {
            dp [x][y] = ((dp [x - 1][y - 1]*weight [x])%MOD + dp [x - 1][y]) %MOD;
        }
    }
    printf ("%lld\n", dp [max][k]);
    return 0;
}
