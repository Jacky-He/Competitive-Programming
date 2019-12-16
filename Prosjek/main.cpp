#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long int ll;

int n, k, num;
int nums [300005];

double result = 0;

bool check (int average)
{
    ll temp [n + 1];
    ll psa [n + 1];
    psa [0] = 0;
    pair <ll, int> maxsum [n + 1];
    maxsum [0] = {-INF, 0};
    for (int x = 1; x <= n; x++)
    {
        temp [x - 1] = (nums [x - 1] - average);
        psa [x] = psa [x - 1] + temp [x - 1];
    }
    for (int x = 1; x <= n; x++)
    {
        if (maxsum [x - 1].first + temp [x - 1] > temp [x - 1])
        {
            maxsum [x].first = maxsum [x - 1].first + temp [x - 1];
            maxsum [x].second = maxsum [x - 1].second + 1;
        }
        else
        {
            maxsum [x].first = temp [x - 1];
            maxsum [x].second = 1;
        }
    }
    bool res = false;
    for (int x = k; x <= n; x++)
    {
        ll sum1 = psa [x] - psa [x - k];
        int sz1 = k;
        ll sum2 = sum1 + maxsum [x - k].first;
        int sz2 = k + maxsum [x - k].second;
        if (sum1 >= 0 || sum2 >= 0)
        {
            result = max (result, double(double(sum1) + double(sz1)*double(average))/double(sz1));
            result = max (result, double(double(sum2) + double(sz2)*double(average))/double(sz2));
            res = true;
        }
    }
    return res;
}

int main ()
{
    scanf ("%d%d", &n, &k);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        nums [x] = num;
    }
    int lo = 1;
    int hi = 1e6;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi)/2;
        if (check (mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    check (hi);
    check (lo);
    printf ("%f\n", result);
    return 0;
}
