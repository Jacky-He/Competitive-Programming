#include <bits/stdc++.h>
using namespace std;
int n;
int main ()
{
    scanf ("%d", &n);
    int arr [n];
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &arr[x]);
    }
    if (n == 1)
    {
        printf (".%2f ", double(arr[0]));
        printf ("%.2f\n", double(arr[0]));
    }
    else if (n == 2)
    {
        printf ("%.2f ", double(arr[0] + arr[1])/2);
        printf ("%.2f\n", double(arr[0] + arr[1])/2);
    }
    else
    {
        sort (arr, arr + n);
        //small:
        double small = double(arr [1]);
        if ((n - 1)%2 == 0)
        {
            double temp = double(arr[(1 + n - 1)/2] + arr [(1 + n - 1)/2 + 1])/2;
            temp = (temp + arr[0])/2;
            small = min (small, temp);
        }
        else
        {
            double temp = double (arr[(1 + n - 1)/2]);
            temp = (temp + arr[0])/2;
            small = min (small, temp);
        }
        //big:
        double big = double (arr[n - 2]);
        if ((n - 1)%2 == 0)
        {
            double temp = double (arr [(n - 2)/2] + arr [(n - 2)/2 + 1])/2;
            temp = (temp + arr[n-1])/2;
            big = max (big, temp);
        }
        else
        {
            double temp = double (arr [(n - 2)/2]);
            temp = (temp + arr[n-1])/2;
            big = max (big, temp);
        }
        printf ("%.2f ", small);
        printf ("%.2f\n", big);
    }
    return 0;
}
