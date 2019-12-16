#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main ()
{
    scanf ("%d%d%d", &a, &b, &c);
    printf ("%d\n", a*c <= b? c : b/a);
    return 0;
}
