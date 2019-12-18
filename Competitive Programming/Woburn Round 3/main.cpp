#include <bits/stdc++.h>
using namespace std;
unordered_set <int> sieve [10000001];
int divisible [10000001];
int A, B, C, D;
bool prime (int n)
{
    return sieve [n].empty();
}
void init ()
{
    for (int x = 2; x < 10000001; x++)
    {
        if (sieve [x].empty())
        {
            for (int i = x*2; i < 10000001; i += x)
            {
                sieve [i].insert(x);
            }
        }
    }
}
int main ()
{
    scanf ("%d%d%d%d", &A, &B, &C, &D);
    init();
    for (int x = C; x <= D; x++)
    {
        for (int each: sieve [x])
        {
            divisible [each]++;
        }
    }
    return 0;
}