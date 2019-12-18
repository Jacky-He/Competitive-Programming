#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int a, b;
    scanf ("%d%d", &a, &b);
    printf ("Sun Mon Tue Wed Thr Fri Sat\n");
    int index = 1;
    while (index < a)
    {
        printf ("    ");
        index++;
    }
    for (int num = 1; num <= b; num++)
    {
        printf ("%3d", num);
        if (index == 7 || num == b)
        {
            index = 1;
            printf ("\n");
        }
        else
        {
            index++;
            printf (" ");
        }
    }
    return 0;
}
