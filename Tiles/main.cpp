#include <bits/stdc++.h>
using namespace std;
int n, m, w;
int main ()
{
    scanf ("%d%d%d", &n, &m, &w);
    if (n >= w && m >= w)
    {
        printf ("%d\n", (n/w)*(m/w));
    }
    else
    {
        printf ("%d\n", 0);
    }
    return 0;
}
