#include <bits/stdc++.h>
using namespace std;
int n, t, factor, queries, temp;
int dp [1000005];
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d%d", &t, &factor);
        dp [t] = max (dp [t], factor);
    }
    for (int x = 1; x < 1000005; x++)
    {
        dp [x] = max (dp [x], dp [x - 1]);
    }
    scanf ("%d", &queries);
    for (int x = 0; x < queries; x++)
    {
        scanf ("%d", &temp);
        printf ("%d\n", dp [temp]);
    }
    return 0;
}

