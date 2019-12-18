#include <bits/stdc++.h>
using namespace std;
bool prime (int num)
{
    if (num == 1)
    {
        return false;
    }

    for (int x = 2; x <= sqrt(num); x ++)
    {
        if (num%x == 0)
        {
            return false;
        }
    }
    return true;
}
bool also (int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += num%10;
        num /= 10;
    }
    return prime (sum);
}
int main ()
{
    int n;
    scanf ("%d", &n);
    int primes = 0;
    while (n--)
    {
        int num;
        scanf ("%d", &num);
        if (prime (num) && also (num))
        {
            primes++;
        }
    }
    printf ("%d", primes);
    return 0;
}
