#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, sum;
    scanf ("%d%d", &n, &sum);
    int denominations [n];
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &denominations [x]);
    }
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (denominations [i] <= sum && sum != 0)
        {
            sum -= denominations [i];
            count++;
        }
    }
    if (sum == 0)
    {
        printf ("%d", count);
    }
    else
    {
        printf ("%d", -1);
    }
    return 0;
}
