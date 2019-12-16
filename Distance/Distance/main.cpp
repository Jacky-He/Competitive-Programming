#include <bits/stdc++.h>
using namespace std;
int n;
int main ()
{
    scanf ("%d", &n);
    int distance = n - 1;
    int curr = 1;
    bool yay = true;
    printf ("%d ", curr);
    while (distance >= 1)
    {
        if (yay)
        {
            curr += distance;
        }
        else
        {
            curr -= distance;
        }
        printf ("%d ", curr);
        yay = !yay;
        distance--;
    }
    return 0;
}
