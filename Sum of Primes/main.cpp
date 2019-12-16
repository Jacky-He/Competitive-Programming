#include <bits/stdc++.h>
using namespace std;
bool notprime [100001];
int main ()
{
    int n;
    for (int x = 0; x < 5; x++)
    {
        scanf ("%d", &n);
        int sum = 0;
        for (int i = 2; i <= n; i++)
        {
            if (!notprime [i])
            {
                sum += i;
                int multiplier = 2;
                while (i*multiplier <= n)
                {
                    notprime [i*multiplier] = true;
                    multiplier++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
