#include <bits/stdc++.h>
using namespace std;
int temp;

int main ()
{
    scanf ("%d", &temp);
    while (temp != 0)
    {
        int numNotWork = 0;
        int x = 1;
        while (sqrt(2*double(x)*x) <= temp)
        {
            x++;
        }
        while (x <= temp)
        {
            int i = x;
            while (sqrt(double(x)*x + double(i)*i) > temp)
            {
                numNotWork += 2;
                i--;
            }
            numNotWork--;
            x++;
        }
        int num = (x)*(x) - numNotWork;
        printf ("%d\n", num*4 - (temp + 1)*4 + 1);
        scanf ("%d", &temp);
    }
    return 0;
}
