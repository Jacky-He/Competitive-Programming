#include <bits/stdc++.h>
using namespace std;
int testcase, a, b, c;
bool test (int a, int b, int c)
{
    if (c % (a + b) == 0 && c / (a + b) == 0)
    {
        if (c / (a + b) == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int amounta = 0;
    while (amounta <= c)
    {
        if ((c - amounta)%b == 0)
        {
            return true;
        }
        amounta += a;
    }
    return false;
}
int main ()
{
    scanf ("%d", &testcase);
    for (int x = 0; x < testcase; x++)
    {
        scanf ("%d%d%d", &a, &b, &c);
        if ((c % a == 0 && c /a > 0) || (c % b == 0 && c / b > 0) || (c % (a + b) == 0 && c / (a + b) > 0) || test (a, b, c))
        {
            printf ("YES\n");
        }
        else
        {
            printf ("NO\n");
        }
    }
    return 0;
}
