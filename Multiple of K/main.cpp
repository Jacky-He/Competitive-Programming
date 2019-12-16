#include <bits/stdc++.h>
using namespace std;
int n, k, num;
int psa [1000006];
int numbers [1000006];
int main ()
{
    scanf ("%d%d", &n, &k);
    memset (numbers, -1, sizeof (numbers));
    int result = -1;
    numbers [0] = 0;
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &num);
        psa [x] = (psa [x - 1] + num)%k;
        if (numbers [psa [x]] == -1)
        {
            numbers [psa [x]] = x;
        }
        else
        {
            result = max (result, x - numbers [psa [x]]);
        }
    }
    printf ("%d\n", result);
}
