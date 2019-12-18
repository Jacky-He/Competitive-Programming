#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int n, cost, value;

vector <int> profits;

int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &value);
        profits.push_back (value);
    }
    ll sum = 0;
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &cost);
        profits [x] -= cost;
        if (profits [x] > 0)
        {
            sum += profits [x];
        }
    }
    printf ("%lld\n", sum);
    return 0;
}
