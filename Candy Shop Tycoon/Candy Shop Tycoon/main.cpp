#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int C;
int total = 0;
bool solve (int n1, int n2, int n3, int index)
{
    if (index == 1)
    {
        for (int x = 0; x <= 100; x++)
        {
            if (solve (x, n2, n3, 2))
            {
                return true;
            }
        }
        return false;
    }
    if (index == 2)
    {
        for (int x = 0; x <= 100; x++)
        {
            if (solve (n1, x, n3, 3))
            {
                return true;
            }
        }
        return false;
    }
    for (int x = 0; x <= 100; x++)
    {
        if (n1*a + n2*b + c*x == C)
        {
            return true;
        }
    }
    return false;
}
int main ()
{
    scanf ("%d%d%d", &a, &b, &c);
    scanf ("%d", &C);
    printf (solve (0, 0, 0, 1)? "QUEST CLEARED\n" : "TRY AGAIN\n");
    return 0;
}
