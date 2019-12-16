#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
typedef long long int ll;
using namespace std;

int n, num;
vector <int> integers;

int main ()
{
    scanf ("%d", &n);
    int negativecnt = 0;
    bool zero = false;
    ll sum = 0;
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        integers.push_back (abs (num));
        if (num < 0)
        {
            negativecnt++;
        }
        else if (num == 0)
        {
            zero = true;
        }
        sum += abs (num);
    }
    if (negativecnt%2 == 0 || zero)
    {
        printf ("%lld\n", sum);
        return 0;
    }
    int mini = INF;
    for (int each: integers)
    {
        mini = min (mini, each);
    }
    printf ("%lld\n", sum - mini*2);
    return 0;
}
