#include <bits/stdc++.h>
using namespace std;
int n;
int main ()
{
    scanf ("%d", &n);
    int arr [n];
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &arr [x]);
    }
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr [i] > arr [j])
            {
                counter++;
            }
        }
    }
    printf ("%d\n", counter);
    return 0;
}
