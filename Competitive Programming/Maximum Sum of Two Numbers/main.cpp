#include <bits/stdc++.h>
using namespace std;
int arr [100001];
int n, m;
int bsearch (int a, int index)
{
    int lo = index + 1; int hi = n - 1;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi)/2;
        if (arr[mid] + a > m)
        {
            hi = mid;
        }
        else if (arr[mid] + a == m)
        {
            return m;
        }
        else
        {
            lo = mid;
        }
    }
    if (arr[hi] + a <= m)
    {
        return arr[hi] + a;
    }
    if (arr[lo] + a <= m)
    {
        return arr[lo] + a;
    }
    return -1;
}
int main ()
{
    scanf ("%d%d", &n, &m);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &arr [x]);
    }
    sort (arr, arr + n);
    int max = 0;
    for (int x = 0; x < n; x++)
    {
        int temp = bsearch (arr [x], x);
        if (temp > max)
        {
            max = temp;
        }
        if (max == m)
        {
            break;
        }
    }
    printf ("%d\n", max);
    return 0;
}
