#include <stdio.h>
using namespace std;
int n;
int nn [10]; //maxmaxn
bool distinct (int num)
{
    while (num != 0)
    {
        int check = num%10;
        nn[check]++;
        if (nn[check] >= 2)
        {
            return false;
        }
        num /= 10;
    }
    return true;
}
int main ()
{
    scanf ("%d", &n);
    bool cont = true;
    n++;
    while (cont)
    {
        for (int x = 0; x < 10; x++)
        {
            nn [x] = 0;
        }
        if (distinct (n))
        {
            cont = false;
        }
        n++;
    }
    printf ("%d\n", n-1);
    return 0;
}