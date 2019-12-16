#include <bits/stdc++.h>
using namespace std;

int d, h, m;

int main ()
{
    int start = 11*24*60 + 11*60 + 11;
    scanf ("%d%d%d", &d, &h, &m);
    int end = d*24*60 + h*60 + m;
    if (end < start)
    {
        printf ("%d\n", -1);
        return 0;
    }
    int interval = end - start;
    printf ("%d\n", interval);
    return 0;
}
