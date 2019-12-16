#include <bits/stdc++.h>
typedef unsigned long long int ull;
using namespace std;
vector <ull> levels [100001];
ull sumDigits (ull num)
{
    ull sum = 0;
    while (num != 0)
    {
        sum += num%10;
        num /= 10;
    }
    return sum;
}
int main ()
{
    ull num;
    scanf ("%lld", &num);
    ull counter = 0;
    levels [0].push_back (num);
    int index = 0;
    while (true)
    {
        for (ull each: levels [index])
        {
            if (each == 1)
            {
                printf ("%d", index);
                return 0;
            }
            levels [index + 1].push_back (each/sumDigits (each));
            levels [index+1].push_back (each - 1);
        }
        index++;
    }
    return 0;
}
