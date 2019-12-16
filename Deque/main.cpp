#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int n;
ll num;
ll dp [2][3003][3003]; //0, taro, 1, jiro
ll psa [3003];

ll solve (bool who, int from, int to)
{
    if (from == to)
    {
        return dp [who][from][to] = psa [to] - psa [from - 1];
    }
    if (dp [who][from][to] != 0)
    {
        return dp [who][from][to];
    }
    ll op1 = psa [from] - psa [from - 1] + psa [to] - psa [from] - solve (!who, from + 1, to);
    ll op2 = psa [to] - psa [to - 1] + psa [to - 1] - psa [from - 1] - solve (!who, from, to - 1);
    return dp [who][from][to] = max (op1, op2);
}

int main()
{
    scanf ("%d", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf ("%lld", &num);
        psa [x] = psa [x - 1] + num;
    }
    printf ("%lld\n", 2*solve (false, 1, n) - psa [n]);
    return 0;
}