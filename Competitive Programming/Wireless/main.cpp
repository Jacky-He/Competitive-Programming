#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long int ll;

int m, n, k, X, Y, r, b;
int diff [1004][30004];
int getX (ll y, ll r, pair <ll, ll> center)
{
    ll temp = (y - center.second)*(y - center.second);
    return (int)(sqrtl(r*r - temp) + center.first);
}

void print ()
{
    for (int x = m; x > 0; x--)
    {
        for (int y = 1; y <= n; y++)
        {
            cout << diff [y][x] << " ";
        }
        cout << endl;
    }
}
int main ()
{
    scanf ("%d%d%d", &m, &n, &k);
    for (int x = 0; x < k; x++)
    {
        scanf ("%d%d%d%d", &X, &Y, &r, &b);
        for (int i = Y; i <= Y + r; i++)
        {
            int xval = getX (i, r, {X, Y});
            int lowerx = X - (xval - X) - 1;
            int lowery = Y - (i - Y);
            if (1 <= i && i <= m)
            {
                diff [min (xval, n)][i] += b;
                diff [max (0, lowerx)][i] -= b;
            }
            if (1 <= lowery && lowery <= m && i != Y)
            {
                diff [min(xval, n)][lowery] += b;
                diff [max(0, lowerx)][lowery] -= b;
            }
        }
    }
    
    int maxi = 0;
    int cnt = 0;
    for (int x = n; x > 0; x--)
    {
        for (int y = m; y > 0; y--)
        {
            diff [x][y] += diff [x + 1][y];
            if (diff [x][y] > maxi)
            {
                maxi = diff [x][y];
                cnt = 1;
            }
            else if (diff [x][y] == maxi)
            {
                cnt++;
            }
        }
    }
    printf ("%d\n%d\n", maxi, cnt);
    return 0;
}

/*

3
5
3
1 3 2 5
3 1 2 7
5 1 1 5



*/
