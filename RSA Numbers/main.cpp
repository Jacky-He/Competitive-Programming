#include <bits/stdc++.h>
using namespace std;
int a, b;

bool RSA (int num)
{
    int cnt = 0;
    int sr = (int)sqrt(num);
    for (int x = 1; x < sr; x++)
    {
        if (num%x == 0)
        {
            cnt += 2;
        }
        if (cnt > 4)
        {
            return false;
        }
    }
    if (sr*sr == num)
    {
        cnt++;
    }
    else if (num%sr == 0)
    {
        cnt += 2;
    }
    return cnt == 4;
}

int main ()
{
    scanf ("%d%d", &a, &b);
    int cnt = 0;
    for (int x = a; x <= b; x++)
    {
        cnt += RSA (x);
    }
    printf("The number of RSA numbers between %d and %d is %d\n", a, b, cnt);
    return 0;
}
