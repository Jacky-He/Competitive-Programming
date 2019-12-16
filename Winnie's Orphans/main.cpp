#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int num;
int main ()
{
    scanf ("%d%d", &n, &m);
    pair <int, int> mini = {INF, 0};
    
    for (int x = 0; x < n; x++)
    {
        int ex = 0;
        for (int y = 0; y < m; y++)
        {
            scanf ("%d", &num);
            if (num == 1 || num == 10)
            {
                ex++;
            }
        }
        if (ex < mini.first)
        {
            mini = {ex, x + 1};
        }
    }
    printf ("%d\n", mini.second);
    return 0;
}
