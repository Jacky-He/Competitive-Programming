#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    scanf ("%d", &n);
    int sum = 0;
    int multiplier = 1;
    for (int x = 0; x <= n; x++)
    {
        sum += multiplier*x;
        multiplier++;
    }
    for (int x = n + 1, j = 0; j <= n; x--, j++)
    {
        sum += x*j;
    }
    cout << sum << endl;
    return 0;
}
