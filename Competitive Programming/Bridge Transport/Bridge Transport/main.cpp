#include <bits/stdc++.h>
using namespace std;
int n, cars, car;
int main ()
{
    scanf ("%d%d", &n, &cars);
    queue <int> Q;
    int totalweight = 0;
    bool broke = false;
    for (int x = 1; x <= cars; x++)
    {
        scanf ("%d", &car);
        if (Q.size() < 4)
        {
            totalweight += car;
            Q.push (car);
        }
        else if (Q.size() == 4)
        {
            totalweight -= Q.front();
            totalweight += car;
            Q.pop();
            Q.push (car);
        }
        if (totalweight > n)
        {
            printf ("%d\n", x - 1);
            broke = true;
            break;
        }
    }
    if (!broke)
    {
        printf ("%d\n", cars);
    }
    return 0;
}
