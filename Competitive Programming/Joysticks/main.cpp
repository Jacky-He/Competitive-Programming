#include <bits/stdc++.h>
using namespace std;
int dp [300][300], a, b;

int solve (int n1, int n2)
{
    int& ret = dp [n1][n2];
    if (n1 == 0 || n2 == 0)
    {
        return ret = 0;
    }
    if (ret != 0)
    {
        return ret;
    }
    if (n1 - 2 >= 0)
    {
        ret = max (solve (n1 - 2, n2 + 1) + 1, ret);
    }
    if (n2 - 2 >= 0)
    {
        ret = max (solve (n1 + 1, n2 - 2) + 1, ret);
    }
    return ret;
}

int main()
{
    scanf ("%d%d", &a, &b);
    printf ("%d\n", solve (a, b));
    return 0;
}