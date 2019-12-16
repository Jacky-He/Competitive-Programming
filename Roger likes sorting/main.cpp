#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int operation, l, r;
bool cmp (int num1, int num2)
{
    return num1 > num2;
}
int main ()
{
    scanf ("%d%d", &n, &m);
    int arr [n];
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &arr [x]);
    }
    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d", &operation, &l, &r);
        if (operation == 1)
        {
            sort (arr + l - 1, arr + r, cmp);
        }
        else if (operation == 0)
        {
            sort (arr + l - 1, arr + r);
        }
    }
    scanf ("%d", &q);
    printf ("%d\n", arr [q - 1]);
    return 0;
}
