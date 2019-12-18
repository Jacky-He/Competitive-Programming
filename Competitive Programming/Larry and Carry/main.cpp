#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int n;
ll num;
ll thing [20];
bool viable (ll a, ll b)
{
    while (a != 0 && b != 0)
    {
        if (a%10 + b%10 >= 10)
        {
            return false;
        }
        a /= 10;
        b /= 10;
    }
    return true;
}

int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%lld", &num);
        thing [x] = num;
    }
    int result = 0;
    for (int x = 0; x < (1 << n); x++)
    {
        int sum = 0;
        bool flag = false;
        int cnt = 0;
        for (int y = 0; y < 20; y++)
        {
            if ((x >> y)&1)
            {
                cnt++;
                if (viable (sum, thing [y]))
                {
                    sum += thing [y];
                }
                else
                {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            result = max (result, cnt);
        }
    }
    printf ("%d\n", result);
    return 0;
}



