#include <bits/stdc++.h>
using namespace std;
int parking [101];
int main ()
{
    int a, b, c;
    int i, j;
    scanf ("%d%d%d", &a, &b, &c);
    for (int x = 0; x < 3; x++)
    {
        scanf ("%d%d", &i, &j);
        for (int index = i + 1; index <= j; index++)
        {
            parking [index]++;
        }
    }
    int sum = 0;
    for (int x = 0; x < 101; x++)
    {
        if (parking [x] == 1)
        {
            sum += a;
        }
        else if (parking [x] == 2)
        {
            sum += (b*2);
        }
        else if (parking [x] == 3)
        {
            sum += (c*3);
        }
    }
    printf ("%d\n", sum);
    return 0;
}
