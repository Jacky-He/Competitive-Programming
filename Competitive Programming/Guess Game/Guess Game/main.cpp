#include <bits/stdc++.h>
using namespace std;
int rounds, target, lo, high;
int main ()
{
    scanf ("%d%d%d", &target, &lo, &high);
    while (lo + 1 < high)
    {
        rounds++;
        int mid = (lo + high)/2;
        if (mid == target)
        {
            printf ("%d\n", rounds);
            return 0;
        }
        else if (mid < target)
        {
            lo = mid;
        }
        else
        {
            high = mid;
        }
    }
    if (lo == target)
    {
        printf ("%d\n", rounds + 1);
    }
    else if (high == target)
    {
        printf ("%d\n", rounds + 2);
    }
    return 0;
}
