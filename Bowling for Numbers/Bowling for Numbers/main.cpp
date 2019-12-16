#include <bits/stdc++.h>
using namespace std;
int psa [300001];
int main ()
{
    int numTestCases, pins, balls, width, pin;
    scanf ("%d", &numTestCases);
    for (int x = 0; x < numTestCases; x++)
    {
        scanf ("%d%d%d", &pins, &balls, &width);
        int dp [pins + 1][balls + 1];
        for (int i = 0; i <= pins; i++)
        {
            memset (dp [i], 0, sizeof (dp [0]));
        }
        for (int y = 1; y <= pins; y++)
        {
            scanf ("%d", &pin);
            psa [y] = psa [y - 1] + pin;
        }
        for (int p = 1; p <= pins; p++)
        {
            for (int b = 1; b <= balls; b++)
            {
                int additional = 0;
                if (p - width < 0)
                {
                    dp [p][b] = psa [p];
                }
                else
                {
                    additional = psa [p] - psa [p - width];
                    dp [p][b] = max (dp [p - width][b - 1] + additional, dp [p - 1][b]);
                }
            }
        }
        printf ("%d\n", dp [pins][balls]);
    }
    return 0;
}
