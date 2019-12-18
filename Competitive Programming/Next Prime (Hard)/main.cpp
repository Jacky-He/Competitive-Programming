#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
typedef unsigned long long int ull;
ull input;
bool isPrime (ull something)
{
    if (something <= 3)
    {
        return something > 1;
    }
    if (something % 2 == 0 || something % 3 == 0 || something % 5 == 0)
    {
        return false;
    }
    for (ull x = 7; x*x <= something; x+= 6)
    {
        if (something % x == 0 || something % (x + 4) == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    scanf ("%lld", &input);
    while (!isPrime (input))
    {
        input++;
    }
    printf ("%lld\n", input);
    return 0;
}
