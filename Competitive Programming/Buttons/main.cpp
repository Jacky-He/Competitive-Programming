#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, result;
int main()
{
    scanf ("%lld", &n);
    for (int i = 1, j = n - 1; i < n; i++, j--)
    {
        result += i*j;
    }
    result += n;
    printf ("%lld\n", result);
    return 0;
}