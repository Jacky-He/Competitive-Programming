#include <bits/stdc++.h>
using namespace std;
int n, num;
int dp [34];
int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        int result = 0;
        for (int temp = num, cnt = 0; temp != 0; temp >>= 1, cnt++)
        {
            if (temp & 1)
            {
                result = max (result, dp [cnt] + 1);
            }
        }
        for (int temp = num, cnt = 0; temp != 0; temp >>= 1, cnt++)
        {
            if (temp & 1)
            {
                dp [cnt] = result;
            }
        }
    }
    int output = 0;
    for (int x = 0; x < 34; x++)
    {
        output = max (output, dp [x]);
    }
    printf ("%d\n", output);
    return 0;
}
