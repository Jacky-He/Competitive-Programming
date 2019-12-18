#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll n, num;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll forwards [100005];
ll backwards [100005];
vector <ll> elements;
int main ()
{
    scanf ("%lld", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%lld", &num);
        elements.push_back(num);
        if (x == 0)
        {
            forwards [x] = num;
        }
        else
        {
            forwards [x] = gcf (forwards [x - 1], num);
        }
    }
    for (int x = (int)n - 1; x >= 0; x--)
    {
        if (backwards [x] == n - 1)
        {
            backwards [x] = elements [x];
        }
        else
        {
            backwards [x] = gcf (elements [x], backwards [x + 1]);
        }
    }
    ll result = backwards [1];
    for (int x = 1; x < n; x++)
    {
        result = max (gcf (forwards [x - 1], backwards [x + 1]), result);
    }
    printf ("%lld\n", result);
    return 0;
}
