#include <bits/stdc++.h>
using namespace std;
int h1, w1, h2, w2;
int main ()
{
    scanf ("%d%d%d%d", &h1, &w1, &h2, &w2);
    if ((h1 - 1)*w2 < (h2 - 1)*w1)
    {
        printf ("%d\n", 2);
    }
    else if ((h1 - 1)*w2 > (h2 - 1)*w1)
    {
        printf ("%d\n", 1);
    }
    else
    {
        printf ("%d\n", -1);
    }
    return 0;
}
