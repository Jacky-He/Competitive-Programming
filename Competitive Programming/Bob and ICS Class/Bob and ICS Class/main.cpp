#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int a1, b1, c1, a2, b2, c2;
    scanf ("%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2);
    if ((int)sqrt(a1) == (int)sqrt(a2) && (int)sqrt(b1)== (int)sqrt(b2) && (int)sqrt(c1)== (int)sqrt(c2))
    {
        printf ("Dull\n");
    }
    else
    {
        printf ("Colourful\n");
    }
    return 0;
}
