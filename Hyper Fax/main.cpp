#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
ll dist, fuel;
vector <pair <ll, ll>> v;
ll dp [2002][2002][2];
ll psa [2002];
ll solve (int left, int right, bool side) //0: left, 1: right
{
    ll& ret = dp [left][right][side];
    if (ret != -1)
    {
        return ret;
    }
    if (left == right && v [right - 1].first == 0)
    {
        return ret = v [right - 1].second;
    }
    if (left >= right)
    {
        return ret = 0;
    }
    if (side)
    {
        ret = max (0LL, ret);
        ll temp = solve (left, right - 1, 1);
        ll dis = abs(v [right - 1].first - v[right - 2].first);
        if (temp >= dis)
        {
            ret = max (ret, temp - dis + v [right - 1].second);
        }
        temp = solve (left, right - 1, 0);
        dis = abs (v [left - 1].first - v [right - 1].first);
        if (temp >= dis)
        {
            ret = max (ret, temp - dis + v [right - 1].second);
        }
        return ret;
    }
    ret = max (0LL, ret);
    ll temp = solve (left + 1, right, 0);
    ll dis = abs (v [left].first - v [left - 1].first);
    if (temp >= dis)
    {
        ret = max (ret, temp - dis + v [left - 1].second);
    }
    temp = solve (left + 1, right, 1);
    dis = abs (v [left - 1].first - v [right - 1].first);
    if (temp >= dis)
    {
        ret = max (ret, temp - dis + v [left - 1].second);
    }
    return ret;
}
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < 2002; x++)
    {
        for (int y  = 0; y < 2002; y++)
        {
            dp [x][y][0] = -1;
            dp [x][y][1] = -1;
        }
    }
    for (int x = 0; x < n; x++)
    {
        scanf ("%lld%lld", &dist, &fuel);
        v.push_back ({dist, fuel});
    }
    sort (v.begin(), v.end());
    for (int x = 1; x <= v.size(); x++)
    {
        psa [x] = psa [x - 1] + v[x - 1].second;
    }
    ll result = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if (solve (x, y, 1) || solve (x, y, 0))
            {
                result = max (result, psa [y] - psa [x - 1]);
            }
        }
    }
    printf ("%lld\n", result);
    return 0;
}
