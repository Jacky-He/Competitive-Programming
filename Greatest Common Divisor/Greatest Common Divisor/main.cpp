#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll a, b, k;
ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
vector <ll> forwards;
vector <ll> backwards;
int main ()
{
    scanf ("%lld%lld%lld", &a, &b, &k);
    ll gcd = gcf (a, b);
    ll root = (int)(sqrt(gcd));
    for (int x = 1; (root*root == gcd)? (x < root) : (x <= root); x++)
    {
        if (gcd%x == 0)
        {
            forwards.push_back (x);
            backwards.push_back (gcd/x);
        }
    }
    if (root*root == gcd)
    {
        forwards.push_back (root);
    }
    if (k > forwards.size() + backwards.size())
    {
        printf ("%d\n", -1);
        return 0;
    }
    if (k <= backwards.size())
    {
        printf ("%lld\n", backwards [k - 1]);
        return 0;
    }
    printf ("%lld\n", forwards [forwards.size() - (k - backwards.size())]);
    return 0;
}
