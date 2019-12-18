#include <bits/stdc++.h>
using namespace std;

int n, a, b, num;

int main ()
{
    scanf ("%d%d%d", &n, &a, &b);
    int cnt = 0;
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        cnt += (a <= num && num <= b);
    }
    printf ("%d\n", cnt);
    return 0;
}
