#include <bits/stdc++.h>
using namespace std;
int np, na, sump;
int temp;
double average;
int n;
int main ()
{
    scanf ("%d", &np);
    for (int x = 0; x < np; x++)
    {
        scanf ("%d", &temp);
        sump += temp;
    }
    scanf ("%d", &na);
    for (int x = 0; x < na; x++)
    {
        scanf ("%d", &n);
        np++;
        sump += n;
        average = double(sump)/np;
        printf ("%.3f\n", average);
    }
    return 0;
}
