#include <bits/stdc++.h>
using namespace std;
bool semiprime [2001];
bool sieve [1002];
int num;
bool prime (int n)
{
    return !sieve [n];
}
void init ()
{
    sieve [0] = true;
    sieve [1] = true;
    for (int x = 2; x < 1001; x++)
    {
        if (prime (x))
        {
            for (int y = x*2; y < 1001; y += x)
            {
                sieve [y] = true;
            }
        }
    }
    for (int x = 2; x < 1001; x++)
    {
        for (int y = 2; y < 1001; y++)
        {
            if (prime (x) && prime (y) && x*y <= 1001)
            {
                semiprime [x*y] = true;
            }
        }
    }
}

int main ()
{
    init ();
    for (int x = 0; x < 5; x++)
    {
        scanf ("%d", &num);
        printf (semiprime [num]? "semiprime\n" : "not\n");
    }
    return 0;
}