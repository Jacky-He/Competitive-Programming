#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    scanf ("%d%d", &n, &m);
    int arr [n];
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &arr[x]);
    }
    for (int x = 0; x < m; x++)
    {
        sort (arr, arr + n);
        printf ("%d\n", arr[0]);
        arr[0] ++;
    }
    return 0;
}
