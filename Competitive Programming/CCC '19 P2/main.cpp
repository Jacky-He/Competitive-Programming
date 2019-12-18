#include <bits/stdc++.h>
using namespace std;
int sieve [2000001];
int testcases, num;

bool prime (int n)
{
    return !sieve [n];
}
void init ()
{
    sieve [0] = sieve [1] = true;
    for (int x = 2; x < 2000001; x++)
    {
        if (prime (x))
        {
            for (int i = x*2; i < 2000001; i += x)
            {
                sieve [i] = true;
            }
        }
    }
}

int main ()
{
    init();
    scanf ("%d", &testcases);
    while (testcases--)
    {
        scanf ("%d", &num);
        int i = num;
        int j = num;
        while (!(prime(i) && prime (j)))
        {
            i--;
            j++;
        }
        printf ("%d %d\n", i, j);
    }
    return 0;
}