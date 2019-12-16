#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main ()
{
    int n;
    int counter = 0;
    scanf ("%d", &n);
    ull num;
    while (n > 0)
    {
        counter = 0;
        scanf ("%llu", &num);
        while (num != 0)
        {
            if (num % 2 == 0)
            {
                num >>= 1;
            }
            else if (num % 4 == 1 || num == 3)
            {
                num -= 1;
            }
            else
            {
                num += 1;
            }
            counter++;
        }
        printf ("%d\n", counter);
        n--;
    }
    return 0;
}
