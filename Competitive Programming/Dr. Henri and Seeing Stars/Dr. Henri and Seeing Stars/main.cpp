#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int R, X, Y;
int x, y, m;
int brm;
int brx, bry;
int main ()
{
    scanf ("%d%d%d", &R, &X, &Y);
    brm = INF;
    for (int i = 0; i < 3; i++)
    {
        scanf ("%d%d%d", &x, &y, &m);
        if (m < brm)
        {
            brm = m;
            brx = x;
            bry = y;
        }
    }
    double dx = brx - X;
    double dy = bry - Y;
    if (sqrt(dx*dx + dy*dy) < R)
    {
        printf ("What a beauty!\n");
    }
    else
    {
        printf ("Time to move my telescope!\n");
    }
    return 0;
}
