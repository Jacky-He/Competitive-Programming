#include <bits/stdc++.h>
using namespace std;

int n;
int dp [401][401];
int arr [401];

int solve (int from, int to)
{
    if (dp [from][to] != -1)
    {
        return dp [from][to];
    }
    if (from > to)
    {
        return dp [from][to] = 0;
    }
    if (from == to)
    {
        return dp [from][to] = arr [from];
    }
    int i = from, j = to;
    while (i < j)
    {
        int left = solve (from, i);
        int middle = solve (i + 1, j - 1);
        int right = solve (j, to);
        if (i == j - 1)
        {
            if (left && right && left == right)
            {
                return dp [from][to] = left + right;
            }
        }
        else
        {
            if (left && middle && right && left == right)
            {
                return dp [from][to] = left + right + middle;
            }
        }
        if (!left)
        {
            i++;
        }
        else if (!right)
        {
            j--;
        }
        else if (left < right)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return dp [from][to] = 0;
}

int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < 401; x++)
    {
        memset (dp [x], -1, sizeof (dp [x]));
    }
    for (int x = 1; x <= n; x++)
    {
        scanf ("%d", &arr[x]);
    }
    int result = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            result = max (result, solve (x, y));
        }
    }
    printf ("%d\n", result);
    return 0;
}