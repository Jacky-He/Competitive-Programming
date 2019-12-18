#include <bits/stdc++.h>
using namespace std;
int dp [100005];
int numbers [100005];
int n, num;
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        numbers [num]++;
    }
    dp [1] = numbers [1];
    for (int x = 2; x < 100005; x++)
    {
        dp [x] = max (dp [x], dp [x - 1], dp [x - 2] + x*numbers [x]);
    }
    printf ("%d\n", dp [100004]);
    return 0;
}
