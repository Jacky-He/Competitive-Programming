#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int n, d;
int a, b;
bool cmp (int n1, int n2)
{
    return n1 > n2;
}
int main ()
{
    scanf ("%d%d", &n, &d);
    int arr [n];
    int temp [n];
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &arr [x]);
    }
    for (int x = 0; x <= d; x++)
    {
        ll total = 0;
        for (int y = 0; y < n; y++)
        {
            temp [y] = arr [y];
            total += temp [y];
        }
        sort (temp, temp + n, cmp);
        ll sum = 0;
        int count = 0;
        for (int y = 0; y < n; y++)
        {
            sum += temp [y];
            count++;
            if (sum > double(total)/2)
            {
                break;
            }
        }
        printf ("%d\n", count);
        if (x < d)
        {
            scanf ("%d%d", &a, &b);
            arr [a-1] = b;
        }
    }
    return 0;
}
