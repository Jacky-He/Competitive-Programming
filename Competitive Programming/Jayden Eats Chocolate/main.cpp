#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int destination;
    scanf ("%d", &destination);
    int dp [destination + 1];
    int options [3];
    scanf ("%d%d%d", &options [0], &options [1], &options [2]);
    sort (options, options + 3);
    memset (dp, 0, sizeof (dp));
    for (int i = 0; i < 3; i++)
    {
        dp [options [i]] = max (dp [options[i]], 1);
        for (int x = 0; x <= destination; x++)
        {
            if (x - options [i] >= 0 && dp [x - options [i]] != 0)
            {
                dp [x] = max (dp [x], dp [x - options [i]] + 1);
            }
        }
    }
    printf ("%d\n", dp [destination]);
    return 0;
}
