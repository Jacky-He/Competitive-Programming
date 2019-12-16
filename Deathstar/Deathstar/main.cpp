#include <bits/stdc++.h>
using namespace std;
int n, num;
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        int result = 0;
        for (int y = 0; y < n; y++)
        {
            scanf ("%d", &num);
            result |= num;
        }
        printf ("%d ", result);
    }
    printf ("\n");
    return 0;
}
