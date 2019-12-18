#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b, c, d;
bool diff [10004][10004]; //black: 0, white: 1

int main ()
{
    scanf ("%d%d", &n, &m);

    for (int x = 0; x < m; x++)
    {
        scanf ("%d%d%d%d", &a, &b, &c, &d);
        a++;
        b++;
        diff [a][b] = !diff [a][b];
        diff [a + c][b] = !diff [a + c][b];
        diff [a][b + d] = !diff [a][b + d];
        diff [a + c][b + d] = !diff [a + c][b + d];
    }
    int cnt = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            diff [x][y] ^= diff [x][y - 1] ^ diff [x - 1][y] ^ diff [x - 1][y - 1];
            cnt += diff [x][y];
        }
    }
    
    printf ("%d\n", cnt);
    return 0;
}

