#include <bits/stdc++.h>
using namespace std;
int n, a, R;
int main ()
{
    scanf ("%d%d%d", &n, &a, &R);
    int max = R/a;
    if (max > n)
    {
        printf ("%d\n", n);
    }
    else
    {
        printf ("%d\n", max);
    }
    return 0;
}
