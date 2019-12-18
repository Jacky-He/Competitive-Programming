#include <bits/stdc++.h>
using namespace std;
bool sieve [201];
int num;
bool prime (int n)
{
    return !sieve [n];
}
void init ()
{
    sieve [0] = sieve [1] = true;
    for (int x = 2; x < 201; x++)
    {
        if (prime (x))
        {
            for (int y = x*2; y < 201; y += x)
            {
                sieve [y] = true;
            }
        }
    }
}
int r (int n)
{
    int cnt = 0;
    int x = n;
    while (cnt < 2)
    {
        x++;
        if (prime (x))
        {
            cnt++;
        }
    }
    int n1 = x;
    x = n;
    cnt = 0;
    while (cnt < 2 && x > 2)
    {
        x--;
        if (prime (x))
        {
            cnt++;
        }
    }
    int n2 = x;
    if (cnt < 2)
    {
        return n1;
    }
    if (abs (n - n1) == abs (n - n2))
    {

        return n1;
    }
    if (abs (n - n1) > abs (n - n2))
    {
        return n2;
    }
    return n1;
}
int main ()
{
    init ();
    for (int x = 0; x < 5; x++)
    {
        scanf ("%d", &num);
        printf ("%d\n", r (num));
    }
    return 0;
}