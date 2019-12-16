#include <bits/stdc++.h>
using namespace std;
int n, num;
int arr [701];
int main ()
{
        scanf ("%d", &n);
        int s = 0;
        for (int x = 1; x <= n; x++)
        {
            scanf ("%d", &num);
            arr [x] = num;
            s += num;
        }
        int sum = (s % 2 != 0)?(s/2 + 1):(s/2);
        int dp1 [sum + 1];
        int dp2 [sum + 1];
        memset (dp1, 0, sizeof (dp1));
        memset (dp2, 0, sizeof (dp2));
        int* pt1 = dp1;
        int* pt2 = dp2;
        for (int x = 1; x <= n; x++)
        {
            for (int y = 1; y <= sum; y++)
            {
                if (y - arr [x] >= 0)
                {
                    if (pt1 [y - arr[x]] + arr [x] <= sum)
                    {
                        pt2 [y] = max (pt1 [y], pt1 [y - arr[x]] + arr [x]);
                    }
                }
                pt2 [y] = max (pt2 [y], pt1 [y]);
            }
            int* temp = pt1;
            pt1 = pt2;
            pt2 = temp;
            for (int y = 0; y <= sum; y++)
            {
                pt2 [y] = 0;
            }
        }
        printf("%d\n", abs(s - 2*pt1 [sum]));
    
    return 0;
}
