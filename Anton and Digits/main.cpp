#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll num [10];
ll result;
int main()
{
    scanf ("%lld%lld%lld%lld", &num [2], &num [3], &num [5], &num [6]);
    ll temp = min(min (num[2], num[5]), num [6]);
    result += temp*256;
    num [2] -= temp;
    temp = min (num [2], num [3]);
    result += temp*32;
    printf ("%lld\n", result);
    return 0;
}