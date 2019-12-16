#include <bits/stdc++.h>
using namespace std;
int main ()
{
    string input;
    cin >> input;
    int dp [input.size() + 1];
    dp [0] = 0;
    memset (dp, 0, sizeof (dp));
    for (int x = 1; x <= (int) input.size (); x++)
    {
        if (input [x - 1] == 'G')
        {
            dp [x] = dp [x - 1] + 1;
        }
        else
        {
            dp [x] = dp [x - 1];
        }
    }
    int n, i, j;
    scanf ("%d", &n);
    while (n--)
    {
        scanf ("%d%d", &i, &j);
        printf ("%d\n", dp [j + 1] - dp [i]);
    }
    return 0;
}
