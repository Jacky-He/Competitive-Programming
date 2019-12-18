#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long int ll;
ll gcd (ll num1, ll num2)
{
    if (num1 == 0)
    {
        return num2;
    }
    return gcd (num2 % num1, num1);
}
ll maxPrime (ll number)
{
    ll max = -1;
    while (number % 2 == 0)
    {
        number >>= 1;
    }
    max = 2;
    for (ll divisor = 3; divisor <= sqrt (number); divisor += 2)
    {
        while (number % divisor == 0)
        {
            max = number;
            number /= divisor;
        }
    }
    if (number > 2)
    {
        max = number;
    }
    return max;
}
int main ()
{
    int N;
    cin >> N;
    ll num;
    ll GCD;
    cin >> GCD;
    for (int x = 1; x < N; x++)
    {
        cin >> num;
        GCD = gcd (GCD, num);
    }
    if (GCD == 1)
    {
        cout << "DNE" << endl;
    }
    else
    {
        cout << maxPrime (GCD) << endl;
    }
    return 0;
}
