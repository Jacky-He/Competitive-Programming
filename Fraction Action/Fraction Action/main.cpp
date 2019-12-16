#include <bits/stdc++.h>
using namespace std;
int a, b;
int gcf (int a, int b) {return b == 0? a: gcf (b, a%b);}
int main ()
{
    scanf ("%d%d", &a, &b);
    int quotient = a/b;
    int remainder = a%b;
    if (remainder != 0)
    {
        if (quotient != 0)
        {
            printf ("%d", quotient);
        }
        int gcd = gcf (remainder, b);
        printf (" %d/%d\n", remainder/gcd, b/gcd);
    }
    else
    {
        printf ("%d", quotient);
        printf ("\n");
    }
    return 0;
}
