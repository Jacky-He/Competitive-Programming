#include <bits/stdc++.h>
using namespace std;
int n;
int arr [1002];
int dp [1003][1003];
int solve (int left, int right)
{
    if (dp [left][right] != 0)
    {
        return dp [left][right];
    }
    if (right < left)
    {
        return 0;
    }
    if (left == right)
    {
        return dp [left][right] = arr [left];
    }
    int choice1 = (arr [left + 1] < arr [right]? solve (left + 1, right - 1) : solve (left + 2, right)) + arr [left];
    int choice2 = (arr [left] < arr [right - 1]? solve (left, right - 2): solve (left + 1, right - 1)) + arr [right];
    return dp [left][right] = max (choice1, choice2);
}
int main ()
{
    scanf ("%d", &n);
    int gamecnt = 1;
    while (n != 0)
    {
        int sum = 0;
        for (int x = 0; x < 1003; x++)
        {
            memset (dp [x], 0, sizeof (dp [x]));
        }
        for (int x = 1; x <= n; x++)
        {
            scanf ("%d", &arr [x]);
            sum += arr [x];
        }
        int temp = (2*solve (1, n) - sum);
        printf ("In game %d, the greedy strategy might lose by as many as %d points.\n", gamecnt, temp);
        scanf ("%d", &n);
        gamecnt++;
    }
    return 0;
}





