#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long int ll;
ll psaforward [300003];
ll psa2forward [300003];
ll n, k, num;
vector <ll> arr;
ll baker = 0;
ll sum = INF;
unordered_map <ll, ll> lookup;
ll p1, p2;
int main ()
{
    scanf ("%lld", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%lld", &num);
        arr.push_back (num);
        lookup [num] = x + 1;
    }
    sort (arr.begin(), arr.end());
    scanf ("%lld", &k);
    for (int x = 1; x <= (int) arr.size(); x++)
    {
        psaforward [x] = psaforward [x - 1] + arr [x - 1];
        psa2forward [x] = (x - 1)*arr [x - 1] - psaforward [x - 1] + psa2forward [x - 1];
    }
    for (ll i = 1, j = k; j <= n; i++, j++)
    {
        ll right = psa2forward [j];
        ll left = psa2forward [i - 1] + (psaforward [j] - psaforward [i - 1])*(i - 1) - psaforward [i - 1]*(j - i + 1);
        if (right - left < sum)
        {
            sum = right - left;
            p1 = i;
            p2 = j;
        }
    }
    for (ll x = p1; x <= p2; x++)
    {
        printf ("%lld ", lookup [arr [x - 1]]);
    }
}

