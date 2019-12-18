#include <bits/stdc++.h>
using namespace std;
int t, s, f;
int ans (int a, int b)
{
    int c = b - a + 1;
    int cnt = 0;
    int multi = 0;
    int result = 0;
    while (b != 0)
    {
        int currentbit = a&1;
        int repeats = (1 << multi);
        int numleft = repeats - cnt;
        int zerocnt = 0;
        int onecnt = 0;
        if (currentbit)
        {
            onecnt += numleft;
            if (c - onecnt > 0)
            {
                onecnt += ((c - numleft)/(repeats*2))*repeats;
                int remainder = (c-numleft)%(repeats*2);
                onecnt += remainder > repeats? remainder - repeats: 0;
            }
            result += ((onecnt&1)<<multi);
        }
        else
        {
            zerocnt += numleft;
            if (c - zerocnt > 0)
            {
                zerocnt += ((c-numleft)/(repeats*2))*repeats;
                int remainder = (c-numleft)%(repeats*2);
                zerocnt += remainder > repeats? remainder - repeats: 0;
            }
            onecnt = c - zerocnt;
            result += ((onecnt&1)<<multi);
        }
        cnt += ((a&1)<<multi);
        a >>= 1;
        b >>= 1;
        multi++;
    }
    return result;
}
int main ()
{
    scanf ("%d", &t);
    for (int x = 0; x < t; x++)
    {
        scanf ("%d%d", &s, &f);
        printf ("%d\n", ans (s, f));
    }
    return 0;
}
