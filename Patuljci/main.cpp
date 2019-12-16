#include <bits/stdc++.h>
using namespace std;
int arr [9];
int sum = 0;
int main ()
{
    for (int x = 0; x < 9; x++)
    {
        scanf ("%d", &arr [x]);
        sum += arr [x];
    }
    for (int x = 0; x < 9; x++)
    {
        for (int y = x + 1; y < 9; y++)
        {
            if (sum - arr [x] - arr [y] == 100)
            {
                for (int z = 0; z < 9; z++)
                {
                    if (z != x && z != y)
                    {
                        printf ("%d\n", arr [z]);
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}
